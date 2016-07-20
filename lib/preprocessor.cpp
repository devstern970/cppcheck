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


#include "preprocessor.h"
#include "path.h"
#include "errorlogger.h"
#include "settings.h"
#include "simplecpp.h"

#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <set>
#include <stack>

/**
 * Remove heading and trailing whitespaces from the input parameter.
 * If string is all spaces/tabs, return empty string.
 * @param s The string to trim.
 */
static std::string trim(const std::string& s)
{
    const std::string::size_type beg = s.find_first_not_of(" \t");
    if (beg == std::string::npos)
        return "";
    const std::string::size_type end = s.find_last_not_of(" \t");
    return s.substr(beg, end - beg + 1);
}

Directive::Directive(const std::string &_file, const int _linenr, const std::string &_str):
    file(_file),
    linenr(_linenr),
    str(_str)
{
    str = trim(str);
}

bool Preprocessor::missingIncludeFlag;
bool Preprocessor::missingSystemIncludeFlag;

char Preprocessor::macroChar = char(1);

Preprocessor::Preprocessor(Settings& settings, ErrorLogger *errorLogger) : _settings(settings), _errorLogger(errorLogger)
{
}

Preprocessor::~Preprocessor()
{
    for (std::map<std::string, simplecpp::TokenList *>::iterator it = tokenlists.begin(); it != tokenlists.end(); ++it)
        delete it->second;
}

void Preprocessor::writeError(const std::string &fileName, const unsigned int linenr, ErrorLogger *errorLogger, const std::string &errorType, const std::string &errorText)
{
    if (!errorLogger)
        return;

    std::list<ErrorLogger::ErrorMessage::FileLocation> locationList;
    ErrorLogger::ErrorMessage::FileLocation loc(fileName, linenr);
    locationList.push_back(loc);
    errorLogger->reportErr(ErrorLogger::ErrorMessage(locationList,
                           Severity::error,
                           errorText,
                           errorType,
                           false));
}


void Preprocessor::inlineSuppressions(const simplecpp::TokenList &tokens)
{
    if (!_settings.inlineSuppressions)
        return;

    std::list<std::string> suppressionIDs;

    for (const simplecpp::Token *tok = tokens.cbegin(); tok; tok = tok->next) {
        if (tok->comment) {
            std::istringstream iss(tok->str.substr(2));
            std::string word;
            iss >> word;
            if (word != "cppcheck-suppress")
                continue;
            iss >> word;
            if (iss)
                suppressionIDs.push_back(word);
            continue;
        }

        if (suppressionIDs.empty())
            continue;

        // Relative filename
        std::string relativeFilename(tok->location.file());
        if (_settings.relativePaths) {
            for (std::size_t j = 0U; j < _settings.basePaths.size(); ++j) {
                const std::string bp = _settings.basePaths[j] + "/";
                if (relativeFilename.compare(0,bp.size(),bp)==0) {
                    relativeFilename = relativeFilename.substr(bp.size());
                }
            }
        }


        // Add the suppressions.
        for (std::list<std::string>::const_iterator it = suppressionIDs.begin(); it != suppressionIDs.end(); ++it) {
            _settings.nomsg.addSuppression(*it, relativeFilename, tok->location.line);
        }
        suppressionIDs.clear();
    }
}

