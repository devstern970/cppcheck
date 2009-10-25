CXXFLAGS=-Wall -Wextra -pedantic -g
CXX=g++
BIN=${DESTDIR}/usr/bin


###### Object Files

LIBOBJ =     lib/checkautovariables.o \
              lib/checkbufferoverrun.o \
              lib/checkclass.o \
              lib/checkdangerousfunctions.o \
              lib/checkexceptionsafety.o \
              lib/checkheaders.o \
              lib/checkmemoryleak.o \
              lib/checkother.o \
              lib/checkstl.o \
              lib/checkunusedfunctions.o \
              lib/cppcheck.o \
              lib/cppcheckexecutor.o \
              lib/errorlogger.o \
              lib/filelister.o \
              lib/mathlib.o \
              lib/preprocessor.o \
              lib/settings.o \
              lib/threadexecutor.o \
              lib/token.o \
              lib/tokenize.o

CLIOBJ =     cli/main.o

TESTOBJ =     test/testautovariables.o \
              test/testbufferoverrun.o \
              test/testcharvar.o \
              test/testclass.o \
              test/testconstructors.o \
              test/testcppcheck.o \
              test/testdangerousfunctions.o \
              test/testdivision.o \
              test/testexceptionsafety.o \
              test/testfilelister.o \
              test/testincompletestatement.o \
              test/testmathlib.o \
              test/testmemleak.o \
              test/testother.o \
              test/testpreprocessor.o \
              test/testredundantif.o \
              test/testrunner.o \
              test/testsimplifytokens.o \
              test/teststl.o \
              test/testsuite.o \
              test/testtoken.o \
              test/testtokenize.o \
              test/testunusedfunctions.o \
              test/testunusedprivfunc.o \
              test/testunusedvar.o


###### Targets

cppcheck:	$(LIBOBJ)	$(CLIOBJ)
	$(CXX) $(CXXFLAGS) -o cppcheck $(CLIOBJ) $(LIBOBJ) $(LDFLAGS)

all:	cppcheck	testrunner	tools

testrunner:	$(TESTOBJ)	$(LIBOBJ)
	$(CXX) $(CXXFLAGS) -o testrunner $(TESTOBJ) $(LIBOBJ) $(LDFLAGS)

test:	all
	./testrunner

tools:	tools/dmake

tools/dmake:	tools/dmake.cpp	lib/filelister.cpp	lib/filelister.h
	$(CXX) $(CXXFLAGS) -o tools/dmake tools/dmake.cpp lib/filelister.cpp $(LDFLAGS)

