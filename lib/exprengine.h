/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2019 Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//---------------------------------------------------------------------------
#ifndef exprengineH
#define exprengineH
//---------------------------------------------------------------------------

#include "config.h"

#include <functional>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <stdint.h>

class ErrorLogger;
class Tokenizer;
class Scope;
class Settings;
class Token;

#ifdef __GNUC__
typedef __int128_t   int128_t;
#else
typedef long long    int128_t;
#ifdef _MSC_VER
#pragma message(__FILE__ "(" _CRT_STRINGIZE(__LINE__) ")" ": warning: TODO No 128-bit integer type is available => Limited analysis of large integers...")
#else
#warning TODO No 128-bit integer type is available => Limited analysis of large integers
#endif
#endif

namespace ExprEngine {
    std::string str(int128_t);

    // TODO we need to handle floats, containers, pointers, aliases and structs and stuff
    enum class ValueType {
        UninitValue,
        IntRange,
        FloatRange,
        PointerValue,
        ArrayValue,
        StringLiteralValue,
        StructValue,
        AddressOfValue,
        BinOpResult,
        IntegerTruncation
    };

    class Value;
    typedef std::shared_ptr<Value> ValuePtr;

    class Value {
    public:
        Value(const std::string &name) : name(name) {}
        virtual ~Value() {}
        virtual ValueType type() const = 0;
        virtual std::string getRange() const = 0;
        virtual bool isIntValueInRange(int value) const {
            (void)value;
            return false;
        }
        const std::string name;
    };

    class UninitValue: public Value {
    public:
        UninitValue() : Value("?") {}
        ValueType type() const override {
            return ValueType::UninitValue;
        }
        std::string getRange() const override {
            return "?";
        }
    };

    class IntRange : public Value {
    public:
        IntRange(const std::string &name, int128_t minValue, int128_t maxValue)
            : Value(name)
            , minValue(minValue)
            , maxValue(maxValue) {
        }
        ~IntRange() OVERRIDE {}

        ValueType type() const override {
            return ValueType::IntRange;
        }
        std::string getRange() const override {
            if (minValue == maxValue)
                return str(minValue);
            return str(minValue) + ":" + str(maxValue);
        }
        bool isIntValueInRange(int value) const override {
            return value >= minValue && value <= maxValue;
        }

        int128_t minValue;
        int128_t maxValue;
    };

    class FloatRange : public Value {
    public:
        FloatRange(const std::string &name, long double minValue, long double maxValue)
            : Value(name)
            , minValue(minValue)
            , maxValue(maxValue) {
        }
        ~FloatRange() OVERRIDE {}

        ValueType type() const override {
            return ValueType::FloatRange;
        }
        std::string getRange() const override {
            return std::to_string(minValue) + ":" + std::to_string(maxValue);
        }

        long double minValue;
        long double maxValue;
    };

    class PointerValue: public Value {
    public:
        PointerValue(const std::string &name, ValuePtr data, bool null, bool uninitData)
            : Value(name)
            , data(data)
            , null(null)
            , uninitData(uninitData) {
        }
        ValueType type() const override {
            return ValueType::PointerValue;
        }
        std::string getRange() const override;
        ValuePtr data;
        bool null;
        bool uninitData;
    };

    class ArrayValue: public Value {
    public:
        const int MAXSIZE = 0x100000;

        ArrayValue(const std::string &name, int minSize, int maxSize)
            : Value(name)
            , minSize(minSize)
            , maxSize(maxSize) {
            if (minSize < 1)
                minSize = 1;
            // Known size..
            if (minSize == maxSize)
                data.resize((minSize < MAXSIZE) ? minSize : MAXSIZE,
                            std::make_shared<UninitValue>());
        }

        ValueType type() const override {
            return ValueType::ArrayValue;
        }
        std::string getRange() const override;

        void assign(ValuePtr index, ValuePtr value);
        void clear();
        ValuePtr read(ValuePtr index);

