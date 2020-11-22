message( STATUS "------------------ General configuration for ${PROJECT_NAME} ${VERSION} -----------------")
message( STATUS )
message( STATUS "CMake Generator =       ${CMAKE_GENERATOR}")
message( STATUS "Compiler =              ${CMAKE_CXX_COMPILER_ID}")
message( STATUS "Compiler Version =      ${CMAKE_CXX_COMPILER_VERSION}")
message( STATUS "Build type =            ${CMAKE_BUILD_TYPE}")
message( STATUS "CMAKE_INSTALL_PREFIX =  ${CMAKE_INSTALL_PREFIX}" )
message( STATUS "CMAKE_DISABLE_PRECOMPILE_HEADERS = ${CMAKE_DISABLE_PRECOMPILE_HEADERS}" )
message( STATUS "C++ flags (General) =   ${CMAKE_CXX_FLAGS}")
message( STATUS "C++ flags (Release) =   ${CMAKE_CXX_FLAGS_RELEASE}")
message( STATUS "C++ flags (RelWithDebInfo) = ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message( STATUS "C++ flags (Debug) =     ${CMAKE_CXX_FLAGS_DEBUG}")
get_directory_property( DirDefs DIRECTORY ${CMAKE_SOURCE_DIR} COMPILE_DEFINITIONS )
foreach( d ${DirDefs} )
    message( STATUS "Found Define: " ${d} )
endforeach()
message( STATUS )
message( STATUS "---------------------------------------------------------" )
message( STATUS "ANALYZE_MEMORY =        ${ANALYZE_MEMORY}" )
message( STATUS "ANALYZE_ADDRESS =       ${ANALYZE_ADDRESS}" )
message( STATUS "ANALYZE_THREAD =        ${ANALYZE_THREAD}" )
message( STATUS "ANALYZE_UNDEFINED =     ${ANALYZE_UNDEFINED}" )
message( STATUS "ANALYZE_DATAFLOW =      ${ANALYZE_DATAFLOW}" )
message( STATUS "WARNINGS_ARE_ERRORS =   ${WARNINGS_ARE_ERRORS}" )
message( STATUS )
message( STATUS "USE_MATCHCOMPILER =     ${USE_MATCHCOMPILER}" )
message( STATUS "USE_MATCHCOMPILER_OPT = ${USE_MATCHCOMPILER_OPT}" )
message( STATUS )
if(NOT DEFINED BUILD_SHARED_LIBS)
    message( STATUS "BUILD_SHARED_LIBS =     OFF" )
else()
    message( STATUS "BUILD_SHARED_LIBS =     ${BUILD_SHARED_LIBS}" )
endif(NOT DEFINED BUILD_SHARED_LIBS)
message( STATUS "LIBXML2_XMLLINT_EXECUTABLE = ${LIBXML2_XMLLINT_EXECUTABLE}" )
message( STATUS "BUILD_TESTS =           ${BUILD_TESTS}" )
if(BUILD_TESTS)
    message( STATUS "REGISTER_TESTS =        ${REGISTER_TESTS}" )
endif()
message( STATUS "ENABLE_CHECK_INTERNAL = ${ENABLE_CHECK_INTERNAL}" )
message( STATUS "ENABLE_OSS_FUZZ =       ${ENABLE_OSS_FUZZ}" )
message( STATUS )
message( STATUS "BUILD_GUI =             ${BUILD_GUI}" )
message( STATUS "WITH_QCHART =           ${WITH_QCHART}" )
message( STATUS )
message( STATUS "HAVE_RULES =            ${HAVE_RULES}" )
if (HAVE_RULES)
    message( STATUS "PCRE_LIBRARY =          ${PCRE_LIBRARY}" )
endif()
message( STATUS )
message( STATUS "USE_Z3 =                ${USE_Z3}" )
if (USE_Z3)
    message( STATUS "Z3_LIBRARIES =          ${Z3_LIBRARIES}" )
    message( STATUS "Z3_CXX_INCLUDE_DIRS =   ${Z3_CXX_INCLUDE_DIRS}" )
endif()
message( STATUS "USE_BUNDLED_TINYXML2 =  ${USE_BUNDLED_TINYXML2}" )
message( STATUS )

if(${ANALYZE_ADDRESS})
   message("##########################################################")
   message(STATUS "For better visualization change environment variable: ASAN_SYMBOLIZER_PATH=/path/to/llvm-symbolizer")
   message("##########################################################")
endif()
