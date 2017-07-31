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

#if defined(__GNUC__) && (defined(_WIN32) || defined(__CYGWIN__))
#undef __STRICT_ANSI__
#endif
#include "path.h"
#include "utils.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <sstream>

#ifndef _WIN32
#include <unistd.h>
#else
#include <direct.h>
#endif
#if defined(__CYGWIN__)
#include <strings.h>
#endif

#include <simplecpp.h>

/** Is the filesystem case insensitive? */
static bool caseInsensitiveFilesystem()
{
#ifdef _WIN32
    return true;
#else
    // TODO: Non-windows filesystems might be case insensitive
    return false;
#endif
}

std::string Path::toNativeSeparators(std::string path)
{
#if defined(_WIN32)
    const char separ = '/';
    const char native = '\\';
#else
    const char separ = '\\';
    const char native = '/';
#endif
    std::replace(path.begin(), path.end(), separ, native);
    return path;
}

std::string Path::fromNativeSeparators(std::string path)
{
    const char nonnative = '\\';
    const char newsepar = '/';
    std::replace(path.begin(), path.end(), nonnative, newsepar);
    return path;
}

std::string Path::simplifyPath(std::string originalPath)
{
    return simplecpp::simplifyPath(originalPath);
}

std::string Path::getPathFromFilename(const std::string &filename)
{
    const std::size_t pos = filename.find_last_of("\\/");

    if (pos != std::string::npos)
        return filename.substr(0, 1 + pos);

    return "";
}


bool Path::sameFileName(const std::string &fname1, const std::string &fname2)
{
#if defined(__linux__) || defined(__sun) || defined(__hpux)
    return (fname1 == fname2);
#elif defined(_MSC_VER) || (defined(__GNUC__) && defined(_WIN32))
    return (_stricmp(fname1.c_str(), fname2.c_str()) == 0);
#elif defined(__GNUC__)
    return (strcasecmp(fname1.c_str(), fname2.c_str()) == 0);
#elif defined(__BORLANDC__)
    return (stricmp(fname1.c_str(), fname2.c_str()) == 0);
#else
#error Platform filename compare function needed
#endif
}

// This wrapper exists because Sun's CC does not allow a static_cast
// from extern "C" int(*)(int) to int(*)(int).
static int tolowerWrapper(int c)
{
    return std::tolower(c);
}

std::string Path::removeQuotationMarks(std::string path)
{
    path.erase(std::remove(path.begin(), path.end(), '\"'), path.end());
    return path;
}

std::string Path::getFilenameExtension(const std::string &path)
{
    const std::string::size_type dotLocation = path.find_last_of('.');
    if (dotLocation == std::string::npos)
        return "";

    std::string extension = path.substr(dotLocation);
    if (caseInsensitiveFilesystem()) {
        // on a case insensitive filesystem the case doesn't matter so
        // let's return the extension in lowercase
        std::transform(extension.begin(), extension.end(), extension.begin(), tolowerWrapper);
    }
    return extension;
}

std::string Path::getFilenameExtensionInLowerCase(const std::string &path)
{
    std::string extension = getFilenameExtension(path);
    std::transform(extension.begin(), extension.end(), extension.begin(), tolowerWrapper);
    return extension;
}

const std::string Path::getCurrentPath()
{
    char currentPath[4096];

#ifndef _WIN32
    if (getcwd(currentPath, 4096) != 0)
#else
    if (_getcwd(currentPath, 4096) != 0)
#endif
        return std::string(currentPath);

    return emptyString;
}

bool Path::isAbsolute(const std::string& path)
{
    const std::string& nativePath = toNativeSeparators(path);

#ifdef _WIN32
    if (path.length() < 2)
        return false;

    // On Windows, 'C:\foo\bar' is an absolute path, while 'C:foo\bar' is not
    if (nativePath.compare(0, 2, "\\\\") == 0 || (std::isalpha(nativePath[0]) != 0 && nativePath.compare(1, 2, ":\\") == 0))
        return true;
#else
    if (!nativePath.empty() && nativePath[0] == '/')
        return true;
#endif

    return false;
}

std::string Path::getRelativePath(const std::string& absolutePath, const std::vector<std::string>& basePaths)
{
    for (std::vector<std::string>::const_iterator i = basePaths.begin(); i != basePaths.end(); ++i) {
        if (absolutePath == *i || i->empty()) // Seems to be a file, or path is empty
            continue;

        bool endsWithSep = endsWith(*i,'/');
        if (absolutePath.compare(0, i->length(), *i) == 0 && absolutePath[i->length() - (endsWithSep?1:0)] == '/') {
            std::string rest = absolutePath.substr(i->length() + (endsWithSep?0:1));
            return rest;
        }
    }
    return absolutePath;
}

bool Path::isC(const std::string &path)
{
    // In unix, ".C" is considered C++ file
    const std::string extension = getFilenameExtension(path);
    return extension == ".c" ||
           extension == ".cl";
}

bool Path::isCPP(const std::string &path)
{
    const std::string extension = getFilenameExtensionInLowerCase(path);
    return extension == ".cpp" ||
           extension == ".cxx" ||
           extension == ".cc" ||
           extension == ".c++" ||
           extension == ".hpp" ||
           extension == ".hxx" ||
           extension == ".hh" ||
           extension == ".tpp" ||
           extension == ".txx" ||
           getFilenameExtension(path) == ".C"; // In unix, ".C" is considered C++ file
}

bool Path::acceptFile(const std::string &path, const std::set<std::string> &extra)
{
    return !Path::isHeader(path) && (Path::isCPP(path) || Path::isC(path) || extra.find(getFilenameExtension(path)) != extra.end());
}

bool Path::isHeader(const std::string &path)
{
    const std::string extension = getFilenameExtensionInLowerCase(path);
    return (extension.compare(0, 2, ".h") == 0);
}

std::string Path::getAbsoluteFilePath(const std::string& filePath)
{
    std::string absolute_path;
#ifdef _WIN32
    char absolute[_MAX_PATH];
    if (_fullpath(absolute, filePath.c_str(), _MAX_PATH))
        absolute_path = absolute;
#elif defined(__linux__) || defined(__sun) || defined(__hpux) || defined(__GNUC__)
    char * absolute = realpath(filePath.c_str(), nullptr);
    if (absolute)
        absolute_path = absolute;
    free(absolute);
#else
#error Platform absolute path function needed
#endif
    return absolute_path;
}
