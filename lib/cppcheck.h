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

//---------------------------------------------------------------------------
#ifndef cppcheckH
#define cppcheckH
//---------------------------------------------------------------------------

#include "config.h"
#include "settings.h"
#include "errorlogger.h"
#include "check.h"

#include <string>
#include <list>
#include <istream>

class Tokenizer;

/// @addtogroup Core
/// @{

/**
 * @brief This is the base class which will use other classes to do
 * static code analysis for C and C++ code to find possible
 * errors or places that could be improved.
 * Usage: See check() for more info.
 */
class CPPCHECKLIB CppCheck : ErrorLogger {
public:
    /**
     * @brief Constructor.
     */
    CppCheck(ErrorLogger &errorLogger, bool useGlobalSuppressions);

    /**
     * @brief Destructor.
     */
    virtual ~CppCheck();

    /**
     * @brief This starts the actual checking. Note that you must call
     * parseFromArgs() or settings() and addFile() before calling this.
     * @return amount of errors found or 0 if none were found.
     */

    /**
      * @brief Check the file.
      * This function checks one given file for errors.
      * @param path Path to the file to check.
      * @return amount of errors found or 0 if none were found.
      * @note You must set settings before calling this function (by calling
      *  settings()).
      */
    unsigned int check(const std::string &path);

    /**
      * @brief Check the file.
      * This function checks one "virtual" file. The file is not read from
      * the disk but the content is given in @p content. In errors the @p path
      * is used as a filename.
      * @param path Path to the file to check.
      * @param content File content as a string.
      * @return amount of errors found or 0 if none were found.
      * @note You must set settings before calling this function (by calling
      *  settings()).
      */
    unsigned int check(const std::string &path, const std::string &content);

    /**
     * @brief Check function usage.
     * @note Call this after all files has been checked
     */
    void checkFunctionUsage();

    /**
     * @brief Get reference to current settings.
     * @return a reference to current settings
     */
    Settings &settings();

    /**
     * @brief Returns current version number as a string.
     * @return version, e.g. "1.38"
     */
    static const char * version();

    /**
     * @brief Returns extra version info as a string.
     * This is for returning extra version info, like Git commit id, build
     * time/date etc.
     * @return extra version info, e.g. "04d42151" (Git commit id).
     */
    static const char * extraVersion();

    virtual void reportStatus(unsigned int fileindex, unsigned int filecount, std::size_t sizedone, std::size_t sizetotal);

    /**
     * @brief Terminate checking. The checking will be terminated as soon as possible.
     */
    void terminate() {
        _settings.terminate();
    }

    /**
     * @brief Call all "getErrorMessages" in all registered Check classes.
     * Also print out XML header and footer.
     */
    void getErrorMessages();

    /**
     * @brief Analyse file - It's public so unit tests can be written
     */
    void analyseFile(std::istream &f, const std::string &filename);

    void tooManyConfigsError(const std::string &file, const std::size_t numberOfConfigurations);
    void purgedConfigurationMessage(const std::string &file, const std::string& configuration);

    void dontSimplify() {
        _simplify = false;
    }

    /** analyse whole program, run this after all TUs has been scanned. */
    void analyseWholeProgram();

private:

    /** @brief There has been a internal error => Report information message */
    void internalError(const std::string &filename, const std::string &msg);

    /**
     * @brief Process one file.
     * @param filename file name
     * @param fileStream stream the file content can be read from
     * @return amount of errors found
     */
    unsigned int processFile(const std::string& filename, std::istream& fileStream);

    /** @brief Check file */
    bool checkFile(const std::string &code, const char FileName[], std::set<unsigned long long>& checksums);

    /**
     * @brief Execute rules, if any
     * @param tokenlist token list to use (normal / simple)
     * @param tokenizer tokenizer
     */
    void executeRules(const std::string &tokenlist, const Tokenizer &tokenizer);

    /**
     * @brief Errors and warnings are directed here.
     *
     * @param msg Errors messages are normally in format
     * "[filepath:line number] Message", e.g.
     * "[main.cpp:4] Uninitialized member variable"
     */
    virtual void reportErr(const ErrorLogger::ErrorMessage &msg);

    /**
     * @brief Information about progress is directed here.
     *
     * @param outmsg Message to show, e.g. "Checking main.cpp..."
     */
    virtual void reportOut(const std::string &outmsg);

    /**
     * @brief Check given code. If error is found, return true
     * and print out source of the file. Try to reduce the code
     * while still showing the error.
     */
    bool findError(std::string code, const char FileName[]);

    /**
     * @brief Replace "from" strings with "to" strings in "code"
     * and return it.
     */
    static void replaceAll(std::string& code, const std::string &from, const std::string &to);

    std::list<std::string> _errorList;
    Settings _settings;

    void reportProgress(const std::string &filename, const char stage[], const std::size_t value);

    /**
     * Output information messages.
     */
    virtual void reportInfo(const ErrorLogger::ErrorMessage &msg);

    ErrorLogger &_errorLogger;

    /** @brief Current preprocessor configuration */
    std::string cfg;

    unsigned int exitcode;

    bool _useGlobalSuppressions;

    /** Are there too many configs? */
    bool tooManyConfigs;

    /** Simplify code? true by default */
    bool _simplify;

    /** File info used for whole program analysis */
    std::list<Check::FileInfo*> fileInfo;
};

/// @}
//---------------------------------------------------------------------------
#endif // cppcheckH
