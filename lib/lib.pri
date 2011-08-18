# no manual edits - this file is autogenerated by dmake

include($$PWD/pcrerules.pri)
INCLUDEPATH += ../externals/tinyxml
HEADERS += $${BASEPATH}check.h \
           $${BASEPATH}check64bit.h \
           $${BASEPATH}checkassignif.h \
           $${BASEPATH}checkautovariables.h \
           $${BASEPATH}checkbufferoverrun.h \
           $${BASEPATH}checkclass.h \
           $${BASEPATH}checkexceptionsafety.h \
           $${BASEPATH}checkmemoryleak.h \
           $${BASEPATH}checknonreentrantfunctions.h \
           $${BASEPATH}checknullpointer.h \
           $${BASEPATH}checkobsoletefunctions.h \
           $${BASEPATH}checkother.h \
           $${BASEPATH}checkpostfixoperator.h \
           $${BASEPATH}checkstl.h \
           $${BASEPATH}checkuninitvar.h \
           $${BASEPATH}checkunusedfunctions.h \
           $${BASEPATH}cppcheck.h \
           $${BASEPATH}errorlogger.h \
           $${BASEPATH}executionpath.h \
           $${BASEPATH}mathlib.h \
           $${BASEPATH}path.h \
           $${BASEPATH}preprocessor.h \
           $${BASEPATH}settings.h \
           $${BASEPATH}symboldatabase.h \
           $${BASEPATH}timer.h \
           $${BASEPATH}token.h \
           $${BASEPATH}tokenize.h

SOURCES += $${BASEPATH}check64bit.cpp \
           $${BASEPATH}checkassignif.cpp \
           $${BASEPATH}checkautovariables.cpp \
           $${BASEPATH}checkbufferoverrun.cpp \
           $${BASEPATH}checkclass.cpp \
           $${BASEPATH}checkexceptionsafety.cpp \
           $${BASEPATH}checkmemoryleak.cpp \
           $${BASEPATH}checknonreentrantfunctions.cpp \
           $${BASEPATH}checknullpointer.cpp \
           $${BASEPATH}checkobsoletefunctions.cpp \
           $${BASEPATH}checkother.cpp \
           $${BASEPATH}checkpostfixoperator.cpp \
           $${BASEPATH}checkstl.cpp \
           $${BASEPATH}checkuninitvar.cpp \
           $${BASEPATH}checkunusedfunctions.cpp \
           $${BASEPATH}cppcheck.cpp \
           $${BASEPATH}errorlogger.cpp \
           $${BASEPATH}executionpath.cpp \
           $${BASEPATH}mathlib.cpp \
           $${BASEPATH}path.cpp \
           $${BASEPATH}preprocessor.cpp \
           $${BASEPATH}settings.cpp \
           $${BASEPATH}symboldatabase.cpp \
           $${BASEPATH}timer.cpp \
           $${BASEPATH}token.cpp \
           $${BASEPATH}tokenize.cpp
