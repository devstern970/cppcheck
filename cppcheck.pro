TEMPLATE = subdirs
SUBDIRS = src test gui
CONFIG += ordered

# check target - build and run tests
check.depends = sub-test
check.commands = $$PWD/test/test
QMAKE_EXTRA_TARGETS += check
