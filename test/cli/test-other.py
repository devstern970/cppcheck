
# python -m pytest test-other.py

import os
import pytest

from testutils import cppcheck

def __test_missing_include(tmpdir, use_j):
    test_file = os.path.join(tmpdir, 'test.c')
    with open(test_file, 'wt') as f:
        f.write("""
                #include "test.h"
                """)

    args = ['--enable=missingInclude', '--template={file}:{line}:{column}: {severity}:{inconclusive:inconclusive:} {message} [{id}]', test_file]
    if use_j:
        args.insert(0, '-j2')

    _, _, stderr = cppcheck(args)
    assert stderr == '{}:2:0: information: Include file: "test.h" not found. [missingInclude]\n'.format(test_file)

def test_missing_include(tmpdir):
    __test_missing_include(tmpdir, False)

def test_missing_include_j(tmpdir): #11283
    __test_missing_include(tmpdir, True)

def __test_missing_include_check_config(tmpdir, use_j):
    test_file = os.path.join(tmpdir, 'test.c')
    with open(test_file, 'wt') as f:
        f.write("""
                #include "test.h"
                """)

    # TODO: -rp is not working requiring the full path in the assert
    args = '--check-config -rp={} {}'.format(tmpdir, test_file)
    if use_j:
        args = '-j2 ' + args

    _, _, stderr = cppcheck(args.split())
    assert stderr == '' # --check-config no longer reports the missing includes

def test_missing_include_check_config(tmpdir):
    __test_missing_include_check_config(tmpdir, False)

def test_missing_include_check_config_j(tmpdir):
    __test_missing_include_check_config(tmpdir, True)