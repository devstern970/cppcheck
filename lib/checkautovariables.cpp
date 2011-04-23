/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2011 Daniel Marjamäki and Cppcheck team.
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
// Auto variables checks
//---------------------------------------------------------------------------

#include "checkautovariables.h"
#include "symboldatabase.h"

#include <sstream>
#include <iostream>
#include <string>

//---------------------------------------------------------------------------


// Register this check class into cppcheck by creating a static instance of it..
namespace
{
static CheckAutoVariables instance;
}


bool CheckAutoVariables::errorAv(const Token* left, const Token* right)
{
    const Variable *var = _tokenizer->getSymbolDatabase()->getVariableFromVarId(left->varId());

    if (!var || !var->isArgument())
        return false;

    return isAutoVar(right->varId());
}

bool CheckAutoVariables::isAutoVar(unsigned int varId)
{
    const Variable *var = _tokenizer->getSymbolDatabase()->getVariableFromVarId(varId);

    if (!var || !var->isLocal() || var->isStatic() || var->isArray())
        return false;

    return true;
}

bool CheckAutoVariables::isAutoVarArray(unsigned int varId)
{
    const Variable *var = _tokenizer->getSymbolDatabase()->getVariableFromVarId(varId);

    if (!var || !var->isLocal() || var->isStatic() || !var->isArray())
        return false;

    return true;
}

void CheckAutoVariables::autoVariables()
{
    const SymbolDatabase *symbolDatabase = _tokenizer->getSymbolDatabase();

    std::list<Scope>::const_iterator scope;

    for (scope = symbolDatabase->scopeList.begin(); scope != symbolDatabase->scopeList.end(); ++scope)
    {
        // only check functions
        if (scope->type != Scope::eFunction)
            continue;

        unsigned int indentlevel = 0;
        // Which variables have an unknown type?
        std::set<unsigned int> unknown_type;
        for (const Token *tok = scope->classDef->next()->link(); tok; tok = tok->next())
        {
            // indentlevel..
            if (tok->str() == "{")
                ++indentlevel;
            else if (tok->str() == "}")
            {
                if (indentlevel <= 1)
                    break;
                --indentlevel;
            }

            //Critical assignment
            if (Token::Match(tok, "[;{}] %var% = & %var%") && errorAv(tok->tokAt(1), tok->tokAt(4)))
            {
                errorAutoVariableAssignment(tok);
            }
            else if (Token::Match(tok, "[;{}] * %var% = & %var%") && errorAv(tok->tokAt(2), tok->tokAt(5)) &&
                     unknown_type.find(tok->tokAt(5)->varId()) == unknown_type.end())
            {
                errorAutoVariableAssignment(tok);
            }
            else if (Token::Match(tok, "[;{}] %var% [ %any% ] = & %var%") && errorAv(tok->tokAt(1), tok->tokAt(7)))
            {
                errorAutoVariableAssignment(tok);
            }
            // Critical return
            else if (Token::Match(tok, "return & %var% ;") && isAutoVar(tok->tokAt(2)->varId()))
            {
                reportError(tok, Severity::error, "autoVariables", "Return of the address of an auto-variable");
            }
            // Invalid pointer deallocation
            else if (Token::Match(tok, "free ( %var% ) ;") && isAutoVarArray(tok->tokAt(2)->varId()))
            {
                reportError(tok, Severity::error, "autoVariables", "Invalid deallocation");
            }
        }
    }
}

//---------------------------------------------------------------------------

void CheckAutoVariables::returnPointerToLocalArray()
{
    const SymbolDatabase *symbolDatabase = _tokenizer->getSymbolDatabase();

    std::list<Scope>::const_iterator scope;

    for (scope = symbolDatabase->scopeList.begin(); scope != symbolDatabase->scopeList.end(); ++scope)
    {
        // only check functions
        if (scope->type != Scope::eFunction)
            continue;

        const Token *tok = scope->classDef;

        // skip any qualification
        while (Token::Match(tok->tokAt(-2), "%type% ::"))
            tok = tok->tokAt(-2);

        // have we reached a function that returns a pointer
        if (Token::Match(tok->tokAt(-2), "%type% *"))
        {
            // go to the '('
            const Token *tok2 = scope->classDef->next();

            // go to the ')'
            tok2 = tok2->next()->link();

            unsigned int indentlevel = 0;
            for (; tok2; tok2 = tok2->next())
            {
                // indentlevel..
                if (tok2->str() == "{")
                    ++indentlevel;
                else if (tok2->str() == "}")
                {
                    if (indentlevel <= 1)
                        break;
                    --indentlevel;
                }

                // Return pointer to local array variable..
                if (Token::Match(tok2, "return %var% ;"))
                {
                    const unsigned int varid = tok2->next()->varId();
                    const Variable *var = symbolDatabase->getVariableFromVarId(varid);

                    if (var && var->isLocal() && !var->isStatic() && var->isArray())
                    {
                        errorReturnPointerToLocalArray(tok2);
                    }
                }
            }
        }
    }
}

void CheckAutoVariables::errorReturnPointerToLocalArray(const Token *tok)
{
    reportError(tok, Severity::error, "returnLocalVariable", "Returning pointer to local array variable");
}

