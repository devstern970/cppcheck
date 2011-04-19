# This file is generated by tools/dmake, do not edit.

# To compile without rules, use 'make HAVE_RULES=no'
HAVE_RULES = yes

ifndef CXXFLAGS
    CXXFLAGS=-Wall -Wextra -Wshadow -pedantic -Wno-long-long -Wfloat-equal -Wcast-qual -g
endif

ifeq ($(HAVE_RULES),yes)
    CXXFLAGS += -DHAVE_RULES
    ifndef LDFLAGS
        LDFLAGS=-lpcre
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

LIBOBJ =      lib/checkautovariables.o \
              lib/checkbufferoverrun.o \
              lib/checkclass.o \
              lib/checkexceptionsafety.o \
              lib/checkmemoryleak.o \
              lib/checknullpointer.o \
              lib/checkobsoletefunctions.o \
              lib/checkother.o \
              lib/checkpostfixoperator.o \
              lib/checkstl.o \
              lib/checkuninitvar.o \
              lib/checkunusedfunctions.o \
              lib/cppcheck.o \
              lib/errorlogger.o \
              lib/executionpath.o \
              lib/mathlib.o \
              lib/path.o \
              lib/preprocessor.o \
              lib/settings.o \
              lib/symboldatabase.o \
              lib/timer.o \
              lib/token.o \
              lib/tokenize.o

CLIOBJ =      cli/cmdlineparser.o \
              cli/cppcheckexecutor.o \
              cli/filelister.o \
              cli/main.o \
              cli/pathmatch.o \
              cli/threadexecutor.o

TESTOBJ =     test/options.o \
              test/testautovariables.o \
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
              test/testmathlib.o \
              test/testmemleak.o \
              test/testnullpointer.o \
              test/testobsoletefunctions.o \
              test/testoptions.o \
              test/testother.o \
              test/testpath.o \
              test/testpathmatch.o \
              test/testpostfixoperator.o \
              test/testpreprocessor.o \
              test/testrunner.o \
              test/testsettings.o \
              test/testsimplifytokens.o \
              test/teststl.o \
              test/testsuite.o \
              test/testsuppressions.o \
              test/testsymboldatabase.o \
              test/testthreadexecutor.o \
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
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o cppcheck $(CLIOBJ) $(LIBOBJ) $(EXTOBJ) $(LDFLAGS)

all:	cppcheck testrunner

testrunner: $(TESTOBJ) $(LIBOBJ) $(EXTOBJ) cli/threadexecutor.o cli/cmdlineparser.o cli/cppcheckexecutor.o cli/filelister.o cli/pathmatch.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o testrunner $(TESTOBJ) $(LIBOBJ) $(EXTOBJ) cli/threadexecutor.o cli/cmdlineparser.o cli/filelister.o cli/pathmatch.o $(LDFLAGS)

test:	all
	./testrunner

check:	all
	./testrunner -g -q

dmake:	tools/dmake.cpp
	$(CXX) -o dmake tools/dmake.cpp cli/filelister.cpp lib/path.cpp -Ilib

