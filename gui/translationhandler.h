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

#ifndef TRANSLATIONHANDLER_H
#define TRANSLATIONHANDLER_H

#include <QStringList>
#include <QTranslator>
#include <QObject>
#include <QList>

/// @addtogroup GUI
/// @{

struct TranslationInfo
{
    QString mName;
    QString mFilename;
    QString mCode;
};


class TranslationHandler : QObject
{
    Q_OBJECT
public:
    TranslationHandler(QObject *parent);
    virtual ~TranslationHandler();
    const QStringList GetNames() const;
    QList<TranslationInfo> GetTranslations() const
    {
        return mTranslations;
    }
    bool SetLanguage(const QString &code, QString &error);
    QString GetCurrentLanguage() const;
    QString SuggestLanguage() const;
protected:
    void AddTranslation(const char *name, const char *filename);
    int GetLanguageIndexByCode(const QString &code) const;

    QString mCurrentLanguage;
    QList<TranslationInfo> mTranslations;
    QTranslator *mTranslator;
private:
};
/// @}
#endif // TRANSLATIONHANDLER_H
