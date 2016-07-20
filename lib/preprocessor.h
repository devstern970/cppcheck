/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2016 Cppcheck team.
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
#ifndef preprocessorH
#define preprocessorH
//---------------------------------------------------------------------------

#include "config.h"
#include "simplecpp.h"

#include <map>
#include <istream>
#include <string>
#include <list>
#include <set>

class ErrorLogger;
class Settings;

/**
 * @brief A preprocessor directive
 * Each preprocessor directive (\#include, \#define, \#undef, \#if, \#ifdef, \#else, \#endif)
 * will be recorded as an instance of this class.
 *
 * file and linenr denote the location where where the directive is defined.
 *
 */

class CPPCHECKLIB Directive {
public:
    /** name of (possibly included) file where directive is defined */
    std::string file;

    /** line number in (possibly included) file where directive is defined */
    int linenr;

    /** the actual directive text */
    std::string str;

    /** record a directive (possibly filtering src) */
    Directive(const std::string &_file, const int _linenr, const std::string &_str);
};

/// @addtogroup Core
/// @{

/**
 * @brief The cppcheck preprocessor.
 * The preprocessor has special functionality for extracting the various ifdef
 * configurations that exist in a source file.
 */
class CPPCHECKLIB Preprocessor {
public:

    /**
     * Include file types.
     */
    enum HeaderTypes {
        NoHeader = 0,
        UserHeader,
        SystemHeader
    };

    /** character that is inserted in expanded macros */
    static char macroChar;

    Preprocessor(Settings& settings, ErrorLogger *errorLogger = nullptr);
    virtual ~Preprocessor();

    static bool missingIncludeFlag;
    static bool missingSystemIncludeFlag;

    void inlineSuppressions(const simplecpp::TokenList &tokens);

    std::set<std::string> getConfigs(const simplecpp::TokenList &tokens) const;

    void loadFiles(const simplecpp::TokenList &rawtokens, std::vector<std::string> &files);

    /**
     * Extract the code for each configuration
     * @param istr The (file/string) stream to read from.
     * @param result The map that will get the results
     * @param filename The name of the file to check e.g. "src/main.cpp"
     * @param includePaths List of paths where include files should be searched from,
     * single path can be e.g. in format "include/".
     * There must be a path separator at the end. Default parameter is empty list.
     * Note that if path from given filename is also extracted and that is used as
     * a last include path if include file was not found from earlier paths.
     */
    void preprocess(std::istream &istr, std::map<std::string, std::string> &result, const std::string &filename, const std::list<std::string> &includePaths = std::list<std::string>());

    /**
     * Extract the code for each configuration. Use this with getcode() to get the
     * file data for each individual configuration.
     *
     * @param srcCodeStream The (file/string) stream to read from.
     * @param processedFile Give reference to empty string as a parameter,
     * function will fill processed file here. Use this also as a filedata parameter
     * to getcode() if you received more than once configurations.
     * @param resultConfigurations List of configurations. Pass these one by one
     * to getcode() with processedFile.
     * @param filename The name of the file to check e.g. "src/main.cpp"
     * @param includePaths List of paths where include files should be searched from,
     * single path can be e.g. in format "include/".
     * There must be a path separator at the end. Default parameter is empty list.
     * Note that if path from given filename is also extracted and that is used as
     * a last include path if include file was not found from earlier paths.
     */
    void preprocess(std::istream &srcCodeStream, std::string &processedFile, std::list<std::string> &resultConfigurations, const std::string &filename, const std::list<std::string> &includePaths);

    std::string getcode(const simplecpp::TokenList &tokens1, const std::string &cfg, std::vector<std::string> &files, const bool writeLocations);

    /**
     * Get preprocessed code for a given configuration
     * @param filedata file data including preprocessing 'if', 'define', etc
     * @param cfg configuration to read out
     * @param filename name of source file
     */
    std::string getcode(const std::string &filedata, const std::string &cfg, const std::string &filename);

    /**
     * preprocess all whitespaces
     * @param processedFile The data to be processed
     */
    static void preprocessWhitespaces(std::string &processedFile);

    /**
     * make sure empty configuration macros are not used in code. the given code must be a single configuration
     * @param code The input code
     * @param cfg configuration
     * @return true => configuration is valid
     */
    bool validateCfg(const std::string &code, const std::string &cfg);
    void validateCfgError(const std::string &cfg, const std::string &macro);

    /**
     * report error
     * @param fileName name of file that the error was found in
     * @param linenr linenr in file
     * @param errorLogger Error logger to write error to
     * @param errorType id string for error
     * @param errorText Plain text
     */
    static void writeError(const std::string &fileName, const unsigned int linenr, ErrorLogger *errorLogger, const std::string &errorType, const std::string &errorText);

    /**
     * Remove redundant parentheses from preprocessor commands. This should only be called from read().
     * @param str Code processed by read().
     * @return code with reduced parentheses
     */
    static std::string removeParentheses(const std::string &str);

    /**
     * clean up #-preprocessor lines (only)
     * @param processedFile The data to be processed
     */
    static std::string preprocessCleanupDirectives(const std::string &processedFile);

    /**
     * Returns the string between double quote characters or \< \> characters.
     * @param str e.g. \code#include "menu.h"\endcode or \code#include <menu.h>\endcode
     * After function call it will contain e.g. "menu.h" without double quotes.
     * @return NoHeader empty string if double quotes or \< \> were not found.
     *         UserHeader if file surrounded with "" was found
     *         SystemHeader if file surrounded with \<\> was found
     */
    static Preprocessor::HeaderTypes getHeaderFileName(std::string &str);
private:

    /**
     * Remove space that has new line character on left or right side of it.
     *
     * @param str The string to be converted
     * @return The string where space characters have been removed.
     */
    static std::string removeSpaceNearNL(const std::string &str);

    static std::string getdef(std::string line, bool def);

public:


    static void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings);

    void setFile0(const std::string &f) {
        file0 = f;
    }

    /**
     * dump all directives present in source file
     */
    void dump(std::ostream &out) const;

private:
    void missingInclude(const std::string &filename, unsigned int linenr, const std::string &header, HeaderTypes headerType);

    void error(const std::string &filename, unsigned int linenr, const std::string &msg);

    Settings& _settings;
    ErrorLogger *_errorLogger;

    /** list of all directives met while preprocessing file */
    std::list<Directive> directives;

    std::map<std::string, simplecpp::TokenList *> tokenlists;

    /** filename for cpp/c file - useful when reporting errors */
    std::string file0;
};

/// @}
//---------------------------------------------------------------------------
#endif // preprocessorH
