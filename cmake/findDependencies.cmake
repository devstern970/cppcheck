if(BUILD_GUI)
    list(APPEND qt_components Core Gui Widgets PrintSupport LinguistTools Help Network)
    if(WITH_QCHART)
        list(APPEND qt_components Charts)
    endif()
    if(BUILD_TESTS)
        list(APPEND qt_components Test)
    endif()
    if(USE_QT6)
        find_package(Qt6 COMPONENTS ${qt_components} REQUIRED)
        set(QT_VERSION "${Qt6Core_VERSION}")
        if(NOT QT_VERSION)
            # TODO: remove fallback
            message(WARNING "'Qt6Core_VERSION' is not set - using 6.0.0 as fallback")
            set(QT_VERSION "6.0.0")
        endif()
        if(MSVC)
            # disable Visual Studio C++ memory leak detection since it causes compiler errors with Qt 6
            # D:\a\cppcheck\Qt\6.2.4\msvc2019_64\include\QtCore/qhash.h(179,15): warning C4003: not enough arguments for function-like macro invocation 'free' [D:\a\cppcheck\cppcheck\build\gui\cppcheck-gui.vcxproj]
            # D:\a\cppcheck\Qt\6.2.4\msvc2019_64\include\QtCore/qhash.h(179,15): error C2059: syntax error: ',' [D:\a\cppcheck\cppcheck\build\gui\cppcheck-gui.vcxproj]
            # this is supposed to be fixed according to the following tickets but it still happens
            # https://bugreports.qt.io/browse/QTBUG-40575
            # https://bugreports.qt.io/browse/QTBUG-86395
            set(DISABLE_CRTDBG_MAP_ALLOC ON)
        endif()
    else()
        message(WARNING "Building with Qt5 is deprecated (it went EOL in May 2023) and will be removed in a future release - please use Qt6 instead")
        find_package(Qt5 COMPONENTS ${qt_components} REQUIRED)
        set(QT_VERSION "${Qt5Core_VERSION_STRING}")
    endif()
endif()

if(HAVE_RULES)
    find_path(PCRE_INCLUDE pcre.h)
    find_library(PCRE_LIBRARY NAMES pcre pcred)
    if(NOT PCRE_LIBRARY OR NOT PCRE_INCLUDE)
        message(FATAL_ERROR "pcre dependency for RULES has not been found")
    endif()
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(CMAKE_VERSION VERSION_EQUAL "3.12" OR CMAKE_VERSION VERSION_GREATER "3.12")
    find_package(Python COMPONENTS Interpreter)
else()
    find_package(PythonInterp 3 QUIET)
    if(PYTHONINTERP_FOUND)
        set(Python_EXECUTABLE ${PYTHON_EXECUTABLE})
        set(Python_VERSION ${PYTHON_VERSION_STRING})
        set(Python_Interpreter_FOUND ${PYTHONINTERP_FOUND})
    endif()
endif()

if(NOT Python_Interpreter_FOUND AND NOT USE_MATCHCOMPILER_OPT STREQUAL "Off")
    message(WARNING "No python interpreter found - disabling matchcompiler.")
    set(USE_MATCHCOMPILER_OPT "Off")
endif()

if(NOT USE_BUNDLED_TINYXML2)
    find_package(tinyxml2 QUIET)
    if(TARGET tinyxml2::tinyxml2)
        set(tinyxml2_LIBRARIES "tinyxml2::tinyxml2")
        set(tinyxml2_INCLUDE_DIRS $<TARGET_PROPERTY:tinyxml2::tinyxml2,INTERFACE_INCLUDE_DIRECTORIES>)
    else()
        find_library(tinyxml2_LIBRARIES tinyxml2)
        find_path(tinyxml2_INCLUDE_DIRS tinyxml2.h)
        if(NOT tinyxml2_LIBRARIES AND NOT tinyxml2_INCLUDE_DIRS)
            message(FATAL_ERROR "tinyxml2 has not been found")
        else()
            set(tinyxml2_FOUND 1)
        endif()
    endif()
endif()

find_package(Threads REQUIRED)

if(USE_BOOST)
    # we are using the header-only "container" component
    find_package(Boost QUIET)
endif()

find_program(LIBXML2_XMLLINT_EXECUTABLE xmllint)