static std::string readcondition(const simplecpp::Token *iftok, const std::set<std::string> &defined)
{
    const simplecpp::Token *cond = iftok->next;
    if (!cond)
        return "";

    if (cond->str == "0")
        return "0";

    if (cond->name && cond->next && iftok->location.sameline(cond->location) && !iftok->location.sameline(cond->next->location)) {
        if (defined.find(cond->str) == defined.end())
            return cond->str;
    }

    if (cond->op == '(' && cond->next && cond->next->name && cond->next->next && cond->next->next->op == ')') {
        if (defined.find(cond->next->str) == defined.end())
            return cond->next->str;
    }

    if (cond->name && cond->next && cond->next->str == "==" && cond->next->next && cond->next->next->number) {
        if (defined.find(cond->str) == defined.end())
            return cond->str + '=' + cond->next->next->str;
    }

    std::set<std::string> configset;
    for (; cond && iftok->location.sameline(cond->location); cond = cond->next) {
        if (cond->op == '!')
            break;
        if (cond->str == "defined") {
            if (!cond->next)
                break;
            const simplecpp::Token *dtok = nullptr;
            if (cond->next->op == '(')
                dtok = cond->next->next;
            else if (cond->next->name)
                dtok = cond->next;
            if (dtok && dtok->name && defined.find(dtok->str) == defined.end())
                configset.insert(dtok->str);
        }
    }
    std::string cfg;
    for (std::set<std::string>::const_iterator it = configset.begin(); it != configset.end(); ++it) {
        if (!cfg.empty())
            cfg += ';';
        cfg += *it;
    }
    return cfg;
}

static std::string cfg(const std::vector<std::string> &configs)
{
    std::set<std::string> configs2(configs.begin(), configs.end());
    std::string ret;
    for (std::set<std::string>::const_iterator it = configs2.begin(); it != configs2.end(); ++it) {
        if (it->empty())
            continue;
        if (*it == "0")
            return "";
        if (!ret.empty())
            ret += ';';
        ret += *it;
    }
    return ret;
}

static void getConfigs(const simplecpp::TokenList &tokens, std::set<std::string> &defined, std::set<std::string> &ret)
{
    std::vector<std::string> configs_if;
    std::vector<std::string> configs_ifndef;

    for (const simplecpp::Token *tok = tokens.cbegin(); tok; tok = tok->next) {
        if (tok->op != '#')
            continue;
        if (tok->previous && tok->location.sameline(tok->previous->location))
            continue;
        if (!tok->next)
            continue;
        if (tok->next->str == "ifdef" || tok->next->str == "ifndef" || tok->next->str == "if") {
            std::string config;
            if (tok->next->str == "ifdef" || tok->next->str == "ifndef") {
                if (tok->next->next && tok->next->next->name && tok->location.sameline(tok->next->next->location) && tok->next->next->next && !tok->location.sameline(tok->next->next->next->location))
                    config = tok->next->next->str;
                if (defined.find(config) != defined.end())
                    config.clear();
            } else if (tok->next->str == "if") {
                config = readcondition(tok->next, defined);
            }
            configs_if.push_back((tok->next->str == "ifndef") ? std::string() : config);
            configs_ifndef.push_back((tok->next->str == "ifndef") ? config : std::string());
            ret.insert(cfg(configs_if));
        } else if (tok->next->str == "elif") {
            configs_if.pop_back();
            configs_if.push_back(readcondition(tok->next, defined));
            ret.insert(cfg(configs_if));
        } else if (tok->next->str == "else") {
            configs_if.pop_back();
            configs_if.push_back(configs_ifndef.back());
            ret.insert(cfg(configs_if));
        } else if (tok->next->str == "endif" && tok->location.sameline(tok->next->location)) {
            if (!configs_if.empty())
                configs_if.pop_back();
            if (!configs_ifndef.empty())
                configs_ifndef.pop_back();
        } else if (tok->next->str == "define" && tok->next->next && tok->next->next->name && tok->location.sameline(tok->next->next->location)) {
            defined.insert(tok->next->next->str);
        }
    }
}


std::set<std::string> Preprocessor::getConfigs(const simplecpp::TokenList &tokens) const
{
    std::set<std::string> ret;
    ret.insert("");
    simplecpp::TokenList tokens2(tokens);
    tokens2.removeComments();
    if (!tokens2.cbegin())
        return ret;

    std::set<std::string> defined;
    defined.insert("__cplusplus");

    ::getConfigs(tokens2, defined, ret);

    for (std::map<std::string, simplecpp::TokenList*>::const_iterator it = tokenlists.begin(); it != tokenlists.end(); ++it)
        ::getConfigs(*(it->second), defined, ret);

    return ret;
}

