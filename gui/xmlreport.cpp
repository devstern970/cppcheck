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

#include <QFile>
#include <QXmlStreamWriter>
#include <qdebug>
#include "xmlreport.h"

static const char ResultElementName[] = "results";
static const char ErrorElementName[] = "error";
static const char FilenameAttribute[] = "file";
static const char LineAttribute[] = "line";
static const char IdAttribute[] = "id";
static const char SeverityAttribute[] = "severity";
static const char MsgAttribute[] = "msg";

XmlReport::XmlReport(const QString &filename, QObject * parent) :
    Report(filename, parent),
    mXmlReader(NULL),
    mXmlWriter(NULL)
{
}

XmlReport::~XmlReport()
{
    delete mXmlReader;
    delete mXmlWriter;
    Close();
}

bool XmlReport::Create()
{
    bool success = false;
    if (Report::Create())
    {
        mXmlWriter = new QXmlStreamWriter(Report::GetFile());
        success = true;
    }
    return success;
}

bool XmlReport::Open()
{
    bool success = false;
    if (Report::Open())
    {
        mXmlReader = new QXmlStreamReader(Report::GetFile());
        success = true;
    }
    return success;
}

void XmlReport::WriteHeader()
{
    mXmlWriter->setAutoFormatting(true);
    mXmlWriter->writeStartDocument();
    mXmlWriter->writeStartElement(ResultElementName);
}

void XmlReport::WriteFooter()
{
    mXmlWriter->writeEndElement();
    mXmlWriter->writeEndDocument();
}

void XmlReport::WriteError(const QStringList &files, const QStringList &lines,
                           const QString &id, const QString &severity, const QString &msg)
{
    /*
    Error example from the core program in xml
    <error file="gui/test.cpp" line="14" id="mismatchAllocDealloc" severity="error" msg="Mismatching allocation and deallocation: k"/>
    The callstack seems to be ignored here aswell, instead last item of the stack is used
    */

    mXmlWriter->writeStartElement(ErrorElementName);
    mXmlWriter->writeAttribute(FilenameAttribute, files[files.size() - 1]);
    mXmlWriter->writeAttribute(LineAttribute, lines[lines.size() - 1]);
    mXmlWriter->writeAttribute(IdAttribute, id);
    mXmlWriter->writeAttribute(SeverityAttribute, severity);
    mXmlWriter->writeAttribute(MsgAttribute, msg);
    mXmlWriter->writeEndElement();
}

void XmlReport::Read()
{
    bool insideResults = false;
    if (!mXmlReader)
    {
        qDebug() << "You must Open() the file before reading it!";
        return;
    }
    while (!mXmlReader->atEnd())
    {
        switch (mXmlReader->readNext())
        {
        case QXmlStreamReader::StartElement:
            if (mXmlReader->name() == ResultElementName)
                insideResults = true;

            // Read error element from inside result element
            if (insideResults && mXmlReader->name() == ErrorElementName)
                ReadError(mXmlReader);
            break;

        case QXmlStreamReader::EndElement:
            if (mXmlReader->name() == ResultElementName)
                insideResults = false;
            break;

            // Not handled
        case QXmlStreamReader::NoToken:
        case QXmlStreamReader::Invalid:
        case QXmlStreamReader::StartDocument:
        case QXmlStreamReader::EndDocument:
        case QXmlStreamReader::Characters:
        case QXmlStreamReader::Comment:
        case QXmlStreamReader::DTD:
        case QXmlStreamReader::EntityReference:
        case QXmlStreamReader::ProcessingInstruction:
            break;
        }
    }
}

void XmlReport::ReadError(QXmlStreamReader *reader)
{
    if (reader->name().toString() == ErrorElementName)
    {
        QXmlStreamAttributes attribs = reader->attributes();
        QString filename = attribs.value("", FilenameAttribute).toString();
        QString line = attribs.value("", LineAttribute).toString();
        QString id = attribs.value("", IdAttribute).toString();
        QString severity = attribs.value("", SeverityAttribute).toString();
        QString msg = attribs.value("", MsgAttribute).toString();
        qDebug() << "Error: " << filename << " " << line << " " << id << " " << severity << " " << msg;
    }
}