clean:
	rm -f lib/*.o cli/*.o test/*.o testrunner cppcheck tools/dmake

install:	cppcheck
	install -d ${BIN}
	install cppcheck ${BIN}


###### Build

lib/checkautovariables.o: lib/checkautovariables.cpp lib/checkautovariables.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkautovariables.o lib/checkautovariables.cpp

lib/checkbufferoverrun.o: lib/checkbufferoverrun.cpp lib/checkbufferoverrun.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h lib/mathlib.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkbufferoverrun.o lib/checkbufferoverrun.cpp

lib/checkclass.o: lib/checkclass.cpp lib/checkclass.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkclass.o lib/checkclass.cpp

lib/checkdangerousfunctions.o: lib/checkdangerousfunctions.cpp lib/checkdangerousfunctions.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkdangerousfunctions.o lib/checkdangerousfunctions.cpp

lib/checkexceptionsafety.o: lib/checkexceptionsafety.cpp lib/checkexceptionsafety.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkexceptionsafety.o lib/checkexceptionsafety.cpp

lib/checkheaders.o: lib/checkheaders.cpp lib/checkheaders.h lib/tokenize.h lib/classinfo.h lib/token.h lib/errorlogger.h lib/settings.h lib/filelister.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkheaders.o lib/checkheaders.cpp

lib/checkmemoryleak.o: lib/checkmemoryleak.cpp lib/checkmemoryleak.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h lib/mathlib.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkmemoryleak.o lib/checkmemoryleak.cpp

lib/checkother.o: lib/checkother.cpp lib/checkother.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h lib/mathlib.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkother.o lib/checkother.cpp

lib/checkstl.o: lib/checkstl.cpp lib/checkstl.h lib/check.h lib/token.h lib/tokenize.h lib/classinfo.h lib/settings.h lib/errorlogger.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkstl.o lib/checkstl.cpp

lib/checkunusedfunctions.o: lib/checkunusedfunctions.cpp lib/checkunusedfunctions.h lib/tokenize.h lib/classinfo.h lib/token.h lib/errorlogger.h lib/settings.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/checkunusedfunctions.o lib/checkunusedfunctions.cpp

lib/cppcheck.o: lib/cppcheck.cpp lib/cppcheck.h lib/settings.h lib/errorlogger.h lib/checkunusedfunctions.h lib/tokenize.h lib/classinfo.h lib/token.h lib/preprocessor.h lib/filelister.h lib/check.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/cppcheck.o lib/cppcheck.cpp

lib/cppcheckexecutor.o: lib/cppcheckexecutor.cpp lib/cppcheckexecutor.h lib/errorlogger.h lib/settings.h lib/cppcheck.h lib/checkunusedfunctions.h lib/tokenize.h lib/classinfo.h lib/token.h lib/threadexecutor.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/cppcheckexecutor.o lib/cppcheckexecutor.cpp

lib/errorlogger.o: lib/errorlogger.cpp lib/errorlogger.h lib/settings.h lib/tokenize.h lib/classinfo.h lib/token.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/errorlogger.o lib/errorlogger.cpp

lib/filelister.o: lib/filelister.cpp lib/filelister.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/filelister.o lib/filelister.cpp

lib/mathlib.o: lib/mathlib.cpp lib/mathlib.h lib/token.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/mathlib.o lib/mathlib.cpp

lib/preprocessor.o: lib/preprocessor.cpp lib/preprocessor.h lib/errorlogger.h lib/settings.h lib/tokenize.h lib/classinfo.h lib/token.h lib/filelister.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/preprocessor.o lib/preprocessor.cpp

lib/settings.o: lib/settings.cpp lib/settings.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/settings.o lib/settings.cpp

lib/threadexecutor.o: lib/threadexecutor.cpp lib/threadexecutor.h lib/settings.h lib/errorlogger.h lib/cppcheck.h lib/checkunusedfunctions.h lib/tokenize.h lib/classinfo.h lib/token.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/threadexecutor.o lib/threadexecutor.cpp

lib/token.o: lib/token.cpp lib/token.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/token.o lib/token.cpp

lib/tokenize.o: lib/tokenize.cpp lib/tokenize.h lib/classinfo.h lib/token.h lib/filelister.h lib/mathlib.h lib/settings.h lib/errorlogger.h lib/check.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o lib/tokenize.o lib/tokenize.cpp

cli/main.o: cli/main.cpp lib/cppcheckexecutor.h lib/errorlogger.h lib/settings.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o cli/main.o cli/main.cpp

test/testautovariables.o: test/testautovariables.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testautovariables.o test/testautovariables.cpp

test/testbufferoverrun.o: test/testbufferoverrun.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testbufferoverrun.o test/testbufferoverrun.cpp

test/testcharvar.o: test/testcharvar.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testcharvar.o test/testcharvar.cpp

test/testclass.o: test/testclass.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testclass.o test/testclass.cpp

test/testconstructors.o: test/testconstructors.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testconstructors.o test/testconstructors.cpp

test/testcppcheck.o: test/testcppcheck.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testcppcheck.o test/testcppcheck.cpp

test/testdangerousfunctions.o: test/testdangerousfunctions.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testdangerousfunctions.o test/testdangerousfunctions.cpp

test/testdivision.o: test/testdivision.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testdivision.o test/testdivision.cpp

test/testexceptionsafety.o: test/testexceptionsafety.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testexceptionsafety.o test/testexceptionsafety.cpp

test/testfilelister.o: test/testfilelister.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testfilelister.o test/testfilelister.cpp

test/testincompletestatement.o: test/testincompletestatement.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testincompletestatement.o test/testincompletestatement.cpp

test/testmathlib.o: test/testmathlib.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testmathlib.o test/testmathlib.cpp

test/testmemleak.o: test/testmemleak.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testmemleak.o test/testmemleak.cpp

test/testother.o: test/testother.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testother.o test/testother.cpp

test/testpreprocessor.o: test/testpreprocessor.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testpreprocessor.o test/testpreprocessor.cpp

test/testredundantif.o: test/testredundantif.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testredundantif.o test/testredundantif.cpp

test/testrunner.o: test/testrunner.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testrunner.o test/testrunner.cpp

test/testsimplifytokens.o: test/testsimplifytokens.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testsimplifytokens.o test/testsimplifytokens.cpp

test/teststl.o: test/teststl.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/teststl.o test/teststl.cpp

test/testsuite.o: test/testsuite.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testsuite.o test/testsuite.cpp

test/testtoken.o: test/testtoken.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testtoken.o test/testtoken.cpp

test/testtokenize.o: test/testtokenize.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testtokenize.o test/testtokenize.cpp

test/testunusedfunctions.o: test/testunusedfunctions.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testunusedfunctions.o test/testunusedfunctions.cpp

test/testunusedprivfunc.o: test/testunusedprivfunc.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testunusedprivfunc.o test/testunusedprivfunc.cpp

test/testunusedvar.o: test/testunusedvar.cpp test/testsuite.h
	$(CXX) $(CXXFLAGS) -Ilib -c -o test/testunusedvar.o test/testunusedvar.cpp