std::string Preprocessor::preprocessCleanupDirectives(const std::string &processedFile)
{
    std::ostringstream code;
    std::istringstream sstr(processedFile);

    std::string line;
    while (std::getline(sstr, line)) {
        // Trim lines..
        if (!line.empty() && line[0] == ' ')
            line.erase(0, line.find_first_not_of(" "));
        if (!line.empty() && line.back() == ' ')
            line.erase(line.find_last_not_of(" ") + 1);

        // Preprocessor
        if (!line.empty() && line[0] == '#') {
            enum {
                ESC_NONE,
                ESC_SINGLE,
                ESC_DOUBLE
            } escapeStatus = ESC_NONE;

            char prev = ' '; // hack to make it skip spaces between # and the directive
            code << "#";
            std::string::const_iterator i = line.begin();
            ++i;

            // need space.. #if( => #if (
            bool needSpace = true;
            while (i != line.end()) {
                // disable esc-mode
                if (escapeStatus != ESC_NONE) {
                    if (prev != '\\' && escapeStatus == ESC_SINGLE && *i == '\'') {
                        escapeStatus = ESC_NONE;
                    }
                    if (prev != '\\' && escapeStatus == ESC_DOUBLE && *i == '"') {
                        escapeStatus = ESC_NONE;
                    }
                } else {
                    // enable esc-mode
                    if (escapeStatus == ESC_NONE && *i == '"')
                        escapeStatus = ESC_DOUBLE;
                    if (escapeStatus == ESC_NONE && *i == '\'')
                        escapeStatus = ESC_SINGLE;
                }
                // skip double whitespace between arguments
                if (escapeStatus == ESC_NONE && prev == ' ' && *i == ' ') {
                    ++i;
                    continue;
                }
                // Convert #if( to "#if ("
                if (escapeStatus == ESC_NONE) {
                    if (needSpace) {
                        if (*i == '(' || *i == '!')
                            code << " ";
                        else if (!std::isalpha((unsigned char)*i))
                            needSpace = false;
                    }
                    if (*i == '#')
                        needSpace = true;
                }
                code << *i;
                if (escapeStatus != ESC_NONE && prev == '\\' && *i == '\\') {
                    prev = ' ';
                } else {
                    prev = *i;
                }
                ++i;
            }
            if (escapeStatus != ESC_NONE) {
                // unmatched quotes.. compiler should probably complain about this..
            }
        } else {
            // Do not mess with regular code..
            code << line;
        }
        code << (sstr.eof()?"":"\n");
    }

    return code.str();
}

void Preprocessor::preprocess(std::istream &istr, std::map<std::string, std::string> &result, const std::string &filename, const std::list<std::string> &includePaths)
{
    (void)includePaths;

    simplecpp::OutputList outputList;
    std::vector<std::string> files;
    const simplecpp::TokenList tokens1(istr, files, filename, &outputList);


    const std::set<std::string> configs = getConfigs(tokens1);

    for (std::set<std::string>::const_iterator it = configs.begin(); it != configs.end(); ++it) {
        if (_settings.userUndefs.find(*it) == _settings.userUndefs.end()) {
            result[ *it ] = getcode(tokens1, *it, files, false);
        }
    }
}

std::string Preprocessor::removeSpaceNearNL(const std::string &str)
{
    std::string tmp;
    char prev = '\n'; // treat start of file as newline
    for (std::size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ' &&
            (prev == '\n' ||
             i + 1 >= str.size() || // treat end of file as newline
             str[i+1] == '\n'
            )
           ) {
            // Ignore space that has new line in either side of it
        } else {
            tmp.append(1, str[i]);
            prev = str[i];
        }
    }

    return tmp;
}

void Preprocessor::preprocessWhitespaces(std::string &processedFile)
{
    // Replace all tabs with spaces..
    std::replace(processedFile.begin(), processedFile.end(), '\t', ' ');

    // Remove space characters that are after or before new line character
    processedFile = removeSpaceNearNL(processedFile);
}

