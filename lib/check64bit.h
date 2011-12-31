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
#ifndef check64bitH
#define check64bitH
//---------------------------------------------------------------------------

#include "check.h"


/// @addtogroup Checks
/// @{

/**
 * @brief Check for 64-bit portability issues
 */

class Check64BitPortability : public Check {
public:
    /** This constructor is used when registering the Check64BitPortability */
    Check64BitPortability() : Check(myName()) {
    }

    /** This constructor is used when running checks. */
    Check64BitPortability(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger)
        : Check(myName(), tokenizer, settings, errorLogger) {
    }

    /** @brief Run checks against the normal token list */
    void runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger) {
        Check64BitPortability check64BitPortability(tokenizer, settings, errorLogger);
        check64BitPortability.pointerassignment();
    }

    /** @brief Run checks against the simplified token list */
    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger) {
        (void)tokenizer;
        (void)settings;
        (void)errorLogger;
    }

    /** Check for pointer assignment */
    void pointerassignment();

private:

    void assignmentAddressToIntegerError(const Token *tok);
    void assignmentIntegerToAddressError(const Token *tok);

    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) {
        Check64BitPortability c(0, settings, errorLogger);
        c.assignmentAddressToIntegerError(0);
        c.assignmentIntegerToAddressError(0);
    }

    std::string myName() const {
        return "64-bit portability";
    }

    std::string classInfo() const {
        return "Check if there is 64-bit portability issues:\n"
               "* assign address to/from int/long";
    }
};
/// @}
//---------------------------------------------------------------------------
#endif

