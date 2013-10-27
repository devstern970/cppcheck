/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2013 Daniel Marjamäki and Cppcheck team.
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

#include "library.h"
#include "testsuite.h"

class TestLibrary : public TestFixture {
public:
    TestLibrary() : TestFixture("TestLibrary") { }

private:

    void run() {
        TEST_CASE(empty);
        TEST_CASE(function);
        TEST_CASE(memory);
    }

    void empty() {
        const char xmldata[] = "<?xml version=\"1.0\"?>\n<def/>";
        tinyxml2::XMLDocument doc;
        doc.Parse(xmldata, sizeof(xmldata));

        Library library;
        library.load(doc);
        ASSERT(library.use.empty());
        ASSERT(library.leakignore.empty());
        ASSERT(library.argumentChecks.empty());
    }

    void function() {
        const char xmldata[] = "<?xml version=\"1.0\"?>\n"
                               "<def>\n"
                               "  <function name=\"foo\">\n"
                               "    <noreturn>false</noreturn>\n"
                               "  </function>\n"
                               "</def>";
        tinyxml2::XMLDocument doc;
        doc.Parse(xmldata, sizeof(xmldata));

        Library library;
        library.load(doc);
        ASSERT(library.use.empty());
        ASSERT(library.leakignore.empty());
        ASSERT(library.argumentChecks.empty());
        ASSERT(library.isnotnoreturn("foo"));
    }

    void memory() {
        const char xmldata[] = "<?xml version=\"1.0\"?>\n"
                               "<def>\n"
                               "  <memory>\n"
                               "    <alloc>CreateX</alloc>\n"
                               "    <dealloc>DeleteX</dealloc>\n"
                               "  </memory>\n"
                               "</def>";
        tinyxml2::XMLDocument doc;
        doc.Parse(xmldata, sizeof(xmldata));

        Library library;
        library.load(doc);
        ASSERT(library.use.empty());
        ASSERT(library.leakignore.empty());
        ASSERT(library.argumentChecks.empty());

        ASSERT(Library::ismemory(library.alloc("CreateX")));
        ASSERT_EQUALS(library.alloc("CreateX"), library.dealloc("DeleteX"));
    }
};

REGISTER_TEST(TestLibrary)