void Preprocessor::preprocess(std::istream &srcCodeStream, std::string &processedFile, std::list<std::string> &resultConfigurations, const std::string &filename, const std::list<std::string> &includePaths)
{
    (void)includePaths;

    if (file0.empty())
        file0 = filename;

    simplecpp::OutputList outputList;
    std::vector<std::string> files;
    const simplecpp::TokenList tokens1(srcCodeStream, files, filename, &outputList);

    const std::set<std::string> configs = getConfigs(tokens1);
    for (std::set<std::string>::const_iterator it = configs.begin(); it != configs.end(); ++it)
        resultConfigurations.push_back(*it);

    processedFile = tokens1.stringify();
}

static void splitcfg(const std::string &cfg, std::list<std::string> &defines, const std::string &defaultValue)
{
    for (std::string::size_type pos1 = 0U; pos1 < cfg.size();) {
        const std::string::size_type pos2 = cfg.find(";",pos1);
        std::string def = (pos2 == std::string::npos) ? cfg.substr(pos1) : cfg.substr(pos1, pos2 - pos1);
        if (!defaultValue.empty() && def.find("=") == std::string::npos)
            def += '=' + defaultValue;
        defines.push_back(def);
        pos1 = (pos2 == std::string::npos) ? pos2 : pos2 + 1U;
    }
}

void Preprocessor::loadFiles(const simplecpp::TokenList &rawtokens, std::vector<std::string> &files)
{
    const std::string filename(files[0]);

    // Create a map for the cfg for faster access to defines
    simplecpp::DUI dui;

    splitcfg(_settings.userDefines, dui.defines, "1");

    for (std::vector<std::string>::const_iterator it = _settings.library.defines.begin(); it != _settings.library.defines.end(); ++it) {
        if (it->compare(0,8,"#define ")!=0)
            continue;
        std::string s = it->substr(8);
        std::string::size_type pos = s.find_first_of(" (");
        if (pos == std::string::npos) {
            dui.defines.push_back(s);
            continue;
        }
        if (s[pos] == ' ') {
            s[pos] = '=';
        } else {
            s[s.find(")")+1] = '=';
        }
        dui.defines.push_back(s);
    }

    if (Path::isCPP(filename))
        dui.defines.push_back("__cplusplus");

    dui.undefined = _settings.userUndefs;

    dui.includePaths = _settings.includePaths;

    simplecpp::OutputList outputList;

    tokenlists = simplecpp::load(rawtokens, files, dui, &outputList);
}

