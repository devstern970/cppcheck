TEMPLATE = app
TARGET = test-projectfile
DEPENDPATH += .
INCLUDEPATH += .
OBJECTS_DIR = ../build
MOC_DIR = ../build

include(../common.pri)

# tests
SOURCES += testprojectfile.cpp \
    ../../projectfile.cpp

HEADERS += testprojectfile.h \
    ../../projectfile.h
