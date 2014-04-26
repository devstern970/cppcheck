/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2014 Daniel Marjamäki and Cppcheck team.
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



#include "mathlib.h"
#include "errorlogger.h"

#include <cmath>
#include <cctype>
#include <limits>

MathLib::biguint MathLib::toULongNumber(const std::string & str)
{
    // hexadecimal numbers:
    if (isHex(str)) {
        if (str[0] == '-') {
            biguint ret = 0;
            std::istringstream istr(str);
            istr >> std::hex >> ret;
            return ret;
        } else {
            unsigned long long ret = 0;
            std::istringstream istr(str);
            istr >> std::hex >> ret;
            return (biguint)ret;
        }
    }

    // octal numbers:
    if (isOct(str)) {
        biguint ret = 0;
        std::istringstream istr(str);
        istr >> std::oct >> ret;
        return ret;
    }

    // binary numbers:
    if (isBin(str)) {
        biguint ret = 0;
        for (std::string::size_type i = str[0] == '0'?2:3; i < str.length(); i++) {
            ret <<= 1;
            if (str[i] == '1')
                ret |= 1;
        }
        /* if (str[0] == '-')
                ret = -ret; */
        return ret;
    }

    if (isFloat(str)) {
        return static_cast<biguint>(std::atof(str.c_str()));
    }

    biguint ret = 0;
    std::istringstream istr(str);
    istr >> ret;
    return ret;
}

MathLib::bigint MathLib::toLongNumber(const std::string & str)
{
    // hexadecimal numbers:
    if (isHex(str)) {
        if (str[0] == '-') {
            bigint ret = 0;
            std::istringstream istr(str);
            istr >> std::hex >> ret;
            return ret;
        } else {
            unsigned long long ret = 0;
            std::istringstream istr(str);
            istr >> std::hex >> ret;
            return (bigint)ret;
        }
    }

    // octal numbers:
    if (isOct(str)) {
        bigint ret = 0;
        std::istringstream istr(str);
        istr >> std::oct >> ret;
        return ret;
    }

    // binary numbers:
    if (isBin(str)) {
        bigint ret = 0;
        for (std::string::size_type i = str[0] == '0'?2:3; i < str.length(); i++) {
            ret <<= 1;
            if (str[i] == '1')
                ret |= 1;
        }
        if (str[0] == '-')
            ret = -ret;
        return ret;
    }

    if (isFloat(str)) {
        return static_cast<bigint>(std::atof(str.c_str()));
    }

    bigint ret = 0;
    std::istringstream istr(str);
    istr >> ret;
    return ret;
}


double MathLib::toDoubleNumber(const std::string &str)
{
    if (isHex(str))
        return static_cast<double>(toLongNumber(str));
    // nullcheck
    else if (isNullValue(str))
        return 0.0;
    // otherwise, convert to double
    std::istringstream istr(str);
    double ret;
    istr >> ret;
    return ret;
}

template<> std::string MathLib::toString(double value)
{
    std::ostringstream result;
    result.precision(12);
    result << value;
    if (result.str() == "-0")
        return "0.0";
    if (result.str().find(".") == std::string::npos)
        return result.str() + ".0";
    return result.str();
}

bool MathLib::isFloat(const std::string &s)
{
    if (s.empty())
        return false;
    enum class State {
        START, BASE_PLUSMINUS, BASE_DIGITS1, LEADING_DECIMAL, TRAILING_DECIMAL, BASE_DIGITS2, E, MANTISSA_PLUSMINUS, MANTISSA_DIGITS, F
    } state = State::START;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        switch (state) {
        case State::START:
            if (*it=='+' || *it=='-')
                state=State::BASE_PLUSMINUS;
            else if (*it=='.')
                state=State::LEADING_DECIMAL;
            else if (std::isdigit(*it))
                state=State::BASE_DIGITS1;
            else
                return false;
            break;
        case State::BASE_PLUSMINUS:
            if (*it=='.')
                state=State::LEADING_DECIMAL;
            else if (std::isdigit(*it))
                state=State::BASE_DIGITS1;
            else if (*it=='e' || *it=='E')
                state=State::E;
            else
                return false;
            break;
        case State::LEADING_DECIMAL:
            if (std::isdigit(*it))
                state=State::BASE_DIGITS2;
            else if (*it=='e' || *it=='E')
                state=State::E;
            else
                return false;
            break;
        case State::BASE_DIGITS1:
            if (*it=='e' || *it=='E')
                state=State::E;
            else if (*it=='.')
                state=State::TRAILING_DECIMAL;
            else if (!std::isdigit(*it))
                return false;
            break;
        case State::TRAILING_DECIMAL:
            if (*it=='e' || *it=='E')
                state=State::E;
            else if (std::isdigit(*it))
                state=State::BASE_DIGITS2;
            else
                return false;
            break;
        case State::BASE_DIGITS2:
            if (*it=='e' || *it=='E')
                state=State::E;
            else if (*it=='f' || *it=='F')
                state=State::F;
            else if (!std::isdigit(*it))
                return false;
            break;
        case State::E:
            if (*it=='+' || *it=='-')
                state=State::MANTISSA_PLUSMINUS;
            else if (std::isdigit(*it))
                state=State::MANTISSA_DIGITS;
            else
                return false;
            break;
        case State::MANTISSA_PLUSMINUS:
            if (!std::isdigit(*it))
                return false;
            else
                state=State::MANTISSA_DIGITS;
            break;
        case State::MANTISSA_DIGITS:
            if (*it=='f' || *it=='F')
                state=State::F;
            else if (!std::isdigit(*it))
                return false;
            break;
        case State::F:
            return false;
        }
    }
    return (state==State::BASE_DIGITS2 || state==State::MANTISSA_DIGITS || state==State::TRAILING_DECIMAL || state==State::F);
}