std::string Preprocessor::getcode(const simplecpp::TokenList &tokens1, const std::string &cfg, std::vector<std::string> &files, const bool writeLocations)
{
    const std::string filename(files[0]);

    // Create a map for the cfg for faster access to defines
    simplecpp::DUI dui;

    splitcfg(_settings.userDefines, dui.defines, "1");
    splitcfg(cfg, dui.defines, "");

    for (std::vector<std::string>::const_iterator it = _settings.library.defines.begin(); it != _settings.library.defines.end(); ++it) {
        if (it->compare(0,8,"#define ")!=0)
            continue;
        std::string s = it->substr(8);
        std::string::size_type pos = s.find_first_of(" (");
        if (pos == std::string::npos) {
            dui.defines.push_back(s);
            continue;
        }
        if (s[pos] == ' ') {
            s[pos] = '=';
        } else {
            s[s.find(")")+1] = '=';
        }
        dui.defines.push_back(s);
    }

    if (Path::isCPP(filename))
        dui.defines.push_back("__cplusplus");

    dui.undefined = _settings.userUndefs;

    dui.includePaths = _settings.includePaths;

    simplecpp::OutputList outputList;
    std::list<simplecpp::MacroUsage> macroUsage;
    const simplecpp::TokenList &tokens2 = simplecpp::preprocess(tokens1, files, tokenlists, dui, &outputList, &macroUsage);

    bool showerror = (!_settings.userDefines.empty() && !_settings.force);
    for (simplecpp::OutputList::const_iterator it = outputList.begin(); it != outputList.end(); ++it) {
        if (it->type == simplecpp::Output::ERROR) {
            if (it->msg.compare(0,6,"#error")!=0 || showerror)
                error(it->location.file(), it->location.line, it->msg);
            return "";
        }
    }

    // directive list..
    directives.clear();
    for (const simplecpp::Token *tok = tokens1.cbegin(); tok; tok = tok ? tok->next : nullptr) {
        if ((tok->op != '#') || (tok->previous && tok->previous->location.line == tok->location.line))
            continue;
        if (tok->next && tok->next->str == "endfile")
            continue;
        Directive directive(tok->location.file(), tok->location.line, "");
        for (const simplecpp::Token *tok2 = tok; tok2 && tok2->location.line == directive.linenr; tok2 = tok2->next) {
            if (tok2->comment)
                continue;
            if (!directive.str.empty() && (tok2->location.col > tok2->previous->location.col + tok2->previous->str.size()))
                directive.str += ' ';
            if (directive.str == "#" && tok2->str == "file")
                directive.str += "include";
            else
                directive.str += tok2->str;
        }
        directives.push_back(directive);
    }

    // ensure that guessed define macros without value are not used in the code
    for (std::list<std::string>::const_iterator defineIt = dui.defines.begin(); defineIt != dui.defines.end(); ++defineIt) {
        if (defineIt->find("=") != std::string::npos)
            continue;
        const std::string macroName = defineIt->substr(0, std::min(defineIt->find("="), defineIt->find("(")));
        for (std::list<simplecpp::MacroUsage>::const_iterator usageIt = macroUsage.begin(); usageIt != macroUsage.end(); ++usageIt) {
            const simplecpp::MacroUsage &mu = *usageIt;
            if (mu.macroName != macroName)
                continue;
            bool directiveLocation = false;
            for (std::list<Directive>::const_iterator dirIt = directives.begin(); dirIt != directives.end(); ++dirIt) {
                if (mu.useLocation.file() == dirIt->file && mu.useLocation.line == dirIt->linenr) {
                    directiveLocation = true;
                    break;
                }
            }
            if (!directiveLocation) {
                if (_settings.isEnabled("information"))
                    validateCfgError(cfg, macroName);
                return "";
            }
        }
    }

    // assembler code locations..
    std::set<simplecpp::Location> assemblerLocations;
    for (std::list<Directive>::const_iterator dirIt = directives.begin(); dirIt != directives.end(); ++dirIt) {
        const Directive &d1 = *dirIt;
        if (d1.str.compare(0, 11, "#pragma asm") != 0)
            continue;
        std::list<Directive>::const_iterator dirIt2 = dirIt;
        ++dirIt2;
        if (dirIt2 == directives.end())
            continue;

        const Directive &d2 = *dirIt2;
        if (d2.str.compare(0,14,"#pragma endasm") != 0 || d1.file != d2.file)
            continue;

        simplecpp::Location loc(files);
        loc.fileIndex = ~0U;
        loc.col = 0U;
        for (unsigned int i = 0; i < files.size(); ++i) {
            if (files[i] == d1.file) {
                loc.fileIndex = i;
                break;
            }
        }

        for (unsigned int linenr = d1.linenr + 1U; linenr < d2.linenr; linenr++) {
            loc.line = linenr;
            assemblerLocations.insert(loc);
        }
    }

    unsigned int prevfile = 0;
    unsigned int line = 1;
    std::ostringstream ret;
    for (const simplecpp::Token *tok = tokens2.cbegin(); tok; tok = tok->next) {
        if (writeLocations && tok->location.fileIndex != prevfile) {
            ret << "\n#line " << tok->location.line << " \"" << tok->location.file() << "\"\n";
            prevfile = tok->location.fileIndex;
            line = tok->location.line;
        }

        if (tok->previous && line == tok->location.line)
            ret << ' ';
        bool newline = false;
        while (tok->location.line > line) {
            ret << '\n';
            line++;
            newline = true;
        }
        if (newline) {
            simplecpp::Location loc = tok->location;
            loc.col = 0U;
            if (assemblerLocations.find(loc) != assemblerLocations.end()) {
                ret << "asm();";
                while (assemblerLocations.find(loc) != assemblerLocations.end()) {
                    loc.line++;
                }
                while (tok && tok->location.line < loc.line)
                    tok = tok->next;
                if (!tok)
                    break;
                while (line < tok->location.line) {
                    ret << '\n';
                    ++line;
                }
            }
        }
        if (!tok->macro.empty())
            ret << Preprocessor::macroChar;
        ret << tok->str;
    }

    return ret.str();
}

