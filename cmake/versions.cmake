# Version for libraries CPP
SET(VERSION "1.88.99")
STRING(REGEX MATCHALL "[0-9]" VERSION_PARTS "${VERSION}")
LIST(GET VERSION_PARTS 0 VERSION_MAJOR)
LIST(GET VERSION_PARTS 1 VERSION_MINOR)
LIST(GET VERSION_PARTS 2 VERSION_PATCH)
SET(SOVERSION "${VERSION_MAJOR}.${VERSION_MINOR}")

# Postfix of so's:
SET(DLLVERSION "")
SET(DEBUG_POSTFIX "")
