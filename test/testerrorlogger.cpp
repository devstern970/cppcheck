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

#include <list>
#include "cppcheck.h"
#include "testsuite.h"
#include "errorlogger.h"

class TestErrorLogger : public TestFixture
{
public:
    TestErrorLogger() : TestFixture("TestErrorLogger")
    { }

private:

    void run()
    {
        TEST_CASE(FileLocationDefaults);
        TEST_CASE(FileLocationSetFile);
        TEST_CASE(ErrorMessageConstruct);
        TEST_CASE(ErrorMessageVerbose);
        TEST_CASE(CustomFormat);
        TEST_CASE(CustomFormat2);
        TEST_CASE(ToXml);
        TEST_CASE(ToVerboseXml);
        TEST_CASE(ToXmlV2);

        // Inconclusive results in xml reports..
        TEST_CASE(InconclusiveXml);
    }

    void FileLocationDefaults()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        ASSERT_EQUALS("", loc.getfile());
        ASSERT_EQUALS(0, loc.line);
    }

    void FileLocationSetFile()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        ASSERT_EQUALS("foo.cpp", loc.getfile());
        ASSERT_EQUALS(0, loc.line);
    }

    void ErrorMessageConstruct()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.", "errorId", false);
        ASSERT_EQUALS(1, (int)msg._callStack.size());
        ASSERT_EQUALS("Programming error.", msg.shortMessage());
        ASSERT_EQUALS("Programming error.", msg.verboseMessage());
        ASSERT_EQUALS("[foo.cpp:5]: (error) Programming error.", msg.toString(false));
        ASSERT_EQUALS("[foo.cpp:5]: (error) Programming error.", msg.toString(true));
    }

    void ErrorMessageVerbose()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.\nVerbose error", "errorId", false);
        ASSERT_EQUALS(1, (int)msg._callStack.size());
        ASSERT_EQUALS("Programming error.", msg.shortMessage());
        ASSERT_EQUALS("Verbose error", msg.verboseMessage());
        ASSERT_EQUALS("[foo.cpp:5]: (error) Programming error.", msg.toString(false));
        ASSERT_EQUALS("[foo.cpp:5]: (error) Verbose error", msg.toString(true));
    }

    void CustomFormat()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.\nVerbose error", "errorId", false);
        ASSERT_EQUALS(1, (int)msg._callStack.size());
        ASSERT_EQUALS("Programming error.", msg.shortMessage());
        ASSERT_EQUALS("Verbose error", msg.verboseMessage());
        ASSERT_EQUALS("foo.cpp:5,error,errorId,Programming error.", msg.toString(false, "{file}:{line},{severity},{id},{message}"));
        ASSERT_EQUALS("foo.cpp:5,error,errorId,Verbose error", msg.toString(true, "{file}:{line},{severity},{id},{message}"));
    }

    void CustomFormat2()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.\nVerbose error", "errorId", false);
        ASSERT_EQUALS(1, (int)msg._callStack.size());
        ASSERT_EQUALS("Programming error.", msg.shortMessage());
        ASSERT_EQUALS("Verbose error", msg.verboseMessage());
        ASSERT_EQUALS("Programming error. - foo.cpp(5):(error,errorId)", msg.toString(false, "{message} - {file}({line}):({severity},{id})"));
        ASSERT_EQUALS("Verbose error - foo.cpp(5):(error,errorId)", msg.toString(true, "{message} - {file}({line}):({severity},{id})"));
    }

    void ToXml()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.\nVerbose error", "errorId", false);
        ASSERT_EQUALS("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<results>", ErrorLogger::ErrorMessage::getXMLHeader(1));
        ASSERT_EQUALS("</results>", ErrorLogger::ErrorMessage::getXMLFooter(1));
        ASSERT_EQUALS("<error file=\"foo.cpp\" line=\"5\" id=\"errorId\" severity=\"error\" msg=\"Programming error.\"/>", msg.toXML(false,1));
    }

    void ToVerboseXml()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.\nVerbose error", "errorId", false);
        ASSERT_EQUALS("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<results>", ErrorLogger::ErrorMessage::getXMLHeader(1));
        ASSERT_EQUALS("</results>", ErrorLogger::ErrorMessage::getXMLFooter(1));
        ASSERT_EQUALS("<error file=\"foo.cpp\" line=\"5\" id=\"errorId\" severity=\"error\" msg=\"Verbose error\"/>", msg.toXML(true,1));
    }

    void ToXmlV2()
    {
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);
        ErrorMessage msg(locs, Severity::error, "Programming error.\nVerbose error", "errorId", false);
        std::string header("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<results version=\"2\">\n");
        header += "  <cppcheck version=\"";
        header += CppCheck::version();
        header += "\"/>\n  <errors>";
        ASSERT_EQUALS(header, ErrorLogger::ErrorMessage::getXMLHeader(2));
        ASSERT_EQUALS("  </errors>\n</results>", ErrorLogger::ErrorMessage::getXMLFooter(2));
        std::string message("  <error id=\"errorId\" severity=\"error\"");
        message += " msg=\"Programming error.\" verbose=\"Verbose error\">\n";
        message += "    <location file=\"foo.cpp\" line=\"5\"/>\n  </error>";
        ASSERT_EQUALS(message, msg.toXML(false,2));
    }

    void InconclusiveXml()
    {
        // Location
        ErrorLogger::ErrorMessage::FileLocation loc;
        loc.setfile("foo.cpp");
        loc.line = 5;
        std::list<ErrorLogger::ErrorMessage::FileLocation> locs;
        locs.push_back(loc);

        // Inconclusive error message
        ErrorMessage msg(locs, Severity::error, "Programming error", "errorId", true);

        // Don't save inconclusive messages if the xml version is 1
        ASSERT_EQUALS("", msg.toXML(false, 1));

        // TODO: how should inconclusive messages be saved when the xml version is 2?
        ASSERT_EQUALS("", msg.toXML(false, 2));
    }
};
REGISTER_TEST(TestErrorLogger)