std::string Preprocessor::getcode(const std::string &filedata, const std::string &cfg, const std::string &filename)
{
    simplecpp::OutputList outputList;
    std::vector<std::string> files;

    std::istringstream istr(filedata);
    const simplecpp::TokenList &tokens1 = simplecpp::TokenList(istr, files, Path::simplifyPath(filename), &outputList);
    inlineSuppressions(tokens1);

    for (simplecpp::OutputList::const_iterator it = outputList.begin(); it != outputList.end(); ++it) {
        if (it->type == simplecpp::Output::ERROR) {
            error(it->location.file(), it->location.line, it->msg);
            return "";
        }
    }

    return getcode(tokens1, cfg, files, filedata.find("#file") != std::string::npos);
}

void Preprocessor::error(const std::string &filename, unsigned int linenr, const std::string &msg)
{
    std::list<ErrorLogger::ErrorMessage::FileLocation> locationList;
    if (!filename.empty()) {
        ErrorLogger::ErrorMessage::FileLocation loc(filename, linenr);
        locationList.push_back(loc);
    }
    _errorLogger->reportErr(ErrorLogger::ErrorMessage(locationList,
                            Severity::error,
                            msg,
                            "preprocessorErrorDirective",
                            false));
}

Preprocessor::HeaderTypes Preprocessor::getHeaderFileName(std::string &str)
{
    std::string::size_type i = str.find_first_of("<\"");
    if (i == std::string::npos) {
        str = "";
        return NoHeader;
    }

    char c = str[i];
    if (c == '<')
        c = '>';

    std::string result;
    for (i = i + 1; i < str.length(); ++i) {
        if (str[i] == c)
            break;

        result.append(1, str[i]);
    }

    // Linux can't open include paths with \ separator, so fix them
    std::replace(result.begin(), result.end(), '\\', '/');

    str = result;

    return (c == '\"') ? UserHeader : SystemHeader;
}


// Report that include is missing
void Preprocessor::missingInclude(const std::string &filename, unsigned int linenr, const std::string &header, HeaderTypes headerType)
{
    const std::string fname = Path::fromNativeSeparators(filename);
    if (_settings.nomsg.isSuppressed("missingInclude", fname, linenr))
        return;
    if (headerType == SystemHeader && _settings.nomsg.isSuppressed("missingIncludeSystem", fname, linenr))
        return;

    if (headerType == SystemHeader)
        missingSystemIncludeFlag = true;
    else
        missingIncludeFlag = true;
    if (_errorLogger && _settings.checkConfiguration) {

        std::list<ErrorLogger::ErrorMessage::FileLocation> locationList;
        if (!filename.empty()) {
            ErrorLogger::ErrorMessage::FileLocation loc;
            loc.line = linenr;
            loc.setfile(Path::toNativeSeparators(filename));
            locationList.push_back(loc);
        }
        ErrorLogger::ErrorMessage errmsg(locationList, Severity::information,
                                         (headerType==SystemHeader) ?
                                         "Include file: <" + header + "> not found. Please note: Cppcheck does not need standard library headers to get proper results." :
                                         "Include file: \"" + header + "\" not found.",
                                         (headerType==SystemHeader) ? "missingIncludeSystem" : "missingInclude",
                                         false);
        errmsg.file0 = file0;
        _errorLogger->reportInfo(errmsg);
    }
}