bool MathLib::isNegative(const std::string &s)
{
    // remember position
    std::string::size_type n = 0;
    // eat up whitespace
    while (std::isspace(s[n])) ++n;
    // every negative number has a negative sign
    return (s[n] == '-');
}

bool MathLib::isPositive(const std::string &s)
{
    return !MathLib::isNegative(s);
}

/*! \brief Does the string represent an octal number?
 * In case leading or trailing white space is provided, the function
 * returns false.
 * Additional information can be found here:
 * http://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html
 *
 * \param[in] s The string to check. In case the string is empty, the function returns false.
 * \return Return true in case a octal number is provided and false otherwise.
 **/
bool MathLib::isOct(const std::string& s)
{
    enum class Status {
        START, PLUSMINUS, OCTAL_PREFIX, DIGITS
    } state = Status::START;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        switch (state) {
        case Status::START:
            if (*it == '+' || *it == '-')
                state = Status::PLUSMINUS;
            else if (*it == '0')
                state = Status::OCTAL_PREFIX;
            else
                return false;
            break;
        case Status::PLUSMINUS:
            if (*it == '0')
                state =Status:: OCTAL_PREFIX;
            else
                return false;
            break;
        case Status::OCTAL_PREFIX:
            if (isOctalDigit(*it))
                state = Status::DIGITS;
            else
                return false;
            break;
        case Status::DIGITS:
            if (isOctalDigit(*it))
                state = Status::DIGITS;
            else
                return isValidSuffix(it,s.end());
            break;
        }
    }
    return state == Status::DIGITS;
}

bool MathLib::isHex(const std::string& s)
{
    enum class Status {
        START, PLUSMINUS, HEX_PREFIX, DIGIT, DIGITS
    } state = Status::START;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        switch (state) {
        case Status::START:
            if (*it == '+' || *it == '-')
                state = Status::PLUSMINUS;
            else if (*it == '0')
                state = Status::HEX_PREFIX;
            else
                return false;
            break;
        case Status::PLUSMINUS:
            if (*it == '0')
                state = Status::HEX_PREFIX;
            else
                return false;
            break;
        case Status::HEX_PREFIX:
            if (*it == 'x' || *it == 'X')
                state = Status::DIGIT;
            else
                return false;
            break;
        case Status::DIGIT:
            if (isxdigit(*it))
                state = Status::DIGITS;
            else
                return false;
            break;
        case Status::DIGITS:
            if (isxdigit(*it))
                state = Status::DIGITS;
            else
                return isValidSuffix(it,s.end());
            break;
        }
    }
    return state == Status::DIGITS;
}

