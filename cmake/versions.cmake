# Version for libraries CPP
SET(VERSION "2.0.99")
STRING(REGEX MATCHALL "[0-9]" VERSION_PARTS "${VERSION}")
LIST(GET VERSION_PARTS 0 VERSION_MAJOR)
LIST(GET VERSION_PARTS 1 VERSION_MINOR)
SET(SOVERSION "${VERSION_MAJOR}.${VERSION_MINOR}")

# Postfix of so's:
SET(DLLVERSION "")
SET(DEBUG_POSTFIX "")