clean:
	rm -f lib/*.o cli/*.o test/*.o externals/tinyxml/*.o testrunner cppcheck cppcheck.1

man:	man/cppcheck.1

man/cppcheck.1:	$(MAN_SOURCE)

	$(XP) $(DB2MAN) $(MAN_SOURCE)

tags:
	ctags -R --exclude=doxyoutput .

install: cppcheck
	install -d ${BIN}
	install cppcheck ${BIN}


###### Build

lib/checkautovariables.o: lib/checkautovariables.cpp lib/checkautovariables.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkautovariables.o lib/checkautovariables.cpp

lib/checkbufferoverrun.o: lib/checkbufferoverrun.cpp lib/checkbufferoverrun.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/mathlib.h lib/executionpath.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkbufferoverrun.o lib/checkbufferoverrun.cpp

lib/checkclass.o: lib/checkclass.cpp lib/checkclass.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkclass.o lib/checkclass.cpp

lib/checkexceptionsafety.o: lib/checkexceptionsafety.cpp lib/checkexceptionsafety.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkexceptionsafety.o lib/checkexceptionsafety.cpp

lib/checkmemoryleak.o: lib/checkmemoryleak.cpp lib/checkmemoryleak.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h lib/mathlib.h lib/executionpath.h lib/checkuninitvar.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkmemoryleak.o lib/checkmemoryleak.cpp

lib/checknullpointer.o: lib/checknullpointer.cpp lib/checknullpointer.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/executionpath.h lib/mathlib.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checknullpointer.o lib/checknullpointer.cpp

lib/checkobsoletefunctions.o: lib/checkobsoletefunctions.cpp lib/checkobsoletefunctions.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkobsoletefunctions.o lib/checkobsoletefunctions.cpp

lib/checkother.o: lib/checkother.cpp lib/checkother.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/mathlib.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkother.o lib/checkother.cpp

lib/checkpostfixoperator.o: lib/checkpostfixoperator.cpp lib/checkpostfixoperator.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkpostfixoperator.o lib/checkpostfixoperator.cpp

lib/checkstl.o: lib/checkstl.cpp lib/checkstl.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/executionpath.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkstl.o lib/checkstl.cpp

lib/checkuninitvar.o: lib/checkuninitvar.cpp lib/checkuninitvar.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/mathlib.h lib/executionpath.h lib/checknullpointer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkuninitvar.o lib/checkuninitvar.cpp

lib/checkunusedfunctions.o: lib/checkunusedfunctions.cpp lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/checkunusedfunctions.o lib/checkunusedfunctions.cpp

lib/cppcheck.o: lib/cppcheck.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/preprocessor.h lib/path.h lib/timer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/cppcheck.o lib/cppcheck.cpp

lib/errorlogger.o: lib/errorlogger.cpp lib/errorlogger.h lib/settings.h lib/path.h lib/cppcheck.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/errorlogger.o lib/errorlogger.cpp

lib/executionpath.o: lib/executionpath.cpp lib/executionpath.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/executionpath.o lib/executionpath.cpp

lib/mathlib.o: lib/mathlib.cpp lib/mathlib.h lib/tokenize.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/mathlib.o lib/mathlib.cpp

lib/path.o: lib/path.cpp lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/path.o lib/path.cpp

lib/preprocessor.o: lib/preprocessor.cpp lib/preprocessor.h lib/tokenize.h lib/token.h lib/path.h lib/errorlogger.h lib/settings.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/preprocessor.o lib/preprocessor.cpp

lib/settings.o: lib/settings.cpp lib/settings.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/settings.o lib/settings.cpp

lib/symboldatabase.o: lib/symboldatabase.cpp lib/symboldatabase.h lib/token.h lib/tokenize.h lib/settings.h lib/errorlogger.h lib/check.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/symboldatabase.o lib/symboldatabase.cpp

lib/timer.o: lib/timer.cpp lib/timer.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/timer.o lib/timer.cpp

lib/token.o: lib/token.cpp lib/token.h lib/errorlogger.h lib/settings.h lib/check.h lib/tokenize.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/token.o lib/token.cpp

lib/tokenize.o: lib/tokenize.cpp lib/tokenize.h lib/token.h lib/mathlib.h lib/settings.h lib/errorlogger.h lib/check.h lib/path.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_LIB} -c -o lib/tokenize.o lib/tokenize.cpp

cli/cmdlineparser.o: cli/cmdlineparser.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/timer.h cli/cmdlineparser.h lib/path.h cli/filelister.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/cmdlineparser.o cli/cmdlineparser.cpp

cli/cppcheckexecutor.o: cli/cppcheckexecutor.cpp cli/cppcheckexecutor.h lib/errorlogger.h lib/settings.h lib/cppcheck.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h cli/threadexecutor.h cli/cmdlineparser.h cli/filelister.h lib/path.h cli/pathmatch.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/cppcheckexecutor.o cli/cppcheckexecutor.cpp

cli/filelister.o: cli/filelister.cpp cli/filelister.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/filelister.o cli/filelister.cpp

cli/main.o: cli/main.cpp cli/cppcheckexecutor.h lib/errorlogger.h lib/settings.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/main.o cli/main.cpp

cli/pathmatch.o: cli/pathmatch.cpp cli/pathmatch.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/pathmatch.o cli/pathmatch.cpp

cli/threadexecutor.o: cli/threadexecutor.cpp cli/threadexecutor.h lib/settings.h lib/errorlogger.h lib/cppcheck.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_CLI} -c -o cli/threadexecutor.o cli/threadexecutor.cpp

test/options.o: test/options.cpp test/options.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/options.o test/options.cpp

test/testautovariables.o: test/testautovariables.cpp lib/tokenize.h lib/checkautovariables.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testautovariables.o test/testautovariables.cpp

test/testbufferoverrun.o: test/testbufferoverrun.cpp lib/tokenize.h lib/checkbufferoverrun.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h lib/mathlib.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testbufferoverrun.o test/testbufferoverrun.cpp

test/testcharvar.o: test/testcharvar.cpp lib/tokenize.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testcharvar.o test/testcharvar.cpp

test/testclass.o: test/testclass.cpp lib/tokenize.h lib/checkclass.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testclass.o test/testclass.cpp

test/testcmdlineparser.o: test/testcmdlineparser.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testcmdlineparser.o test/testcmdlineparser.cpp

test/testconstructors.o: test/testconstructors.cpp lib/tokenize.h lib/checkclass.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testconstructors.o test/testconstructors.cpp

test/testcppcheck.o: test/testcppcheck.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h test/testsuite.h test/redirect.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testcppcheck.o test/testcppcheck.cpp

test/testdivision.o: test/testdivision.cpp lib/tokenize.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testdivision.o test/testdivision.cpp

test/testerrorlogger.o: test/testerrorlogger.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testerrorlogger.o test/testerrorlogger.cpp

test/testexceptionsafety.o: test/testexceptionsafety.cpp lib/tokenize.h lib/checkexceptionsafety.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testexceptionsafety.o test/testexceptionsafety.cpp

test/testfilelister.o: test/testfilelister.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testfilelister.o test/testfilelister.cpp

test/testincompletestatement.o: test/testincompletestatement.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/tokenize.h lib/checkother.h lib/check.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testincompletestatement.o test/testincompletestatement.cpp

test/testmathlib.o: test/testmathlib.cpp lib/mathlib.h test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testmathlib.o test/testmathlib.cpp

test/testmemleak.o: test/testmemleak.cpp lib/tokenize.h lib/checkmemoryleak.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testmemleak.o test/testmemleak.cpp

test/testnullpointer.o: test/testnullpointer.cpp lib/tokenize.h lib/checknullpointer.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testnullpointer.o test/testnullpointer.cpp

test/testobsoletefunctions.o: test/testobsoletefunctions.cpp lib/tokenize.h lib/checkobsoletefunctions.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testobsoletefunctions.o test/testobsoletefunctions.cpp

test/testoptions.o: test/testoptions.cpp test/options.h test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testoptions.o test/testoptions.cpp

test/testother.o: test/testother.cpp lib/preprocessor.h lib/tokenize.h lib/checkother.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testother.o test/testother.cpp

test/testpath.o: test/testpath.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/path.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpath.o test/testpath.cpp

test/testpathmatch.o: test/testpathmatch.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpathmatch.o test/testpathmatch.cpp

test/testpostfixoperator.o: test/testpostfixoperator.cpp lib/tokenize.h lib/checkpostfixoperator.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpostfixoperator.o test/testpostfixoperator.cpp

test/testpreprocessor.o: test/testpreprocessor.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/preprocessor.h lib/tokenize.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testpreprocessor.o test/testpreprocessor.cpp

test/testrunner.o: test/testrunner.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h test/options.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testrunner.o test/testrunner.cpp

test/testsettings.o: test/testsettings.cpp lib/settings.h test/testsuite.h lib/errorlogger.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsettings.o test/testsettings.cpp

test/testsimplifytokens.o: test/testsimplifytokens.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/tokenize.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsimplifytokens.o test/testsimplifytokens.cpp

test/teststl.o: test/teststl.cpp lib/tokenize.h lib/checkstl.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/teststl.o test/teststl.cpp

test/testsuite.o: test/testsuite.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h test/options.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsuite.o test/testsuite.cpp

test/testsuppressions.o: test/testsuppressions.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsuppressions.o test/testsuppressions.cpp

test/testsymboldatabase.o: test/testsymboldatabase.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h test/testutils.h lib/tokenize.h lib/token.h lib/symboldatabase.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testsymboldatabase.o test/testsymboldatabase.cpp

test/testthreadexecutor.o: test/testthreadexecutor.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/check.h lib/token.h lib/tokenize.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testthreadexecutor.o test/testthreadexecutor.cpp

test/testtoken.o: test/testtoken.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h test/testutils.h lib/tokenize.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testtoken.o test/testtoken.cpp

test/testtokenize.o: test/testtokenize.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/tokenize.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testtokenize.o test/testtokenize.cpp

test/testuninitvar.o: test/testuninitvar.cpp lib/tokenize.h lib/checkuninitvar.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testuninitvar.o test/testuninitvar.cpp

test/testunusedfunctions.o: test/testunusedfunctions.cpp lib/tokenize.h test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/checkunusedfunctions.h lib/check.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testunusedfunctions.o test/testunusedfunctions.cpp

test/testunusedprivfunc.o: test/testunusedprivfunc.cpp lib/tokenize.h lib/checkclass.h lib/check.h lib/token.h lib/settings.h lib/errorlogger.h lib/symboldatabase.h test/testsuite.h test/redirect.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testunusedprivfunc.o test/testunusedprivfunc.cpp

test/testunusedvar.o: test/testunusedvar.cpp test/testsuite.h lib/errorlogger.h lib/settings.h test/redirect.h lib/tokenize.h lib/checkother.h lib/check.h lib/token.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ${INCLUDE_FOR_TEST} -c -o test/testunusedvar.o test/testunusedvar.cpp

