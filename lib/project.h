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
#ifndef projectH
#define projectH
//---------------------------------------------------------------------------

#include <list>
#include <string>
#include <set>
#include "config.h"
#include "platform.h"

/// @addtogroup Core
/// @{


/**
 * @brief Project settings.
 */
class CPPCHECKLIB Project {
public:
    /** File settings. Multiple configurations for a file is allowed. */
    struct FileSettings {
        FileSettings() : platformType(Platform::Unspecified) {}
        std::string filename;
        std::string defines;
        std::set<std::string> undefs;
        std::list<std::string> includePaths;
        Platform::PlatformType platformType;
    };
    std::list<FileSettings> fileSettings;

    void load(const std::string &filename);
private:
    void loadCompileCommands(std::istream &istr);
    void loadVcxproj(const std::string &filename);
};

/// @}
//---------------------------------------------------------------------------
#endif // projectH
