message( STATUS "------------------ General configuration for ${PROJECT_NAME} ${PROJECT_VERSION} -----------------")
message( STATUS )
message( STATUS "CMake Version =         ${CMAKE_VERSION}")
message( STATUS "CMake Generator =       ${CMAKE_GENERATOR}")
message( STATUS )
message( STATUS "Compiler =              ${CMAKE_CXX_COMPILER_ID}")
message( STATUS "Compiler Version =      ${CMAKE_CXX_COMPILER_VERSION}")
message( STATUS "Build type =            ${CMAKE_BUILD_TYPE}")
message( STATUS "CMake C++ Standard =    ${CMAKE_CXX_STANDARD}")
message( STATUS "CMAKE_INSTALL_PREFIX =  ${CMAKE_INSTALL_PREFIX}" )
message( STATUS "CMAKE_DISABLE_PRECOMPILE_HEADERS = ${CMAKE_DISABLE_PRECOMPILE_HEADERS}" )
message( STATUS "C++ flags (General) =   ${CMAKE_CXX_FLAGS}")
message( STATUS "C++ flags (Release) =   ${CMAKE_CXX_FLAGS_RELEASE}")
message( STATUS "C++ flags (RelWithDebInfo) = ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message( STATUS "C++ flags (Debug) =     ${CMAKE_CXX_FLAGS_DEBUG}")
message( STATUS "CMAKE_EXE_LINKER_FLAGS = ${CMAKE_EXE_LINKER_FLAGS}")
message( STATUS "CPPCHK_GLIBCXX_DEBUG =  ${CPPCHK_GLIBCXX_DEBUG}" )
get_directory_property( DirCompileDefs DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_DEFINITIONS )
message( STATUS "COMPILE_DEFINITIONS (global) =  ${DirCompileDefs}" )
get_directory_property( DirCompileOptions DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_OPTIONS )
message( STATUS "COMPILE_OPTIONS (global) =  ${DirCompileOptions}" )
message( STATUS )
if (Python_Interpreter_FOUND)
    message( STATUS "Python_VERSION =        ${Python_VERSION}" )
    message( STATUS "Python_EXECUTABLE =     ${Python_EXECUTABLE}" )
endif()
message( STATUS )
message( STATUS "---------------------------------------------------------" )
message( STATUS "ANALYZE_MEMORY =        ${ANALYZE_MEMORY}" )
message( STATUS "ANALYZE_ADDRESS =       ${ANALYZE_ADDRESS}" )
message( STATUS "ANALYZE_THREAD =        ${ANALYZE_THREAD}" )
message( STATUS "ANALYZE_UNDEFINED =     ${ANALYZE_UNDEFINED}" )
message( STATUS "ANALYZE_DATAFLOW =      ${ANALYZE_DATAFLOW}" )
message( STATUS )
message( STATUS "WARNINGS_ARE_ERRORS =   ${WARNINGS_ARE_ERRORS}" )
message( STATUS "EXTERNALS_AS_SYSTEM =   ${EXTERNALS_AS_SYSTEM}" )
message( STATUS )
message( STATUS "USE_MATCHCOMPILER =     ${USE_MATCHCOMPILER}" )
message( STATUS "USE_MATCHCOMPILER_OPT = ${USE_MATCHCOMPILER_OPT}" )
message( STATUS )
message( STATUS "DISABLE_CRTDBG_MAP_ALLOC = ${DISABLE_CRTDBG_MAP_ALLOC}")
message( STATUS "NO_UNIX_SIGNAL_HANDLING = ${NO_UNIX_SIGNAL_HANDLING}")
message( STATUS "NO_UNIX_BACKTRACE_SUPPORT = ${NO_UNIX_BACKTRACE_SUPPORT}")
message( STATUS "NO_WINDOWS_SEH =        ${NO_WINDOWS_SEH}")
message( STATUS )
if(NOT DEFINED BUILD_SHARED_LIBS)
    message( STATUS "BUILD_SHARED_LIBS =     OFF" )
else()
    message( STATUS "BUILD_SHARED_LIBS =     ${BUILD_SHARED_LIBS}" )
endif(NOT DEFINED BUILD_SHARED_LIBS)
message( STATUS "LIBXML2_XMLLINT_EXECUTABLE = ${LIBXML2_XMLLINT_EXECUTABLE}" )
message( STATUS "BUILD_CORE_DLL =        ${BUILD_CORE_DLL}" )
message( STATUS "BUILD_TESTS =           ${BUILD_TESTS}" )
if(BUILD_TESTS)
    message( STATUS "REGISTER_TESTS =        ${REGISTER_TESTS}" )
endif()
message( STATUS "ENABLE_CHECK_INTERNAL = ${ENABLE_CHECK_INTERNAL}" )
message( STATUS "DISABLE_DMAKE =         ${DISABLE_DMAKE}" )
message( STATUS "BUILD_MANPAGE =         ${BUILD_MANPAGE}" )
message( STATUS )
message( STATUS "BUILD_GUI =             ${BUILD_GUI}" )
if (BUILD_GUI)
    message( STATUS "REGISTER_GUI_TESTS =    ${REGISTER_GUI_TESTS}" )
    message( STATUS "WITH_QCHART =           ${WITH_QCHART}" )
    message( STATUS "USE_QT6 =               ${USE_QT6}" )
    message( STATUS "QT_VERSION =            ${QT_VERSION}")
endif()
message( STATUS )
message( STATUS "HAVE_RULES =            ${HAVE_RULES}" )
if (HAVE_RULES)
    message( STATUS "PCRE_LIBRARY =          ${PCRE_LIBRARY}" )
endif()
message( STATUS )
message( STATUS "USE_THREADS =           ${USE_THREADS}" )
message( STATUS "CMAKE_THREAD_LIBS_INIT = ${CMAKE_THREAD_LIBS_INIT}" )
message( STATUS )
message( STATUS "USE_BUNDLED_TINYXML2 =  ${USE_BUNDLED_TINYXML2}" )
if (NOT USE_BUNDLED_TINYXML2)
    message(STATUS "tinyxml2_LIBRARIES =    ${tinyxml2_LIBRARIES}")
    message(STATUS "tinyxml2_INCLUDE_DIRS = ${tinyxml2_INCLUDE_DIRS}")
endif()
message( STATUS )
message( STATUS "USE_BOOST =             ${USE_BOOST}" )
if (USE_BOOST)
    message( STATUS "Boost_FOUND =           ${Boost_FOUND}")
    message( STATUS "Boost_VERSION_STRING =  ${Boost_VERSION_STRING}")
    message( STATUS "Boost_INCLUDE_DIRS =    ${Boost_INCLUDE_DIRS}")
endif()
message( STATUS "USE_LIBCXX =            ${USE_LIBCXX}" )
message( STATUS )

if(${ANALYZE_ADDRESS})
   message("##########################################################")
   message(STATUS "For better visualization change environment variable: ASAN_SYMBOLIZER_PATH=/path/to/llvm-symbolizer")
   message("##########################################################")
endif()
