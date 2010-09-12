/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2010 Daniel Marjam�ki and Cppcheck team.
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

#include "preprocessor.h"
#include "tokenize.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Check that array indexes are within bounds
 * 1. Locate array access through: [ .. ]
 * 2. Try to determine if index is within bounds.
 * 3. If it fails to determine that the index is within bounds then write warning
 * \param tokenizer The tokenizer
 * \param errout output stream to write warnings to
 */

static void arrayIndex(const Tokenizer &tokenizer, std::ostream &errout)
{
    for (const Token *tok = tokenizer.tokens(); tok; tok = tok->next())
    {
        // 1. Locate array access through: [ .. ]
        if (tok->str() == "[")
        {
            // 2. try to determine if the array index is within bounds

            // array declaration
            if (Token::simpleMatch(tok, "[ ]"))
                continue;
            if (Token::Match(tok->tokAt(-2), "%type% %var% [ %num% ] ;|="))
                continue;

            // 3. If it fails to determine that the index is within bounds then write warning
            errout << tokenizer.fileLine(tok)
                   << " failed to determine if given array index is within bounds"
                   << std::endl;
        }
    }
}


int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "syntax: cppcheck-verify file.cpp" << std::endl;
        return 0;
    }

    const std::string fileName = argv[1];

    Tokenizer tokenizer;

    {
        // Preprocess the file..
        Preprocessor preprocessor;
        std::ifstream fin(fileName.c_str());
        std::string filedata;
        std::list<std::string> configurations;
        std::list<std::string> includePaths;
        preprocessor.preprocess(fin,
                                filedata,
                                configurations,
                                fileName,
                                includePaths);
        filedata = Preprocessor::getcode(filedata, "", fileName, NULL);

        // Tokenize the preprocessed code..
        std::istringstream istr(filedata);
        tokenizer.tokenize(istr, fileName.c_str(), "");
    }

    // Check the tokens..
    arrayIndex(tokenizer, std::cerr);

    return 0;
}
