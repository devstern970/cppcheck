// For a release version x.y the MAJOR should be x and both MINOR and DEVMINOR should be y.
// After a release the DEVMINOR is incremented. MAJOR=x MINOR=y, DEVMINOR=y+1

#define CPPCHECK_MAJOR 2
#define CPPCHECK_MINOR 4
#define CPPCHECK_DEVMINOR 4

#define STRINGIFY(x) STRING(x)
#define STRING(VER) #VER
#if CPPCHECK_MINOR == CPPCHECK_DEVMINOR
#define CPPCHECK_VERSION_STRING STRINGIFY(CPPCHECK_MAJOR) "." STRINGIFY(CPPCHECK_DEVMINOR)
#define CPPCHECK_VERSION CPPCHECK_MAJOR,CPPCHECK_MINOR,0,0
#else
#define CPPCHECK_VERSION_STRING STRINGIFY(CPPCHECK_MAJOR) "." STRINGIFY(CPPCHECK_DEVMINOR) " dev"
#define CPPCHECK_VERSION CPPCHECK_MAJOR,CPPCHECK_MINOR,99,0
#endif
#define LEGALCOPYRIGHT L"Copyright (C) 2007-2020 Cppcheck team."
