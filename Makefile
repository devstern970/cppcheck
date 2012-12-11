# This file is generated by tools/dmake, do not edit.

# To compile with rules, use 'make HAVE_RULES=yes'
ifndef HAVE_RULES
    HAVE_RULES=no
endif

# folder where lib/*.cpp files are located
ifndef SRCDIR
    SRCDIR=lib
endif

ifeq ($(SRCDIR),build)
    matchcompiler_S := $(shell python tools/matchcompiler.py)
endif

# Set the CPPCHK_GLIBCXX_DEBUG flag. This flag is not used in release Makefiles.
# The _GLIBCXX_DEBUG define doesn't work in Cygwin or other Win32 systems.
ifndef COMSPEC
    ifdef ComSpec
        #### ComSpec is defined on some WIN32's.
        COMSPEC=$(ComSpec)
    endif # ComSpec
endif # COMSPEC

ifdef COMSPEC
    #### Maybe Windows
    ifndef CPPCHK_GLIBCXX_DEBUG
        CPPCHK_GLIBCXX_DEBUG=
    endif # !CPPCHK_GLIBCXX_DEBUG
else # !COMSPEC
    uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

    ifeq ($(uname_S),Linux)
        ifndef CPPCHK_GLIBCXX_DEBUG
            CPPCHK_GLIBCXX_DEBUG=-D_GLIBCXX_DEBUG
        endif # !CPPCHK_GLIBCXX_DEBUG
    endif # Linux

    ifeq ($(uname_S),GNU/kFreeBSD)
        ifndef CPPCHK_GLIBCXX_DEBUG
            CPPCHK_GLIBCXX_DEBUG=-D_GLIBCXX_DEBUG
        endif # !CPPCHK_GLIBCXX_DEBUG
    endif # GNU/kFreeBSD

endif # COMSPEC

ifndef CXXFLAGS
    CXXFLAGS=-pedantic -Wall -Wextra -Wabi -Wcast-qual -Wconversion -Wfloat-equal -Winline -Wmissing-declarations -Wmissing-format-attribute -Wno-long-long -Woverloaded-virtual -Wpacked -Wredundant-decls -Wshadow -Wsign-promo $(CPPCHK_GLIBCXX_DEBUG) -g
endif

ifeq ($(HAVE_RULES),yes)
    CXXFLAGS += -DHAVE_RULES -DTIXML_USE_STL $(shell pcre-config --cflags)
    ifdef LIBS
        LIBS += $(shell pcre-config --libs)
    else
        LIBS=$(shell pcre-config --libs)
    endif
endif

ifndef CXX
    CXX=g++
endif

ifndef PREFIX
    PREFIX=/usr
endif

ifndef INCLUDE_FOR_LIB
    INCLUDE_FOR_LIB=-Ilib
endif

ifndef INCLUDE_FOR_CLI
    INCLUDE_FOR_CLI=-Ilib -Iexternals -Iexternals/tinyxml
endif

ifndef INCLUDE_FOR_TEST
    INCLUDE_FOR_TEST=-Ilib -Icli -Iexternals -Iexternals/tinyxml
endif

BIN=$(DESTDIR)$(PREFIX)/bin

# For 'make man': sudo apt-get install xsltproc docbook-xsl docbook-xml on Linux
DB2MAN=/usr/share/sgml/docbook/stylesheet/xsl/nwalsh/manpages/docbook.xsl
XP=xsltproc -''-nonet -''-param man.charmap.use.subset "0"
MAN_SOURCE=man/cppcheck.1.xml


###### Object Files