bool MathLib::isValidSuffix(std::string::const_iterator it, std::string::const_iterator end)
{
    enum class Status {
        START, SUFFIX_U, SUFFIX_UL, SUFFIX_ULL, SUFFIX_L, SUFFIX_LU, SUFFIX_LL, SUFFIX_LLU
    } state = Status::START;
    for (; it != end; ++it) {
        switch (state) {
        case Status::START:
            if (*it == 'u' || *it == 'U')
                state = Status::SUFFIX_U;
            else if (*it == 'l' || *it == 'L')
                state = Status::SUFFIX_L;
            else
                return false;
            break;
        case Status::SUFFIX_U:
            if (*it == 'l' || *it == 'L')
                state = Status::SUFFIX_UL; // UL
            else
                return false;
            break;
        case Status::SUFFIX_UL:
            if (*it == 'l' || *it == 'L')
                state = Status::SUFFIX_ULL; // ULL
            else
                return false;
            break;
        case Status::SUFFIX_L:
            if (*it == 'u' || *it == 'U')
                state = Status::SUFFIX_LU; // LU
            else if (*it == 'l' || *it == 'L')
                state = Status::SUFFIX_LL; // LL
            else
                return false;
            break;
        case Status::SUFFIX_LU:
            return false;
        case Status::SUFFIX_LL:
            if (*it == 'u' || *it == 'U')
                state = Status::SUFFIX_LLU; // LLU
            else
                return false;
            break;
        default:
            return false;
        }
    }
    return (state == Status::SUFFIX_U)  || (state == Status::SUFFIX_L)
           || (state == Status::SUFFIX_UL) || (state == Status::SUFFIX_LU)   || (state == Status::SUFFIX_LL)
           || (state == Status::SUFFIX_ULL) || (state == Status::SUFFIX_LLU);
}

/*! \brief Does the string represent a binary number?
 * In case leading or trailing white space is provided, the function
 * returns false.
 * Additional information can be found here:
 * http://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html
 *
 * \param[in] s The string to check. In case the string is empty, the function returns false.
 * \return Return true in case a binary number is provided and false otherwise.
 **/
bool MathLib::isBin(const std::string& s)
{
    enum class Status {
        START, PLUSMINUS, GNU_BIN_PREFIX, DIGIT, DIGITS
    } state = Status::START;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        switch (state) {
        case Status::START:
            if (*it == '+' || *it == '-')
                state = Status::PLUSMINUS;
            else if (*it == '0')
                state = Status::GNU_BIN_PREFIX;
            else
                return false;
            break;
        case Status::PLUSMINUS:
            if (*it == '0')
                state = Status::GNU_BIN_PREFIX;
            else
                return false;
            break;
        case Status::GNU_BIN_PREFIX:
            if (*it == 'b' || *it == 'B')
                state = Status::DIGIT;
            else
                return false;
            break;
        case Status::DIGIT:
            if (*it == '0' || *it == '1')
                state = Status::DIGITS;
            else
                return false;
            break;
        case Status::DIGITS:
            if (*it == '0' || *it == '1')
                state = Status::DIGITS;
            else
                return isValidSuffix(it,s.end());
            break;
        }
    }
    return state == Status::DIGITS;
}

bool MathLib::isDec(const std::string & s)
{
    enum class Status {
        START, PLUSMINUS, DIGIT, SUFFIX
    } state = Status::START;
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        switch (state) {
        case Status::START:
            if (*it == '+' || *it == '-')
                state = Status::PLUSMINUS;
            else if (isdigit(*it))
                state = Status::DIGIT;
            else
                return false;
            break;
        case Status::PLUSMINUS:
            if (isdigit(*it))
                state = Status::DIGIT;
            else
                return false;
            break;
        case Status::DIGIT:
            if (isdigit(*it))
                state = Status::DIGIT;
            else
                return isValidSuffix(it,s.end());
            break;
        case Status::SUFFIX:
            break;
        }
    }
    return state == Status::DIGIT;
}

bool MathLib::isInt(const std::string & s)
{
    return isDec(s) || isHex(s) || isOct(s);
}

std::string MathLib::add(const std::string & first, const std::string & second)
{
    if (MathLib::isInt(first) && MathLib::isInt(second)) {
        return toString(toLongNumber(first) + toLongNumber(second));
    }

    double d1 = toDoubleNumber(first);
    double d2 = toDoubleNumber(second);

    int count = 0;
    while (d1 > 100000.0 * d2 && toString(d1+d2)==first && ++count<5)
        d2 *= 10.0;
    while (d2 > 100000.0 * d1 && toString(d1+d2)==second && ++count<5)
        d1 *= 10.0;

    return toString(d1 + d2);
}

std::string MathLib::subtract(const std::string &first, const std::string &second)
{
    if (MathLib::isInt(first) && MathLib::isInt(second)) {
        return toString(toLongNumber(first) - toLongNumber(second));
    }

    if (first == second)
        return "0.0" ;

    double d1 = toDoubleNumber(first);
    double d2 = toDoubleNumber(second);

    int count = 0;
    while (d1 > 100000.0 * d2 && toString(d1-d2)==first && ++count<5)
        d2 *= 10.0;
    while (d2 > 100000.0 * d1 && toString(d1-d2)==second && ++count<5)
        d1 *= 10.0;

    return toString(d1 - d2);
}

