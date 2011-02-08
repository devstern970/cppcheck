REM A script to run Astyle for the sources

SET STYLE=--style=ansi --min-conditional-indent=0
SET OPTIONS=--pad-header --unpad-paren --suffix=none

astyle %STYLE% %OPTIONS% cli/*.cpp
astyle %STYLE% %OPTIONS% cli/*.h
astyle %STYLE% %OPTIONS% gui/*.cpp
astyle %STYLE% %OPTIONS% gui/*.h
astyle %STYLE% %OPTIONS% gui/test/*.cpp
astyle %STYLE% %OPTIONS% gui/test/*.h
astyle %STYLE% %OPTIONS% lib/*.cpp
astyle %STYLE% %OPTIONS% lib/*.h
astyle %STYLE% %OPTIONS% test/*.cpp
astyle %STYLE% %OPTIONS% test/*.h

astyle %STYLE% %OPTIONS% tools/*.cpp