LIBOBJ =      $(SRCDIR)/check64bit.o \
              $(SRCDIR)/checkassignif.o \
              $(SRCDIR)/checkautovariables.o \
              $(SRCDIR)/checkboost.o \
              $(SRCDIR)/checkbufferoverrun.o \
              $(SRCDIR)/checkclass.o \
              $(SRCDIR)/checkexceptionsafety.o \
              $(SRCDIR)/checkinternal.o \
              $(SRCDIR)/checkio.o \
              $(SRCDIR)/checkleakautovar.o \
              $(SRCDIR)/checkmemoryleak.o \
              $(SRCDIR)/checknonreentrantfunctions.o \
              $(SRCDIR)/checknullpointer.o \
              $(SRCDIR)/checkobsoletefunctions.o \
              $(SRCDIR)/checkother.o \
              $(SRCDIR)/checkpostfixoperator.o \
              $(SRCDIR)/checkstl.o \
              $(SRCDIR)/checkuninitvar.o \
              $(SRCDIR)/checkunusedfunctions.o \
              $(SRCDIR)/checkunusedvar.o \
              $(SRCDIR)/cppcheck.o \
              $(SRCDIR)/errorlogger.o \
              $(SRCDIR)/executionpath.o \
              $(SRCDIR)/mathlib.o \
              $(SRCDIR)/path.o \
              $(SRCDIR)/preprocessor.o \
              $(SRCDIR)/settings.o \
              $(SRCDIR)/suppressions.o \
              $(SRCDIR)/symboldatabase.o \
              $(SRCDIR)/templatesimplifier.o \
              $(SRCDIR)/timer.o \
              $(SRCDIR)/token.o \
              $(SRCDIR)/tokenize.o \
              $(SRCDIR)/tokenlist.o

CLIOBJ =      cli/cmdlineparser.o \
              cli/cppcheckexecutor.o \
              cli/filelister.o \
              cli/main.o \
              cli/pathmatch.o \
              cli/threadexecutor.o

TESTOBJ =     test/options.o \
              test/test64bit.o \
              test/testassignif.o \
              test/testautovariables.o \
              test/testboost.o \
              test/testbufferoverrun.o \
              test/testcharvar.o \
              test/testclass.o \
              test/testcmdlineparser.o \
              test/testconstructors.o \
              test/testcppcheck.o \
              test/testdivision.o \
              test/testerrorlogger.o \
              test/testexceptionsafety.o \
              test/testfilelister.o \
              test/testincompletestatement.o \
              test/testinternal.o \
              test/testio.o \
              test/testleakautovar.o \
              test/testmathlib.o \
              test/testmemleak.o \
              test/testnonreentrantfunctions.o \
              test/testnullpointer.o \
              test/testobsoletefunctions.o \
              test/testoptions.o \
              test/testother.o \
              test/testpath.o \
              test/testpathmatch.o \
              test/testpostfixoperator.o \
              test/testpreprocessor.o \
              test/testrunner.o \
              test/testsimplifytokens.o \
              test/teststl.o \
              test/testsuite.o \
              test/testsuppressions.o \
              test/testsymboldatabase.o \
              test/testthreadexecutor.o \
              test/testtimer.o \
              test/testtoken.o \
              test/testtokenize.o \
              test/testuninitvar.o \
              test/testunusedfunctions.o \
              test/testunusedprivfunc.o \
              test/testunusedvar.o

ifndef TINYXML
    TINYXML = externals/tinyxml/tinystr.o \
              externals/tinyxml/tinyxml.o \
              externals/tinyxml/tinyxmlerror.o \
              externals/tinyxml/tinyxmlparser.o
endif


EXTOBJ += $(TINYXML)

###### Targets

cppcheck: $(LIBOBJ) $(CLIOBJ) $(EXTOBJ)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o cppcheck $(CLIOBJ) $(LIBOBJ) $(EXTOBJ) $(LIBS) $(LDFLAGS)

all:	cppcheck testrunner

testrunner: $(TESTOBJ) $(LIBOBJ) $(EXTOBJ) cli/threadexecutor.o cli/cmdlineparser.o cli/cppcheckexecutor.o cli/filelister.o cli/pathmatch.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o testrunner $(TESTOBJ) $(LIBOBJ) cli/threadexecutor.o cli/cppcheckexecutor.o cli/cmdlineparser.o cli/filelister.o cli/pathmatch.o $(EXTOBJ) $(LIBS) $(LDFLAGS)

test:	all
	./testrunner

check:	all
	./testrunner -g -q

