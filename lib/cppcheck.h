/* -*- C++ -*-
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2024 Cppcheck team.
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

#include "analyzerinfo.h"
#include "check.h"
#include "color.h"
#include "config.h"
#include "errorlogger.h"
#include "settings.h"

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

class TokenList;
enum class SHOWTIME_MODES : std::uint8_t;
struct FileSettings;
class CheckUnusedFunctions;
class Tokenizer;
class FileWithDetails;
class RemarkComment;

namespace simplecpp { class TokenList; }

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
    using ExecuteCmdFn = std::function<int (std::string,std::vector<std::string>,std::string,std::string&)>;

    /**
     * @brief Constructor.
     */
    CppCheck(ErrorLogger &errorLogger,
             bool useGlobalSuppressions,
             ExecuteCmdFn executeCommand);

    /**
     * @brief Destructor.
     */
    ~CppCheck() override;

    /**
     * @brief This starts the actual checking. Note that you must call
     * parseFromArgs() or settings() and addFile() before calling this.
     * @return amount of errors found or 0 if none were found.
     */

    /**
     * @brief Check the file.
     * This function checks one given file for errors.
     * @param file The file to check.
     * @return amount of errors found or 0 if none were found.
     * @note You must set settings before calling this function (by calling
     *  settings()).
     */
    unsigned int check(const FileWithDetails &file);
    unsigned int check(const FileSettings &fs);

    /**
     * @brief Check the file.
     * This function checks one "virtual" file. The file is not read from
     * the disk but the content is given in @p content. In errors the @p path
     * is used as a filename.
     * @param file The file to check.
     * @param content File content as a string.
     * @return amount of errors found or 0 if none were found.
     * @note You must set settings before calling this function (by calling
     *  settings()).
     */
    unsigned int check(const FileWithDetails &file, const std::string &content);

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

    /**
     * @brief Call all "getErrorMessages" in all registered Check classes.
     * Also print out XML header and footer.
     */
    static void getErrorMessages(ErrorLogger &errorlogger);

    void tooManyConfigsError(const std::string &file, int numberOfConfigurations);
    void purgedConfigurationMessage(const std::string &file, const std::string& configuration);

    /** Analyse whole program, run this after all TUs has been scanned.
     * This is deprecated and the plan is to remove this when
     * .analyzeinfo is good enough.
     * Return true if an error is reported.
     */
    bool analyseWholeProgram();

    /** Analyze all files using clang-tidy */
    void analyseClangTidy(const FileSettings &fileSettings);

    /** analyse whole program use .analyzeinfo files */
    unsigned int analyseWholeProgram(const std::string &buildDir, const std::list<FileWithDetails> &files, const std::list<FileSettings>& fileSettings);

    /** Remove *.ctu-info files */
    void removeCtuInfoFiles(const std::list<FileWithDetails>& files, const std::list<FileSettings>& fileSettings); // cppcheck-suppress functionConst // has side effects

    static void resetTimerResults();
    static void printTimerResults(SHOWTIME_MODES mode);

    bool isPremiumCodingStandardId(const std::string& id) const;

    /**
     * @brief Get dumpfile <rawtokens> contents, this is only public for testing purposes
     */
    std::string getDumpFileContentsRawTokens(const std::vector<std::string>& files, const simplecpp::TokenList& tokens1) const;

    std::string getLibraryDumpData() const;

private:
#ifdef HAVE_RULES
    /** Are there "simple" rules */
    bool hasRule(const std::string &tokenlist) const;
#endif

    /** @brief There has been an internal error => Report information message */
    void internalError(const std::string &filename, const std::string &msg);

    /**
     * @brief Check a file using stream
     * @param file the file
     * @param cfgname  cfg name
     * @param fileStream stream the file content can be read from
     * @return number of errors found
     */
    unsigned int checkFile(const FileWithDetails& file, const std::string &cfgname, std::istream* fileStream = nullptr);

    /**
     * @brief Check normal tokens
     * @param tokenizer tokenizer instance
     */
    void checkNormalTokens(const Tokenizer &tokenizer);

    /**
     * Execute addons
     */
    void executeAddons(const std::vector<std::string>& files, const std::string& file0);
    void executeAddons(const std::string &dumpFile, const FileWithDetails& file);

    /**
     * Execute addons
     */
    void executeAddonsWholeProgram(const std::list<FileWithDetails> &files, const std::list<FileSettings>& fileSettings);

#ifdef HAVE_RULES
    /**
     * @brief Execute rules, if any
     * @param tokenlist token list to use (define / normal / raw)
     * @param list token list
     */
    void executeRules(const std::string &tokenlist, const TokenList &list);
#endif

    unsigned int checkClang(const FileWithDetails &file);

    /**
     * @brief Errors and warnings are directed here.
     *
     * @param msg Errors messages are normally in format
     * "[filepath:line number] Message", e.g.
     * "[main.cpp:4] Uninitialized member variable"
     */
    void reportErr(const ErrorMessage &msg) override;

    /**
     * @brief Information about progress is directed here.
     *
     * @param outmsg Message to show, e.g. "Checking main.cpp..."
     */
    void reportOut(const std::string &outmsg, Color c = Color::Reset) override;

    // TODO: store hashes instead of the full messages
    std::unordered_set<std::string> mErrorList;
    Settings mSettings;

    void reportProgress(const std::string &filename, const char stage[], std::size_t value) override;

    ErrorLogger &mErrorLogger;

    /** @brief Current preprocessor configuration */
    std::string mCurrentConfig;

    using Location = std::pair<std::string, int>;
    std::map<Location, std::set<std::string>> mLocationMacros; // What macros are used on a location?

    unsigned int mExitCode{};

    bool mUseGlobalSuppressions;

    /** Are there too many configs? */
    bool mTooManyConfigs{};

    /** File info used for whole program analysis */
    std::list<Check::FileInfo*> mFileInfo;

    AnalyzerInformation mAnalyzerInformation;

    /** Callback for executing a shell command (exe, args, output) */
    ExecuteCmdFn mExecuteCommand;

    std::ofstream mPlistFile;

    std::unique_ptr<CheckUnusedFunctions> mUnusedFunctionsCheck;

    std::vector<RemarkComment> mRemarkComments;
};

/// @}
//---------------------------------------------------------------------------
#endif // cppcheckH
