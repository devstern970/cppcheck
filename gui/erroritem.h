/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2010 Daniel Marjamäki and Cppcheck team.
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

#ifndef ERRORITEM_H
#define ERRORITEM_H

#include <QString>
#include <QStringList>
#include <QMetaType>

class ErrorLine;

/// @addtogroup GUI
/// @{

/**
* @brief A class containing error data for one error.
*
* The paths are stored with internal ("/") separators. Only when we show the
* path or copy if for user (to clipboard) we convert to native separators.
* Full path is stored instead of relative path for flexibility. It is easy
* to get the relative path from full path when needed.
*/
class ErrorItem
{
public:
    ErrorItem() { }
    ErrorItem(const ErrorItem &item);
    ErrorItem(const ErrorLine &line);
    ~ErrorItem() { }

    /**
    * @brief Convert error item to string.
    * @return Error item as string.
    */
    QString ToString() const;

    QString file;
    QStringList files;
    QList<unsigned int> lines;
    QString id;
    QString severity;
    QString summary;
    QString message;
};

Q_DECLARE_METATYPE(ErrorItem);

/**
* @brief A class containing error data for one shown error line.
*/
class ErrorLine
{
public:
    QString file;
    unsigned int line;
    QString id;
    QString severity;
    QString summary;
    QString message;
};

/// @}
#endif // ERRORITEM_H