bool Preprocessor::validateCfg(const std::string &code, const std::string &cfg)
{
    const bool printInformation = _settings.isEnabled("information");

    // fill up "macros" with empty configuration macros
    std::set<std::string> macros;
    for (std::string::size_type pos = 0; pos < cfg.size();) {
        const std::string::size_type pos2 = cfg.find_first_of(";=", pos);
        if (pos2 == std::string::npos) {
            macros.insert(cfg.substr(pos));
            break;
        }
        if (cfg[pos2] == ';')
            macros.insert(cfg.substr(pos, pos2-pos));
        pos = cfg.find(';', pos2);
        if (pos != std::string::npos)
            ++pos;
    }

    // check if any empty macros are used in code
    for (std::set<std::string>::const_iterator it = macros.begin(); it != macros.end(); ++it) {
        const std::string &macro = *it;
        std::string::size_type pos = 0;
        while ((pos = code.find_first_of(std::string("#\"'")+macro[0], pos)) != std::string::npos) {
            const std::string::size_type pos1 = pos;
            const std::string::size_type pos2 = pos + macro.size();
            pos++;

            // skip string..
            if (code[pos1] == '\"' || code[pos1] == '\'') {
                while (pos < code.size() && code[pos] != code[pos1]) {
                    if (code[pos] == '\\')
                        ++pos;
                    ++pos;
                }
                ++pos;
            }

            // skip preprocessor statement..
            else if (code[pos1] == '#') {
                if (pos1 == 0 || code[pos1-1] == '\n')
                    pos = code.find('\n', pos);
            }

            // is macro used in code?
            else if (code.compare(pos1,macro.size(),macro) == 0) {
                if (pos1 > 0 && (std::isalnum((unsigned char)code[pos1-1U]) || code[pos1-1U] == '_'))
                    continue;
                if (pos2 < code.size() && (std::isalnum((unsigned char)code[pos2]) || code[pos2] == '_'))
                    continue;
                // macro is used in code, return false
                if (printInformation)
                    validateCfgError(cfg, macro);
                return false;
            }
        }
    }

    return true;
}

void Preprocessor::validateCfgError(const std::string &cfg, const std::string &macro)
{
    const std::string id = "ConfigurationNotChecked";
    std::list<ErrorLogger::ErrorMessage::FileLocation> locationList;
    ErrorLogger::ErrorMessage::FileLocation loc(file0, 1);
    locationList.push_back(loc);
    ErrorLogger::ErrorMessage errmsg(locationList, Severity::information, "Skipping configuration '" + cfg + "' since the value of '" + macro + "' is unknown. Use -D if you want to check it. You can use -U to skip it explicitly.", id, false);
    _errorLogger->reportInfo(errmsg);
}

void Preprocessor::getErrorMessages(ErrorLogger *errorLogger, const Settings *settings)
{
    Settings settings2(*settings);
    Preprocessor preprocessor(settings2, errorLogger);
    settings2.checkConfiguration=true;
    preprocessor.missingInclude("", 1, "", UserHeader);
    preprocessor.missingInclude("", 1, "", SystemHeader);
    preprocessor.validateCfgError("X", "X");
    preprocessor.error("", 1, "#error message");   // #error ..
}

void Preprocessor::dump(std::ostream &out) const
{
    // Create a xml directive dump.
    // The idea is not that this will be readable for humans. It's a
    // data dump that 3rd party tools could load and get useful info from.
    std::list<Directive>::const_iterator it;

    out << "  <directivelist>" << std::endl;

    for (it = directives.begin(); it != directives.end(); ++it) {
        out << "    <directive "
            << "file=\"" << it->file << "\" "
            << "linenr=\"" << it->linenr << "\" "
            // str might contain characters such as '"', '<' or '>' which
            // could result in invalid XML, so run it through toxml().
            << "str=\"" << ErrorLogger::toxml(it->str) << "\"/>" << std::endl;
    }
    out << "  </directivelist>" << std::endl;
}
