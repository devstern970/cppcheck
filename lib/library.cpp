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
#include "tinyxml2.h"

Library::Library() : allocid(0)
{
    while (!ismemory(++allocid));
    _alloc["malloc"] = allocid;
    _alloc["calloc"] = allocid;
    _alloc["strdup"] = allocid;
    _alloc["strndup"] = allocid;
    _dealloc["free"] = allocid;

    while (!isresource(++allocid));
    _alloc["fopen"] = allocid;
    _dealloc["fclose"] = allocid;
}

Library::Library(const Library &lib) :
    use(lib.use),
    ignore(lib.ignore),
    argumentChecks(lib.argumentChecks),
    returnuninitdata(lib.returnuninitdata),
    allocid(lib.allocid),
    _alloc(lib._alloc),
    _dealloc(lib._dealloc),
    _noreturn(lib._noreturn)
{

}

Library::~Library() { }

bool Library::load(const char exename[], const char path[])
{
    tinyxml2::XMLDocument doc;

    if (std::strchr(path,',') != NULL) {
        bool ret = true;
        std::string p(path);
        while (p.find(",") != std::string::npos) {
            const std::string::size_type pos = p.find(",");
            ret &= load(exename, p.substr(0,pos).c_str());
            p = p.substr(pos+1);
        }
        if (!p.empty())
            ret &= load(exename, p.c_str());
        return ret;
    }

    FILE *fp = fopen(path, "rt");
    if (fp == NULL) {
        std::string fullpath(exename);
        if (fullpath.find_first_of("/\\") != std::string::npos)
            fullpath = fullpath.substr(0, 1U + fullpath.find_last_of("/\\"));
        fullpath += path;
        fp = fopen(fullpath.c_str(), "rt");
        if (fp == NULL) {
            fullpath += ".cfg";
            fp = fopen(fullpath.c_str(), "rt");
            if (fp == NULL)
                return false;
        }
    }

    if (doc.LoadFile(fp) != tinyxml2::XML_NO_ERROR)
        return false;

    const tinyxml2::XMLElement * const rootnode = doc.FirstChildElement();
    if (strcmp(rootnode->Name(),"def") != 0)
        return false;

    for (const tinyxml2::XMLElement *node = rootnode->FirstChildElement(); node; node = node->NextSiblingElement()) {
        if (strcmp(node->Name(),"memory")==0) {
            while (!ismemory(++allocid));
            for (const tinyxml2::XMLElement *memorynode = node->FirstChildElement(); memorynode; memorynode = memorynode->NextSiblingElement()) {
                if (strcmp(memorynode->Name(),"alloc")==0) {
                    _alloc[memorynode->GetText()] = allocid;
                    const char *init = memorynode->Attribute("init");
                    if (init && strcmp(init,"false")==0) {
                        returnuninitdata.insert(memorynode->GetText());
                    }
                } else if (strcmp(memorynode->Name(),"dealloc")==0)
                    _dealloc[memorynode->GetText()] = allocid;
                else if (strcmp(memorynode->Name(),"use")==0)
                    use.insert(memorynode->GetText());
                else
                    return false;
            }
        }

        else if (strcmp(node->Name(),"function")==0) {
            const char *name = node->Attribute("name");
            if (name == NULL)
                return false;

            for (const tinyxml2::XMLElement *functionnode = node->FirstChildElement(); functionnode; functionnode = functionnode->NextSiblingElement()) {
                if (strcmp(functionnode->Name(),"noreturn")==0)
                    _noreturn[name] = (strcmp(functionnode->GetText(), "true") == 0);
                else if (strcmp(functionnode->Name(),"leak-ignore")==0)
                    leakignore.insert(name);
                else if (strcmp(functionnode->Name(),"arg")==0 && functionnode->Attribute("nr") != NULL) {
                    const int nr = atoi(functionnode->Attribute("nr"));
                    bool notnull = false;
                    bool notuninit = false;
                    for (const tinyxml2::XMLElement *argnode = functionnode->FirstChildElement(); argnode; argnode = argnode->NextSiblingElement()) {
                        if (strcmp(argnode->Name(), "not-null") == 0)
                            notnull = true;
                        else if (strcmp(argnode->Name(), "not-uninit") == 0)
                            notuninit = true;
                        else
                            return false;
                    }
                    argumentChecks[name][nr].notnull = notnull;
                    argumentChecks[name][nr].notuninit = notuninit;
                } else
                    return false;
            }
        } else
            return false;
    }
    return true;
}
