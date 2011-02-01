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

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QtGui/QWidget>

namespace Ui
{
class HelpWindow;
}

class QHelpEngine;

/// @addtogroup GUI
/// @{

/**
 * @brief Help Window
 */
class HelpWindow : public QWidget
{
    Q_OBJECT
public:
    HelpWindow(QWidget *parent = 0);
    ~HelpWindow();

    /**
     * load a *.qhc file and setup GUI. the file must exist.
     * @return false if loading failed
     */
    bool load(const QString &helpFile);

private:
    Ui::HelpWindow *m_ui;

    QHelpEngine *helpEngine;
};

#endif // HELPWINDOW_H