        std::vector<ValuePtr> data;
        int minSize;
        int maxSize;
    };

    class StringLiteralValue: public Value {
    public:
        StringLiteralValue(const std::string &name, const std::string &s)
            : Value(name)
            , string(s) {
        }

        ValueType type() const override {
            return ValueType::StringLiteralValue;
        }
        std::string getRange() const override {
            return "\"" + string + "\"";
        }

        int size() const {
            return string.size();
        }
        const std::string string;
    };

    class StructValue: public Value {
    public:
        explicit StructValue(const std::string &name) : Value(name) {}
        ValueType type() const override {
            return ValueType::StructValue;
        }
        std::string getRange() const override {
            return name;
        }
        ValuePtr getValueOfMember(const std::string &name) const {
            auto it = member.find(name);
            return (it == member.end()) ? ValuePtr() : it->second;
        }
        std::map<std::string, ValuePtr> member;
    };

    class AddressOfValue: public Value {
    public:
        AddressOfValue(const std::string &name, int varId)
            : Value(name)
            , varId(varId)
        {}

        ValueType type() const override {
            return ValueType::AddressOfValue;
        }
        std::string getRange() const override {
            return "(&@" + std::to_string(varId);
        }

        int varId;
    };

    class BinOpResult : public Value {
    public:
        BinOpResult(const std::string &binop, ValuePtr op1, ValuePtr op2)
            : Value("(" + op1->name + ")" + binop + "(" + op2->name + ")")
            , binop(binop)
            , op1(op1)
            , op2(op2) {
            auto b1 = std::dynamic_pointer_cast<BinOpResult>(op1);
            if (b1)
                mLeafs = b1->mLeafs;
            else
                mLeafs.insert(op1);

            auto b2 = std::dynamic_pointer_cast<BinOpResult>(op2);
            if (b2)
                mLeafs.insert(b2->mLeafs.begin(), b2->mLeafs.end());
            else
                mLeafs.insert(op2);
        }

        ValueType type() const override {
            return ValueType::BinOpResult;
        }
        std::string getRange() const override;

        struct IntOrFloatValue {
            void setIntValue(int128_t v) {
                type = INT;
                intValue = v;
                floatValue = 0;
            }
            void setFloatValue(long double v) {
                type = FLOAT;
                intValue = 0;
                floatValue = v;
            }
            enum {INT,FLOAT} type;
            bool isFloat() const {
                return type == FLOAT;
            }
            int128_t intValue;
            long double floatValue;
        };

        void getRange(IntOrFloatValue *minValue, IntOrFloatValue *maxValue) const;
        bool isIntValueInRange(int value) const override;

        std::string binop;
        ValuePtr op1;
        ValuePtr op2;
    private:

        IntOrFloatValue evaluate(int test, const std::map<ValuePtr, int> &valueBit) const;
        IntOrFloatValue evaluateOperand(int test, const std::map<ValuePtr, int> &valueBit, ValuePtr value) const;
        std::set<ValuePtr> mLeafs;
    };

    class IntegerTruncation : public Value {
    public:
        IntegerTruncation(const std::string &name, ValuePtr inputValue, int bits, char sign)
            : Value(name)
            , inputValue(inputValue)
            , bits(bits)
            , sign(sign) {
        }

        ValueType type() const override {
            return ValueType::IntegerTruncation;
        }
        std::string getRange() const override;

        ExprEngine::ValuePtr inputValue;
        int bits;
        char sign;
    };

    typedef std::function<void(const Token *, const ExprEngine::Value &)> Callback;

    /** Execute all functions */
    void CPPCHECKLIB executeAllFunctions(const Tokenizer *tokenizer, const Settings *settings, const std::vector<Callback> &callbacks);
    void executeFunction(const Scope *functionScope, const Tokenizer *tokenizer, const Settings *settings, const std::vector<Callback> &callbacks);

    void runChecks(ErrorLogger *errorLogger, const Tokenizer *tokenizer, const Settings *settings);
}
#endif // exprengineH