std::string MathLib::divide(const std::string &first, const std::string &second)
{
    if (MathLib::isInt(first) && MathLib::isInt(second)) {
        const bigint a = toLongNumber(first);
        const bigint b = toLongNumber(second);
        if (a == std::numeric_limits<bigint>::min())
            throw InternalError(0, "Internal Error: Division overflow");
        if (b == 0)
            throw InternalError(0, "Internal Error: Division by zero");
        return toString(toLongNumber(first) / b);
    } else if (second == "0.0") {
        if (first=="0.0" || first=="+0.0")
            return "nan.0";
        if (first=="-0.0")
            return "-nan.0";
        return (first[0] == '-') ? "-inf.0" : "inf.0";
    }
    return toString(toDoubleNumber(first) / toDoubleNumber(second));
}

std::string MathLib::multiply(const std::string &first, const std::string &second)
{
    if (MathLib::isInt(first) && MathLib::isInt(second)) {
        return toString(toLongNumber(first) * toLongNumber(second));
    }
    return toString(toDoubleNumber(first) * toDoubleNumber(second));
}

std::string MathLib::mod(const std::string &first, const std::string &second)
{
    if (MathLib::isInt(first) && MathLib::isInt(second)) {
        bigint b = toLongNumber(second);
        if (b == 0)
            throw InternalError(0, "Internal Error: Division by zero");
        return toString(toLongNumber(first) % b);
    }
    return toString(std::fmod(toDoubleNumber(first),toDoubleNumber(second)));
}

std::string MathLib::calculate(const std::string &first, const std::string &second, char action)
{
    switch (action) {
    case '+':
        return MathLib::add(first, second);

    case '-':
        return MathLib::subtract(first, second);

    case '*':
        return MathLib::multiply(first, second);

    case '/':
        return MathLib::divide(first, second);

    case '%':
        return MathLib::mod(first, second);

    case '&':
        return MathLib::toString(MathLib::toLongNumber(first) & MathLib::toLongNumber(second));

    case '|':
        return MathLib::toString(MathLib::toLongNumber(first) | MathLib::toLongNumber(second));

    case '^':
        return MathLib::toString(MathLib::toLongNumber(first) ^ MathLib::toLongNumber(second));

    default:
        throw InternalError(0, std::string("Unexpected action '") + action + "' in MathLib::calculate(). Please report this to Cppcheck developers.");
    }
}

std::string MathLib::sin(const std::string &tok)
{
    return toString(std::sin(toDoubleNumber(tok)));
}


std::string MathLib::cos(const std::string &tok)
{
    return toString(std::cos(toDoubleNumber(tok)));
}

std::string MathLib::tan(const std::string &tok)
{
    return toString(std::tan(toDoubleNumber(tok)));
}


std::string MathLib::abs(const std::string &tok)
{
    return toString(std::abs(toDoubleNumber(tok)));
}

bool MathLib::isEqual(const std::string &first, const std::string &second)
{
    // this conversion is needed for formatting
    // e.g. if first=0.1 and second=1.0E-1, the direct comparison of the strings would fail
    return toString(toDoubleNumber(first)) == toString(toDoubleNumber(second));
}

bool MathLib::isNotEqual(const std::string &first, const std::string &second)
{
    return !isEqual(first, second);
}

bool MathLib::isGreater(const std::string &first, const std::string &second)
{
    return toDoubleNumber(first) > toDoubleNumber(second);
}

bool MathLib::isGreaterEqual(const std::string &first, const std::string &second)
{
    return toDoubleNumber(first) >= toDoubleNumber(second);
}

bool MathLib::isLess(const std::string &first, const std::string &second)
{
    return toDoubleNumber(first) < toDoubleNumber(second);
}

bool MathLib::isLessEqual(const std::string &first, const std::string &second)
{
    return toDoubleNumber(first) <= toDoubleNumber(second);
}

/*! \brief Does the string represent the numerical value of 0?
 * In case leading or trailing white space is provided, the function
 * returns false.
 * Requirement for this function:
 * - This code is allowed to be slow because of simplicity of the code.
 *
 * \param[in] str The string to check. In case the string is empty, the function returns false.
 * \return Return true in case the string represents a numerical null value.
 **/
bool MathLib::isNullValue(const std::string &str)
{
    if (str.empty() || (!std::isdigit(static_cast<unsigned char>(str[0])) && (str.size() < 1 || (str[0] != '.' && str[0] != '-' && str[0] != '+'))))
        return false; // Has to be a number

    for (size_t i = 0; i < str.size(); i++) {
        if (std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '0') // May not contain digits other than 0
            return false;
        if (str[i] == 'E' || str[i] == 'e')
            return true;
    }
    return true;
}

bool MathLib::isOctalDigit(char c)
{
    return (c >= '0' && c <= '7');
}
