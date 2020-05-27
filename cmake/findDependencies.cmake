if (BUILD_GUI)
    if (NOT WITH_QCHART)
        find_package(Qt5 COMPONENTS Core Gui Widgets PrintSupport LinguistTools REQUIRED)
    else()
        find_package(Qt5 COMPONENTS Core Gui Widgets PrintSupport LinguistTools Charts REQUIRED)
    endif()
endif()

if (HAVE_RULES)
    find_library(PCRE_LIBRARY pcre)
    if (NOT PCRE_LIBRARY)
        message(FATAL_ERROR "pcre dependency for RULES has not been found")
    endif()
endif()

if (USE_Z3)
    find_package(Z3 QUIET)
    if (NOT Z3_FOUND)
        find_library(Z3_LIBRARIES z3)
        if (NOT Z3_LIBRARIES)
            message(FATAL_ERROR "z3 dependency has not been found")
        endif()
        find_path(Z3_CXX_INCLUDE_DIRS z3++.h PATH_SUFFIXES "z3")
        if (NOT Z3_CXX_INCLUDE_DIRS)
            message(FATAL_ERROR "z3++.h has not been found")
        endif()
    endif()
    include_directories(cppcheck SYSTEM ${Z3_CXX_INCLUDE_DIRS})
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC OFF)

if (NOT USE_MATCHCOMPILER_OPT MATCHES "Off")
    find_package(PythonInterp)
    if (NOT ${PYTHONINTERP_FOUND})
        message(WARNING "No python interpreter found. Therefore, the match compiler is switched off.")
        set(USE_MATCHCOMPILER_OPT "Off")
    endif()
endif()