dmake:	tools/dmake.cpp
	$(CXX) -o dmake tools/dmake.cpp cli/filelister.cpp lib/path.cpp -Ilib

clean:
	rm -f build/*.o lib/*.o cli/*.o test/*.o externals/tinyxml/*.o testrunner cppcheck cppcheck.1

man:	man/cppcheck.1

man/cppcheck.1:	$(MAN_SOURCE)

	$(XP) $(DB2MAN) $(MAN_SOURCE)

tags:
	ctags -R --exclude=doxyoutput .

install: cppcheck
	install -d ${BIN}
	install cppcheck ${BIN}


###### Build

$(SRCDIR)/check64bit.o: lib/check64bit.cpp lib/check64bit.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/check64bit.o $(SRCDIR)/check64bit.cpp

$(SRCDIR)/checkassignif.o: lib/checkassignif.cpp lib/checkassignif.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/mathlib.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkassignif.o $(SRCDIR)/checkassignif.cpp

$(SRCDIR)/checkautovariables.o: lib/checkautovariables.cpp lib/checkautovariables.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkautovariables.o $(SRCDIR)/checkautovariables.cpp

$(SRCDIR)/checkboost.o: lib/checkboost.cpp lib/checkboost.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkboost.o $(SRCDIR)/checkboost.cpp

$(SRCDIR)/checkbufferoverrun.o: lib/checkbufferoverrun.cpp lib/checkbufferoverrun.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/mathlib.h lib/symboldatabase.h lib/executionpath.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkbufferoverrun.o $(SRCDIR)/checkbufferoverrun.cpp

$(SRCDIR)/checkclass.o: lib/checkclass.cpp lib/checkclass.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkclass.o $(SRCDIR)/checkclass.cpp

$(SRCDIR)/checkexceptionsafety.o: lib/checkexceptionsafety.cpp lib/checkexceptionsafety.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkexceptionsafety.o $(SRCDIR)/checkexceptionsafety.cpp

$(SRCDIR)/checkinternal.o: lib/checkinternal.cpp lib/checkinternal.h lib/check.h lib/config.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkinternal.o $(SRCDIR)/checkinternal.cpp

$(SRCDIR)/checkio.o: lib/checkio.cpp lib/checkio.h lib/check.h lib/config.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkio.o $(SRCDIR)/checkio.cpp

$(SRCDIR)/checkleakautovar.o: lib/checkleakautovar.cpp lib/checkleakautovar.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/checkmemoryleak.h lib/checkother.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkleakautovar.o $(SRCDIR)/checkleakautovar.cpp

$(SRCDIR)/checkmemoryleak.o: lib/checkmemoryleak.cpp lib/checkmemoryleak.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h lib/checkuninitvar.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkmemoryleak.o $(SRCDIR)/checkmemoryleak.cpp

$(SRCDIR)/checknonreentrantfunctions.o: lib/checknonreentrantfunctions.cpp lib/checknonreentrantfunctions.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checknonreentrantfunctions.o $(SRCDIR)/checknonreentrantfunctions.cpp

$(SRCDIR)/checknullpointer.o: lib/checknullpointer.cpp lib/checknullpointer.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/executionpath.h lib/mathlib.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checknullpointer.o $(SRCDIR)/checknullpointer.cpp

$(SRCDIR)/checkobsoletefunctions.o: lib/checkobsoletefunctions.cpp lib/checkobsoletefunctions.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkobsoletefunctions.o $(SRCDIR)/checkobsoletefunctions.cpp

$(SRCDIR)/checkother.o: lib/checkother.cpp lib/checkother.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/mathlib.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkother.o $(SRCDIR)/checkother.cpp

$(SRCDIR)/checkpostfixoperator.o: lib/checkpostfixoperator.cpp lib/checkpostfixoperator.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkpostfixoperator.o $(SRCDIR)/checkpostfixoperator.cpp

$(SRCDIR)/checkstl.o: lib/checkstl.cpp lib/checkstl.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/executionpath.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkstl.o $(SRCDIR)/checkstl.cpp

$(SRCDIR)/checkuninitvar.o: lib/checkuninitvar.cpp lib/checkuninitvar.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/mathlib.h lib/executionpath.h lib/checknullpointer.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkuninitvar.o $(SRCDIR)/checkuninitvar.cpp

$(SRCDIR)/checkunusedfunctions.o: lib/checkunusedfunctions.cpp lib/checkunusedfunctions.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkunusedfunctions.o $(SRCDIR)/checkunusedfunctions.cpp

$(SRCDIR)/checkunusedvar.o: lib/checkunusedvar.cpp lib/checkunusedvar.h lib/config.h lib/check.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/checkunusedvar.o $(SRCDIR)/checkunusedvar.cpp

$(SRCDIR)/cppcheck.o: lib/cppcheck.cpp lib/cppcheck.h lib/config.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h lib/preprocessor.h lib/path.h lib/timer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/cppcheck.o $(SRCDIR)/cppcheck.cpp

$(SRCDIR)/errorlogger.o: lib/errorlogger.cpp lib/errorlogger.h lib/config.h lib/suppressions.h lib/path.h lib/cppcheck.h lib/settings.h lib/standards.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/errorlogger.o $(SRCDIR)/errorlogger.cpp

$(SRCDIR)/executionpath.o: lib/executionpath.cpp lib/executionpath.h lib/config.h lib/token.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/executionpath.o $(SRCDIR)/executionpath.cpp

$(SRCDIR)/mathlib.o: lib/mathlib.cpp lib/mathlib.h lib/config.h lib/errorlogger.h lib/suppressions.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/mathlib.o $(SRCDIR)/mathlib.cpp

$(SRCDIR)/path.o: lib/path.cpp lib/path.h lib/config.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/path.o $(SRCDIR)/path.cpp

$(SRCDIR)/preprocessor.o: lib/preprocessor.cpp lib/preprocessor.h lib/config.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/token.h lib/path.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/preprocessor.o $(SRCDIR)/preprocessor.cpp

$(SRCDIR)/settings.o: lib/settings.cpp lib/settings.h lib/config.h lib/suppressions.h lib/standards.h lib/path.h lib/preprocessor.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/settings.o $(SRCDIR)/settings.cpp

$(SRCDIR)/suppressions.o: lib/suppressions.cpp lib/suppressions.h lib/config.h lib/settings.h lib/standards.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/suppressions.o $(SRCDIR)/suppressions.cpp

$(SRCDIR)/symboldatabase.o: lib/symboldatabase.cpp lib/symboldatabase.h lib/config.h lib/token.h lib/mathlib.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h lib/check.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/symboldatabase.o $(SRCDIR)/symboldatabase.cpp

$(SRCDIR)/templatesimplifier.o: lib/templatesimplifier.cpp lib/templatesimplifier.h lib/config.h lib/mathlib.h lib/token.h lib/tokenlist.h lib/errorlogger.h lib/suppressions.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/templatesimplifier.o $(SRCDIR)/templatesimplifier.cpp

$(SRCDIR)/timer.o: lib/timer.cpp lib/timer.h lib/config.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/timer.o $(SRCDIR)/timer.cpp

$(SRCDIR)/token.o: lib/token.cpp lib/token.h lib/config.h lib/errorlogger.h lib/suppressions.h lib/check.h lib/tokenize.h lib/tokenlist.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/token.o $(SRCDIR)/token.cpp

$(SRCDIR)/tokenize.o: lib/tokenize.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/mathlib.h lib/settings.h lib/standards.h lib/check.h lib/token.h lib/path.h lib/symboldatabase.h lib/templatesimplifier.h lib/timer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/tokenize.o $(SRCDIR)/tokenize.cpp

$(SRCDIR)/tokenlist.o: lib/tokenlist.cpp lib/tokenlist.h lib/config.h lib/token.h lib/mathlib.h lib/path.h lib/preprocessor.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o $(SRCDIR)/tokenlist.o $(SRCDIR)/tokenlist.cpp

cli/cmdlineparser.o: cli/cmdlineparser.cpp lib/cppcheck.h lib/config.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h lib/timer.h cli/cmdlineparser.h lib/path.h cli/filelister.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/cmdlineparser.o cli/cmdlineparser.cpp

cli/cppcheckexecutor.o: cli/cppcheckexecutor.cpp cli/cppcheckexecutor.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/cppcheck.h lib/settings.h lib/standards.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h cli/threadexecutor.h lib/preprocessor.h cli/cmdlineparser.h cli/filelister.h lib/path.h cli/pathmatch.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/cppcheckexecutor.o cli/cppcheckexecutor.cpp

cli/filelister.o: cli/filelister.cpp cli/filelister.h lib/path.h lib/config.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/filelister.o cli/filelister.cpp

cli/main.o: cli/main.cpp cli/cppcheckexecutor.h lib/errorlogger.h lib/config.h lib/suppressions.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/main.o cli/main.cpp

cli/pathmatch.o: cli/pathmatch.cpp cli/pathmatch.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/pathmatch.o cli/pathmatch.cpp

cli/threadexecutor.o: cli/threadexecutor.cpp cli/cppcheckexecutor.h lib/errorlogger.h lib/config.h lib/suppressions.h cli/threadexecutor.h lib/cppcheck.h lib/settings.h lib/standards.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/threadexecutor.o cli/threadexecutor.cpp

test/options.o: test/options.cpp test/options.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/options.o test/options.cpp

test/test64bit.o: test/test64bit.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/check64bit.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/test64bit.o test/test64bit.cpp

test/testassignif.o: test/testassignif.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkassignif.h lib/check.h lib/token.h lib/settings.h lib/standards.h lib/mathlib.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testassignif.o test/testassignif.cpp

test/testautovariables.o: test/testautovariables.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkautovariables.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testautovariables.o test/testautovariables.cpp

test/testboost.o: test/testboost.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkboost.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testboost.o test/testboost.cpp

test/testbufferoverrun.o: test/testbufferoverrun.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkbufferoverrun.h lib/check.h lib/token.h lib/settings.h lib/standards.h lib/mathlib.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testbufferoverrun.o test/testbufferoverrun.cpp

test/testcharvar.o: test/testcharvar.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testcharvar.o test/testcharvar.cpp

test/testclass.o: test/testclass.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkclass.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testclass.o test/testclass.cpp

test/testcmdlineparser.o: test/testcmdlineparser.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testcmdlineparser.o test/testcmdlineparser.cpp

test/testconstructors.o: test/testconstructors.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkclass.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testconstructors.o test/testconstructors.cpp

test/testcppcheck.o: test/testcppcheck.cpp lib/cppcheck.h lib/config.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h test/testsuite.h test/redirect.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testcppcheck.o test/testcppcheck.cpp

test/testdivision.o: test/testdivision.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testdivision.o test/testdivision.cpp

test/testerrorlogger.o: test/testerrorlogger.cpp lib/cppcheck.h lib/config.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testerrorlogger.o test/testerrorlogger.cpp

test/testexceptionsafety.o: test/testexceptionsafety.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkexceptionsafety.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testexceptionsafety.o test/testexceptionsafety.cpp

test/testfilelister.o: test/testfilelister.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testfilelister.o test/testfilelister.cpp

test/testincompletestatement.o: test/testincompletestatement.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/tokenize.h lib/tokenlist.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testincompletestatement.o test/testincompletestatement.cpp

test/testinternal.o: test/testinternal.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkinternal.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testinternal.o test/testinternal.cpp

test/testio.o: test/testio.cpp lib/checkio.h lib/check.h lib/config.h lib/token.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testio.o test/testio.cpp

test/testleakautovar.o: test/testleakautovar.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkleakautovar.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testleakautovar.o test/testleakautovar.cpp

test/testmathlib.o: test/testmathlib.cpp lib/mathlib.h lib/config.h test/testsuite.h lib/errorlogger.h lib/suppressions.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testmathlib.o test/testmathlib.cpp

test/testmemleak.o: test/testmemleak.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkmemoryleak.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h lib/symboldatabase.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testmemleak.o test/testmemleak.cpp

test/testnonreentrantfunctions.o: test/testnonreentrantfunctions.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checknonreentrantfunctions.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testnonreentrantfunctions.o test/testnonreentrantfunctions.cpp

test/testnullpointer.o: test/testnullpointer.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checknullpointer.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testnullpointer.o test/testnullpointer.cpp

test/testobsoletefunctions.o: test/testobsoletefunctions.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkobsoletefunctions.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testobsoletefunctions.o test/testobsoletefunctions.cpp

test/testoptions.o: test/testoptions.cpp test/options.h test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testoptions.o test/testoptions.cpp

test/testother.o: test/testother.cpp lib/preprocessor.h lib/config.h lib/tokenize.h lib/errorlogger.h lib/suppressions.h lib/tokenlist.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testother.o test/testother.cpp

test/testpath.o: test/testpath.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpath.o test/testpath.cpp

test/testpathmatch.o: test/testpathmatch.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpathmatch.o test/testpathmatch.cpp

test/testpostfixoperator.o: test/testpostfixoperator.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkpostfixoperator.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpostfixoperator.o test/testpostfixoperator.cpp

test/testpreprocessor.o: test/testpreprocessor.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/preprocessor.h lib/tokenize.h lib/tokenlist.h lib/token.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpreprocessor.o test/testpreprocessor.cpp

test/testrunner.o: test/testrunner.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h test/options.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testrunner.o test/testrunner.cpp

test/testsimplifytokens.o: test/testsimplifytokens.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/tokenize.h lib/tokenlist.h lib/token.h lib/settings.h lib/standards.h lib/templatesimplifier.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsimplifytokens.o test/testsimplifytokens.cpp

test/teststl.o: test/teststl.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkstl.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/teststl.o test/teststl.cpp

test/testsuite.o: test/testsuite.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h test/options.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsuite.o test/testsuite.cpp

test/testsuppressions.o: test/testsuppressions.cpp lib/cppcheck.h lib/config.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsuppressions.o test/testsuppressions.cpp

test/testsymboldatabase.o: test/testsymboldatabase.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h test/testutils.h lib/settings.h lib/standards.h lib/tokenize.h lib/tokenlist.h lib/symboldatabase.h lib/token.h lib/mathlib.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsymboldatabase.o test/testsymboldatabase.cpp

test/testthreadexecutor.o: test/testthreadexecutor.cpp lib/cppcheck.h lib/config.h lib/settings.h lib/suppressions.h lib/standards.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/tokenlist.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testthreadexecutor.o test/testthreadexecutor.cpp

test/testtimer.o: test/testtimer.cpp lib/timer.h lib/config.h test/testsuite.h lib/errorlogger.h lib/suppressions.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testtimer.o test/testtimer.cpp

test/testtoken.o: test/testtoken.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h test/testutils.h lib/settings.h lib/standards.h lib/tokenize.h lib/tokenlist.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testtoken.o test/testtoken.cpp

test/testtokenize.o: test/testtokenize.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/tokenize.h lib/tokenlist.h lib/token.h lib/settings.h lib/standards.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testtokenize.o test/testtokenize.cpp

test/testuninitvar.o: test/testuninitvar.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkuninitvar.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testuninitvar.o test/testuninitvar.cpp

test/testunusedfunctions.o: test/testunusedfunctions.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h test/testsuite.h test/redirect.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testunusedfunctions.o test/testunusedfunctions.cpp

test/testunusedprivfunc.o: test/testunusedprivfunc.cpp lib/tokenize.h lib/errorlogger.h lib/config.h lib/suppressions.h lib/tokenlist.h lib/checkclass.h lib/check.h lib/token.h lib/settings.h lib/standards.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testunusedprivfunc.o test/testunusedprivfunc.cpp

test/testunusedvar.o: test/testunusedvar.cpp test/testsuite.h lib/errorlogger.h lib/config.h lib/suppressions.h test/redirect.h lib/tokenize.h lib/tokenlist.h lib/checkunusedvar.h lib/check.h lib/token.h lib/settings.h lib/standards.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testunusedvar.o test/testunusedvar.cpp

