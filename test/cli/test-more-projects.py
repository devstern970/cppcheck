
# python -m pytest test-other-projects.py

import os
import tempfile
from testutils import cppcheck


# FIXME make CI happy
#def test_project_force_U():
#    # 10018
#    # -U does not work with compile_commands.json
#    with tempfile.TemporaryDirectory('10018') as temp_folder:
#        with open(os.path.join(temp_folder, 'bug1.cpp'), 'wt') as f:
#            f.write("""
#                    int x = 123 / 0;
#                    #ifdef MACRO1
#                    int y = 1000 / 0;
#                    #endif
#                    """)
#
#        compile_commands = os.path.join(temp_folder, 'compile_commands.json')
#
#        with open(compile_commands, 'wt') as f:
#            f.write('[ { "directory": "%s", "command": "c++ -o bug1.o -c bug1.cpp", "file": "bug1.cpp", "output": "bug1.o" } ]' % str(temp_folder))
#
#        # Without -U => both bugs are found
#        ret, stdout, stderr = cppcheck(['--project=' + compile_commands, '--force', '-rp=' + temp_folder, '--template=cppcheck1'])
#        assert (stderr == '[bug1.cpp:2]: (error) Division by zero.\n'
#                          '[bug1.cpp:4]: (error) Division by zero.\n')
#
#        # With -U => only first bug is found
#        ret, stdout, stderr = cppcheck(['--project=' + compile_commands, '--force', '-UMACRO1', '-rp=' + temp_folder, '--template=cppcheck1'])
#        assert stderr == '[bug1.cpp:2]: (error) Division by zero.\n'