void CheckAutoVariables::errorAutoVariableAssignment(const Token *tok)
{
    reportError(tok, Severity::error, "autoVariables",
                "Assigning address of local auto-variable to a function parameter.\n"
                "Dangerous assignment - function parameter takes the address of a local "
                "auto-variable. Local auto-variables are reserved from the stack. And the "
                "stack is freed when the function ends. So the pointer to a local variable "
                "is invalid after the function ends.");
}

//---------------------------------------------------------------------------

// return temporary?
bool CheckAutoVariables::returnTemporary(const Token *tok) const
{
    if (!Token::Match(tok, "return %var% ("))
        return false;
    return bool(0 != Token::findmatch(_tokenizer->tokens(), ("std :: string " + tok->next()->str() + " (").c_str()));
}

//---------------------------------------------------------------------------

void CheckAutoVariables::returnReference()
{
    const SymbolDatabase *symbolDatabase = _tokenizer->getSymbolDatabase();

    std::list<Scope>::const_iterator scope;

    for (scope = symbolDatabase->scopeList.begin(); scope != symbolDatabase->scopeList.end(); ++scope)
    {
        // only check functions
        if (scope->type != Scope::eFunction)
            continue;

        const Token *tok = scope->classDef;

        // skip any qualification
        while (Token::Match(tok->tokAt(-2), "%type% ::"))
            tok = tok->tokAt(-2);

        // have we reached a function that returns a reference?
        if (Token::Match(tok->tokAt(-2), "%type% &") ||
            Token::Match(tok->tokAt(-2), "> &"))
        {
            // go to the '('
            const Token *tok2 = scope->classDef->next();

            // go to the ')'
            tok2 = tok2->link();

            unsigned int indentlevel = 0;
            for (; tok2; tok2 = tok2->next())
            {
                // indentlevel..
                if (tok2->str() == "{")
                    ++indentlevel;
                else if (tok2->str() == "}")
                {
                    if (indentlevel <= 1)
                        break;
                    --indentlevel;
                }

                // return..
                if (Token::Match(tok2, "return %var% ;"))
                {
                    // is the returned variable a local variable?
                    const unsigned int varid = tok2->next()->varId();
                    const Variable *var = symbolDatabase->getVariableFromVarId(varid);

                    if (var && var->isLocal() && !var->isStatic())
                    {
                        // report error..
                        errorReturnReference(tok2);
                    }
                }

                // return reference to temporary..
                else if (returnTemporary(tok2))
                {
                    // report error..
                    errorReturnTempReference(tok2);
                }
            }
        }
    }
}

void CheckAutoVariables::errorReturnReference(const Token *tok)
{
    reportError(tok, Severity::error, "returnReference", "Returning reference to auto variable");
}

void CheckAutoVariables::errorReturnTempReference(const Token *tok)
{
    reportError(tok, Severity::error, "returnTempReference", "Returning reference to temporary");
}

//---------------------------------------------------------------------------

// Return c_str
void CheckAutoVariables::returncstr()
{
    // locate function that returns a const char *..
    const SymbolDatabase *symbolDatabase = _tokenizer->getSymbolDatabase();

    std::list<Scope>::const_iterator scope;

    for (scope = symbolDatabase->scopeList.begin(); scope != symbolDatabase->scopeList.end(); ++scope)
    {
        // only check functions
        if (scope->type != Scope::eFunction)
            continue;

        const Token *tok = scope->classDef;

        // skip any qualification
        while (Token::Match(tok->tokAt(-2), "%type% ::"))
            tok = tok->tokAt(-2);

        // have we reached a function that returns a const char *
        if (Token::simpleMatch(tok->tokAt(-3), "const char *"))
        {
            // go to the '('
            const Token *tok2 = scope->classDef->next();

            // go to the ')'
            tok2 = tok2->next()->link();

            unsigned int indentlevel = 0;
            for (; tok2; tok2 = tok2->next())
            {
                // indentlevel..
                if (tok2->str() == "{")
                    ++indentlevel;
                else if (tok2->str() == "}")
                {
                    if (indentlevel <= 1)
                        break;
                    --indentlevel;
                }

                // return..
                if (Token::Match(tok2, "return %var% . c_str ( ) ;"))
                {
                    // is the returned variable a local variable?
                    const unsigned int varid = tok2->next()->varId();
                    const Variable *var = symbolDatabase->getVariableFromVarId(varid);

                    if (var && var->isLocal() && !var->isStatic())
                    {
                        // report error..
                        errorReturnAutocstr(tok2);
                    }
                }

                // return pointer to temporary..
                else if (returnTemporary(tok2))
                {
                    // report error..
                    errorReturnTempPointer(tok2);
                }
            }
        }
    }
}

void CheckAutoVariables::errorReturnAutocstr(const Token *tok)
{
    reportError(tok, Severity::error, "returnAutocstr", "Returning pointer to auto variable");
}

void CheckAutoVariables::errorReturnTempPointer(const Token *tok)
{
    reportError(tok, Severity::error, "returnTempPointer", "Returning pointer to temporary");
}
