/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2012 Daniel Marjamäki and Cppcheck team.
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
#ifndef checkleakautovarH
#define checkleakautovarH
//---------------------------------------------------------------------------

#include "config.h"
#include "check.h"


class CPPCHECKLIB VarInfo {
public:
    std::map<unsigned int, std::string> alloctype;
    std::map<unsigned int, std::string> possibleUsage;
    std::set<unsigned int> conditionalAlloc;

    void clear() {
        alloctype.clear();
        possibleUsage.clear();
        conditionalAlloc.clear();
    }

    void erase(unsigned int varid) {
        alloctype.erase(varid);
        possibleUsage.erase(varid);
        conditionalAlloc.erase(varid);
    }

    void swap(VarInfo &other) {
        alloctype.swap(other.alloctype);
        possibleUsage.swap(other.possibleUsage);
        conditionalAlloc.swap(other.conditionalAlloc);
    }

    /** set possible usage for all variables */
    void possibleUsageAll(const std::string &functionName);

    void print();
};


/// @addtogroup Checks
/// @{

/**
 * @brief Check for leaks
 */

class CPPCHECKLIB CheckLeakAutoVar : public Check {
public:
    /** This constructor is used when registering the CheckLeakAutoVar */
    CheckLeakAutoVar() : Check(myName()) {
    }

    /** This constructor is used when running checks. */
    CheckLeakAutoVar(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger)
        : Check(myName(), tokenizer, settings, errorLogger) {
    }

    /** @brief Run checks against the simplified token list */
    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger) {
        CheckLeakAutoVar checkLeakAutoVar(tokenizer, settings, errorLogger);
        checkLeakAutoVar.parseConfigurationFile("cppcheck.cfg");
        checkLeakAutoVar.check();
    }

private:

    std::map<std::string,std::string> cfgalloc;
    std::map<std::string,std::string> cfgdealloc;

    void parseConfigurationFile(const std::string &filename);

    /** check for leaks in all scopes */
    void check();

    /** check for leaks in a function scope */
    void checkScope(const Token * const startToken,
                    VarInfo *varInfo,
                    std::set<unsigned int> notzero);

    /** parse function call */
    void functionCall(const Token *tok, VarInfo *varInfo, const std::string &dealloc);

    /** return. either "return" or end of variable scope is seen */
    void ret(const Token *tok, const VarInfo &varInfo);

    /** if variable is allocated then there is a leak */
    void leakIfAllocated(const Token *vartok, const VarInfo &varInfo);

    void leakError(const Token* tok, const std::string &varname);
    void mismatchError(const Token* tok, const std::string &varname);
    void deallocUseError(const Token *tok, const std::string &varname);
    void doubleDeallocationError(const Token *tok, const std::string &varname);

    /** message: user configuration is needed to complete analysis */
    void configurationInfo(const Token* tok, const std::string &functionName);

    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) const {
        CheckLeakAutoVar c(0, settings, errorLogger);
        c.leakError(NULL, "p");
        c.mismatchError(NULL, "p");
        c.deallocUseError(NULL, "p");
        c.doubleDeallocationError(NULL, "p");
        c.configurationInfo(0, "f");  // user configuration is needed to complete analysis
    }

    std::string myName() const {
        return "Leaks in functions";
    }

    std::string classInfo() const {
        return "";
    }
};
/// @}
//---------------------------------------------------------------------------
#endif

