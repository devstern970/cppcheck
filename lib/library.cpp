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
#include "path.h"
#include "tinyxml2.h"

#include <string>
#include <algorithm>

Library::Library() : allocid(0)
{
}

bool Library::load(const char exename[], const char path[])
{
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

    // open file..
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.LoadFile(path);
    if (error == tinyxml2::XML_ERROR_FILE_NOT_FOUND) {
        // failed to open file.. is there no extension?
        std::string fullfilename(path);
        if (Path::getFilenameExtension(fullfilename) == "") {
            fullfilename += ".cfg";
            error = doc.LoadFile(fullfilename.c_str());
        }

        if (error == tinyxml2::XML_ERROR_FILE_NOT_FOUND) {
            // Try to locate the library configuration in the installation folder..
            const std::string installfolder = Path::fromNativeSeparators(Path::getPathFromFilename(exename));
            const std::string filename = installfolder + "cfg/" + fullfilename;
            error = doc.LoadFile(filename.c_str());
        }
    }

    return (error == tinyxml2::XML_NO_ERROR) && load(doc);
}

bool Library::load(const tinyxml2::XMLDocument &doc)
{
    const tinyxml2::XMLElement * const rootnode = doc.FirstChildElement();

    if (rootnode == NULL)
        return false;

    if (strcmp(rootnode->Name(),"def") != 0)
        return false;

    for (const tinyxml2::XMLElement *node = rootnode->FirstChildElement(); node; node = node->NextSiblingElement()) {
        if (strcmp(node->Name(),"memory")==0 || strcmp(node->Name(),"resource")==0) {
            if (strcmp(node->Name(), "memory")==0)
                while (!ismemory(++allocid));
            else
                while (!isresource(++allocid));
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
                else if (strcmp(functionnode->Name(), "arg") == 0 && functionnode->Attribute("nr") != NULL) {
                    const int nr = atoi(functionnode->Attribute("nr"));
                    bool notnull = false;
                    bool notuninit = false;
                    bool formatstr = false;
                    bool strz = false;
                    std::string valid;
                    for (const tinyxml2::XMLElement *argnode = functionnode->FirstChildElement(); argnode; argnode = argnode->NextSiblingElement()) {
                        if (strcmp(argnode->Name(), "not-null") == 0)
                            notnull = true;
                        else if (strcmp(argnode->Name(), "not-uninit") == 0)
                            notuninit = true;
                        else if (strcmp(argnode->Name(), "formatstr") == 0)
                            formatstr = true;
                        else if (strcmp(argnode->Name(), "strz") == 0)
                            strz = true;
                        else if (strcmp(argnode->Name(), "valid") == 0) {
                            // Validate the validation expression
                            const char *p = argnode->GetText();
                            if (!std::isdigit(*p))
                                return false;
                            for (; *p; p++) {
                                if (std::isdigit(*p))
                                    continue;
                                if (*p == '-' && std::isdigit(*(p-1)))
                                    continue;
                                if (*p == ',' && *(p+1) != ',')
                                    continue;
                                return false;
                            }

                            // Set validation expression
                            valid = argnode->GetText();
                        }

                        else
                            return false;
                    }
                    argumentChecks[name][nr].notnull   = notnull;
                    argumentChecks[name][nr].notuninit = notuninit;
                    argumentChecks[name][nr].formatstr = formatstr;
                    argumentChecks[name][nr].strz      = strz;
                    argumentChecks[name][nr].valid     = valid;
                } else if (strcmp(functionnode->Name(), "ignorefunction") == 0) {
                    _ignorefunction[name] = (strcmp(functionnode->GetText(), "true") == 0);
                } else
                    return false;
            }
        }

        else if (strcmp(node->Name(), "markup") == 0) {
            const char * const extension = node->Attribute("ext");
            if (!extension)
                return false;
            _markupExtensions.insert(extension);

            const char * const reporterrors = node->Attribute("reporterrors");
            _reporterrors[extension] = (reporterrors && strcmp(reporterrors, "true") == 0);

            for (const tinyxml2::XMLElement *markupnode = node->FirstChildElement(); markupnode; markupnode = markupnode->NextSiblingElement()) {
                if (strcmp(markupnode->Name(), "keywords") == 0) {
                    for (const tinyxml2::XMLElement *librarynode = markupnode->FirstChildElement(); librarynode; librarynode = librarynode->NextSiblingElement()) {
                        if (strcmp(librarynode->Name(), "keyword") == 0)
                            _keywords[extension].insert(librarynode->Attribute("name"));
                        else
                            return false;
                    }
                }

                else if (strcmp(markupnode->Name(), "exported") == 0) {
                    for (const tinyxml2::XMLElement *exporter = node->FirstChildElement(); exporter; exporter = exporter->NextSiblingElement()) {
                        if (strcmp(exporter->Name(), "exporter") != 0)
                            return false;

                        const char * const prefix = exporter->Attribute("prefix");
                        if (!prefix)
                            return false;

                        for (const tinyxml2::XMLElement *e = exporter->FirstChildElement(); e; e = e->NextSiblingElement()) {
                            if (strcmp(e->Name(), "prefix") == 0)
                                _exporters[prefix].addPrefix(e->GetText());
                            else if (strcmp(e->Name(), "suffix") == 0)
                                _exporters[prefix].addSuffix(e->GetText());
                            else
                                return false;
                        }
                    }
                }

                else if (strcmp(markupnode->Name(), "imported") == 0) {
                    for (const tinyxml2::XMLElement *librarynode = markupnode->FirstChildElement(); librarynode; librarynode = librarynode->NextSiblingElement()) {
                        if (strcmp(librarynode->Name(), "importer") == 0)
                            _importers[extension].insert(librarynode->GetText());
                        else
                            return false;
                    }
                }

                else if (strcmp(markupnode->Name(), "reflection") == 0) {
                    for (const tinyxml2::XMLElement *reflectionnode = markupnode->FirstChildElement(); reflectionnode; reflectionnode = reflectionnode->NextSiblingElement()) {
                        if (strcmp(reflectionnode->Name(), "call") != 0)
                            return false;

                        const char * const argString = reflectionnode->Attribute("arg");
                        if (!argString)
                            return false;

                        _reflection[extension][reflectionnode->GetText()] = atoi(argString);
                    }
                }

                else if (strcmp(markupnode->Name(), "codeblocks") == 0) {
                    for (const tinyxml2::XMLElement *blocknode = blocknode->FirstChildElement(); blocknode; blocknode = blocknode->NextSiblingElement()) {
                        if (strcmp(blocknode->Name(), "block") == 0)
                            _executableblocks[extension].addBlock(blocknode->Attribute("name"));

                        else if (strcmp(blocknode->Name(), "structure") == 0) {
                            const char * start = blocknode->Attribute("start");
                            if (start)
                                _executableblocks[extension].setStart(start);
                            const char * end = blocknode->Attribute("end");
                            if (end)
                                _executableblocks[extension].setEnd(end);
                            const char * offset = blocknode->Attribute("offset");
                            if (offset)
                                _executableblocks[extension].setOffset(atoi(offset));
                        }

                        else
                            return false;
                    }
                }

                else
                    return false;
            }
        }

        else
            return false;
    }
    return true;
}
