<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="fi_FI">
<context>
    <name>About</name>
    <message>
        <location filename="about.ui" line="14"/>
        <source>About Cppcheck</source>
        <translation>Tietoa ohjelmasta Cppcheck</translation>
    </message>
    <message>
        <location filename="about.ui" line="64"/>
        <source>Version %1</source>
        <translation>Versio %1</translation>
    </message>
    <message>
        <location filename="about.ui" line="71"/>
        <source>Cppcheck - A tool for static C/C++ code analysis.</source>
        <translation>Cppcheck - Työkalu C/C++ koodin staattiseen analysointiin.</translation>
    </message>
    <message utf8="true">
        <location filename="about.ui" line="81"/>
        <source>Copyright © 2007-2012 Daniel Marjamäki and cppcheck team.</source>
        <oldsource>Copyright © 2007-2011 Daniel Marjamäki and cppcheck team.</oldsource>
        <translation type="unfinished">Copyright (C) 2007-2009 Daniel Marjamäki ja cppcheck tiimi.</translation>
    </message>
    <message>
        <location filename="about.ui" line="91"/>
        <source>This program is licensed under the terms
of the GNU General Public License version 3</source>
        <translation>Tämä ohjelma on lisensoitu GNU General
Public lisenssin version 3 alaisuuteen</translation>
    </message>
    <message>
        <location filename="about.ui" line="102"/>
        <source>Visit Cppcheck homepage at %1</source>
        <translation>Cppcheckin kotisivu löytyy osoitteesta %1</translation>
    </message>
</context>
<context>
    <name>ApplicationDialog</name>
    <message>
        <location filename="application.ui" line="23"/>
        <source>Add an application</source>
        <translation>Lisää uusi ohjelma</translation>
    </message>
    <message>
        <location filename="application.ui" line="41"/>
        <source>Here you can add an application that can open error files. Specify a name for the application, the application executable and command line parameters for the application.

The following texts in parameters are replaced with appropriate values when application is executed:
(file) - Filename containing the error
(line) - Line number containing the error
(message) - Error message
(severity) - Error severity

Example opening a file with Kate and make Kate scroll to the correct line:
Executable: kate
Parameters: -l(line) (file)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="application.ui" line="76"/>
        <source>&amp;Name:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="application.ui" line="86"/>
        <source>&amp;Executable:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="application.ui" line="96"/>
        <source>&amp;Parameters:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="application.ui" line="138"/>
        <source>Browse</source>
        <translation>Selaa</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="57"/>
        <source>Executable files (*.exe);;All files(*.*)</source>
        <translation>Suoritettavat tiedostot (*.exe);;Kaikki tiedostot(*.*)</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="60"/>
        <source>Select viewer application</source>
        <translation>Valitse ohjelma jolla avata virhetiedosto</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="84"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="85"/>
        <source>You must specify a name, a path and parameters for the application!</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>FileViewDialog</name>
    <message>
        <location filename="fileviewdialog.cpp" line="42"/>
        <source>Could not find the file: %1</source>
        <oldsource>Could not find the file:
</oldsource>
        <translation>Tiedostoa %1 ei löytynyt</translation>
    </message>
    <message>
        <location filename="fileviewdialog.cpp" line="46"/>
        <location filename="fileviewdialog.cpp" line="60"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="fileviewdialog.cpp" line="56"/>
        <source>Could not read the file: %1</source>
        <translation>Tiedoston %1 lukeminen epäonnistui</translation>
    </message>
</context>
<context>
    <name>LogView</name>
    <message>
        <location filename="logview.ui" line="17"/>
        <source>Checking Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="logview.ui" line="48"/>
        <source>&amp;Save</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="logview.ui" line="55"/>
        <source>Clear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="logview.ui" line="62"/>
        <source>Close</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="logview.cpp" line="66"/>
        <source>Save Log</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="logview.cpp" line="67"/>
        <source>Text files (*.txt *.log);;All files (*.*)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="logview.cpp" line="71"/>
        <source>Cppcheck</source>
        <translation type="unfinished">Cppcheck</translation>
    </message>
    <message>
        <location filename="logview.cpp" line="72"/>
        <source>Could not open file for writing: &quot;%1&quot;</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="main.ui" line="26"/>
        <location filename="mainwindow.cpp" line="248"/>
        <location filename="mainwindow.cpp" line="309"/>
        <location filename="mainwindow.cpp" line="339"/>
        <location filename="mainwindow.cpp" line="406"/>
        <location filename="mainwindow.cpp" line="428"/>
        <location filename="mainwindow.cpp" line="616"/>
        <location filename="mainwindow.cpp" line="707"/>
        <location filename="mainwindow.cpp" line="826"/>
        <location filename="mainwindow.cpp" line="846"/>
        <location filename="mainwindow.cpp" line="992"/>
        <location filename="mainwindow.cpp" line="1073"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="main.ui" line="158"/>
        <source>Standard</source>
        <translation>Vakio</translation>
    </message>
    <message>
        <location filename="main.ui" line="74"/>
        <source>&amp;File</source>
        <translation>&amp;Tiedosto</translation>
    </message>
    <message>
        <location filename="main.ui" line="89"/>
        <source>&amp;View</source>
        <translation>&amp;Näytä</translation>
    </message>
    <message>
        <location filename="main.ui" line="93"/>
        <source>&amp;Toolbars</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="130"/>
        <source>&amp;Check</source>
        <translation>&amp;Tarkista</translation>
    </message>
    <message>
        <location filename="main.ui" line="145"/>
        <source>&amp;Edit</source>
        <translation>&amp;Muokkaa</translation>
    </message>
    <message>
        <location filename="main.ui" line="205"/>
        <source>&amp;License...</source>
        <translation>&amp;Lisenssi...</translation>
    </message>
    <message>
        <location filename="main.ui" line="210"/>
        <source>A&amp;uthors...</source>
        <translation>&amp;Tekijät...</translation>
    </message>
    <message>
        <location filename="main.ui" line="219"/>
        <source>&amp;About...</source>
        <translation>&amp;Tietoa ohjelmasta Cppcheck...</translation>
    </message>
    <message>
        <location filename="main.ui" line="224"/>
        <source>&amp;Files...</source>
        <translation>&amp;Tiedostot...</translation>
    </message>
    <message>
        <location filename="main.ui" line="227"/>
        <location filename="main.ui" line="230"/>
        <source>Check files</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="233"/>
        <source>Ctrl+F</source>
        <translation>Ctrl+F</translation>
    </message>
    <message>
        <location filename="main.ui" line="242"/>
        <source>&amp;Directory...</source>
        <translation>&amp;Hakemisto...</translation>
    </message>
    <message>
        <location filename="main.ui" line="245"/>
        <location filename="main.ui" line="248"/>
        <source>Check directory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="251"/>
        <source>Ctrl+D</source>
        <translation>Ctrl+D</translation>
    </message>
    <message>
        <location filename="main.ui" line="260"/>
        <source>&amp;Recheck files</source>
        <translation>Tarkista tiedostot &amp;uudelleen</translation>
    </message>
    <message>
        <location filename="main.ui" line="263"/>
        <source>Ctrl+R</source>
        <translation>Ctrl+R</translation>
    </message>
    <message>
        <location filename="main.ui" line="272"/>
        <source>&amp;Stop</source>
        <translation>&amp;Pysäytä</translation>
    </message>
    <message>
        <location filename="main.ui" line="275"/>
        <location filename="main.ui" line="278"/>
        <source>Stop checking</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="281"/>
        <source>Esc</source>
        <translation>Esc</translation>
    </message>
    <message>
        <location filename="main.ui" line="290"/>
        <source>&amp;Save results to file...</source>
        <translation>&amp;Tallenna tulokset tiedostoon...</translation>
    </message>
    <message>
        <location filename="main.ui" line="293"/>
        <source>Ctrl+S</source>
        <translation>Ctrl+S</translation>
    </message>
    <message>
        <location filename="main.ui" line="298"/>
        <source>&amp;Quit</source>
        <translation>&amp;Lopeta</translation>
    </message>
    <message>
        <location filename="main.ui" line="307"/>
        <source>&amp;Clear results</source>
        <translation>&amp;Tyhjennä tulokset</translation>
    </message>
    <message>
        <location filename="main.ui" line="316"/>
        <source>&amp;Preferences</source>
        <translation>&amp;Asetukset</translation>
    </message>
    <message>
        <location filename="main.ui" line="346"/>
        <source>Errors</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="349"/>
        <location filename="main.ui" line="352"/>
        <source>Show errors</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="474"/>
        <source>Warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="477"/>
        <location filename="main.ui" line="480"/>
        <source>Show warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="492"/>
        <source>Performance warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="495"/>
        <location filename="main.ui" line="498"/>
        <source>Show performance warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="506"/>
        <source>Show &amp;hidden</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="518"/>
        <source>Information</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="521"/>
        <source>Show information messages</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="533"/>
        <source>Portability</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="536"/>
        <source>Show portability warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="544"/>
        <source>&amp;Filter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="547"/>
        <source>Filter results</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="563"/>
        <source>Windows 32-bit ANSI</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="571"/>
        <source>Windows 32-bit Unicode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="579"/>
        <source>Unix 32-bit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="587"/>
        <source>Unix 64-bit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="595"/>
        <source>Windows 64-bit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="603"/>
        <source>Platforms</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="614"/>
        <source>C++11</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="622"/>
        <source>C99</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="630"/>
        <source>Posix</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="357"/>
        <source>&amp;Check all</source>
        <translation>&amp;Valitse kaikki</translation>
    </message>
    <message>
        <location filename="main.ui" line="194"/>
        <source>Filter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="362"/>
        <source>&amp;Uncheck all</source>
        <translation>&amp;Poista kaikista valinta</translation>
    </message>
    <message>
        <location filename="main.ui" line="367"/>
        <source>Collapse &amp;all</source>
        <translation>&amp;Pienennä kaikki</translation>
    </message>
    <message>
        <location filename="main.ui" line="372"/>
        <source>&amp;Expand all</source>
        <translation>&amp;Laajenna kaikki</translation>
    </message>
    <message>
        <location filename="main.ui" line="380"/>
        <source>&amp;Standard</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="383"/>
        <source>Standard items</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="399"/>
        <source>Toolbar</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="407"/>
        <source>&amp;Categories</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="410"/>
        <source>Error categories</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="415"/>
        <source>&amp;Open XML...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="424"/>
        <source>Open P&amp;roject File...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="429"/>
        <source>&amp;New Project File...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="434"/>
        <source>&amp;Log View</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="437"/>
        <source>Log View</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="445"/>
        <source>C&amp;lose Project File</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="453"/>
        <source>&amp;Edit Project File...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="462"/>
        <source>&amp;Statistics</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="388"/>
        <source>&amp;Contents</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="177"/>
        <source>Categories</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="328"/>
        <source>Style warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="331"/>
        <location filename="main.ui" line="334"/>
        <source>Show style warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="391"/>
        <source>Open the help contents</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="394"/>
        <source>F1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="120"/>
        <source>&amp;Help</source>
        <translation>&amp;Ohje</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="371"/>
        <source>Select directory to check</source>
        <translation>Valitse tarkistettava hakemisto</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="310"/>
        <source>No suitable files found to check!</source>
        <translation>Tarkistettavaksi sopivia tiedostoja ei löytynyt!</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="71"/>
        <source>Quick Filter:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="407"/>
        <source>Found project file: %1

Do you want to load this project file instead?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="429"/>
        <source>Found project files from the directory.

Do you want to proceed checking without using any of these project files?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="749"/>
        <source>License</source>
        <translation>Lisenssi</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="756"/>
        <source>Authors</source>
        <translation>Tekijät</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="764"/>
        <source>XML files version 2 (*.xml);;XML files version 1 (*.xml);;Text files (*.txt);;CSV files (*.csv)</source>
        <oldsource>XML files (*.xml);;Text files (*.txt);;CSV files (*.csv)</oldsource>
        <translation type="unfinished">XML-tiedostot (*.xml);;Tekstitiedostot (*.txt);;CSV-tiedostot (*.csv)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="766"/>
        <source>Save the report file</source>
        <translation>Tallenna raportti</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="632"/>
        <source>XML files (*.xml)</source>
        <translation>XML-tiedostot (*xml)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="243"/>
        <source>There was a problem with loading the editor application settings.

This is probably because the settings were changed between the Cppcheck versions. Please check (and fix) the editor application settings, otherwise the editor program might not start correctly.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="340"/>
        <source>You must close the project file before selecting new files or directories!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="617"/>
        <source>Current results will be cleared.

Opening a new XML file will clear current results.Do you want to proceed?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="634"/>
        <source>Open the report file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="703"/>
        <source>Checking is running.

Do you want to stop the checking and exit Cppcheck?.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="773"/>
        <source>XML files version 1 (*.xml)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="777"/>
        <source>XML files version 2 (*.xml)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="781"/>
        <source>Text files (*.txt)</source>
        <translation>Tekstitiedostot (*.txt)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="785"/>
        <source>CSV files (*.csv)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="828"/>
        <source>Cppcheck - %1</source>
        <translation>Cppcheck - %1</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="840"/>
        <source>Failed to change the user interface language:

%1

The user interface language has been reset to English. Open the Preferences-dialog to select any of the available languages.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="884"/>
        <location filename="mainwindow.cpp" line="956"/>
        <source>Project files (*.cppcheck);;All files(*.*)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="886"/>
        <source>Select Project File</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="903"/>
        <location filename="mainwindow.cpp" line="968"/>
        <source>Project:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="958"/>
        <source>Select Project Filename</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="993"/>
        <source>No project file loaded</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="1068"/>
        <source>The project file

%1

 could not be found!

Do you want to remove the file from the recently used projects -list?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="34"/>
        <source>Finnish</source>
        <translation>Suomi</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="33"/>
        <source>English</source>
        <translation>Englanti</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="32"/>
        <source>Dutch</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="35"/>
        <source>French</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="37"/>
        <source>Italian</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="39"/>
        <source>Korean</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="42"/>
        <source>Spanish</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="43"/>
        <source>Swedish</source>
        <translation>Ruotsi</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="36"/>
        <source>German</source>
        <translation>Saksa</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="40"/>
        <source>Russian</source>
        <translation>Venäjä</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="38"/>
        <source>Japanese</source>
        <oldsource>Japanease</oldsource>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="41"/>
        <source>Serbian</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>Platforms</name>
    <message>
        <location filename="platforms.cpp" line="37"/>
        <source>Build-in</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="platforms.cpp" line="38"/>
        <source>Unix 32-bit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="platforms.cpp" line="39"/>
        <source>Unix 64-bit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="platforms.cpp" line="40"/>
        <source>Windows 32-bit ANSI</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="platforms.cpp" line="41"/>
        <source>Windows 32-bit Unicode</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="platforms.cpp" line="42"/>
        <source>Windows 64-bit</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>Project</name>
    <message>
        <location filename="project.cpp" line="71"/>
        <location filename="project.cpp" line="115"/>
        <source>Cppcheck</source>
        <translation type="unfinished">Cppcheck</translation>
    </message>
    <message>
        <location filename="project.cpp" line="72"/>
        <source>Could not read the project file.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="project.cpp" line="116"/>
        <source>Could not write the project file.</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ProjectFile</name>
    <message>
        <location filename="projectfile.ui" line="14"/>
        <source>Project File</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="24"/>
        <source>Project</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="49"/>
        <source>Root:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="68"/>
        <location filename="projectfile.ui" line="217"/>
        <source>Paths:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="95"/>
        <location filename="projectfile.ui" line="158"/>
        <location filename="projectfile.ui" line="231"/>
        <source>Add...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="102"/>
        <location filename="projectfile.ui" line="165"/>
        <location filename="projectfile.ui" line="238"/>
        <source>Edit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="109"/>
        <location filename="projectfile.ui" line="172"/>
        <location filename="projectfile.ui" line="245"/>
        <source>Remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="134"/>
        <source>Includes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="140"/>
        <source>Include directories:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="192"/>
        <source>Up</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="199"/>
        <source>Down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="211"/>
        <source>Exclude</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="32"/>
        <source>Defines:</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ProjectFileDialog</name>
    <message>
        <location filename="projectfiledialog.cpp" line="38"/>
        <source>Project file: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfiledialog.cpp" line="209"/>
        <source>Select include directory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfiledialog.cpp" line="232"/>
        <source>Select a directory to check</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfiledialog.cpp" line="272"/>
        <source>Select directory to ignore</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="translationhandler.cpp" line="77"/>
        <source>Unknown language specified!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="89"/>
        <source>Language file %1 not found!</source>
        <oldsource>Language file %1.qm not found!</oldsource>
        <translation>Käännöstiedostoa %1 ei löytynyt!</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="95"/>
        <source>Failed to load translation for language %1 from file %2</source>
        <oldsource>Failed to load translation for language %1 from file %2.qm</oldsource>
        <translation>Käänöksen lataaminen kielelle %1 tiedostosta %2 epäonnistui</translation>
    </message>
</context>
<context>
    <name>ResultsTree</name>
    <message>
        <location filename="resultstree.cpp" line="55"/>
        <location filename="resultstree.cpp" line="987"/>
        <source>File</source>
        <translation>Tiedosto</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="55"/>
        <location filename="resultstree.cpp" line="987"/>
        <source>Severity</source>
        <translation>Tyyppi</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="55"/>
        <location filename="resultstree.cpp" line="987"/>
        <source>Line</source>
        <translation>Rivi</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="55"/>
        <location filename="resultstree.cpp" line="987"/>
        <source>Summary</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="103"/>
        <source>Undefined file</source>
        <translation>Määrittelemätön tiedosto</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="205"/>
        <location filename="resultstree.cpp" line="728"/>
        <source>[Inconclusive]</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="279"/>
        <source>debug</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="543"/>
        <source>Copy filename</source>
        <translation>Kopioi tiedostonimi</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="544"/>
        <source>Copy full path</source>
        <translation>Kopioi tiedoston koko polku</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="545"/>
        <source>Copy message</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="546"/>
        <source>Hide</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="589"/>
        <location filename="resultstree.cpp" line="603"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="590"/>
        <source>No editor application configured.

Configure the editor application for Cppcheck in preferences/Applications.</source>
        <oldsource>Configure the text file viewer program in Cppcheck preferences/Applications.</oldsource>
        <translation type="unfinished">Voit asetuksista määritellä muita ohjelmia joilla avata tämän virheen sisältävän tiedoston.</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="604"/>
        <source>No default editor application selected.

Please select the default editor application in preferences/Applications.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="633"/>
        <source>Could not find the file!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="679"/>
        <source>Could not start %1

Please check the application path and parameters are correct.</source>
        <translation>Ohjelman %1 käynnistäminen epäonnistui

Tarkista että ohjelman polku ja parametrit ovat oikeat.</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="693"/>
        <source>Could not find file:
%1
Please select the directory where file is located.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="700"/>
        <source>Select Directory</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="255"/>
        <source>style</source>
        <translation>Tyyli</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="259"/>
        <source>error</source>
        <translation>Yleinen</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="263"/>
        <source>warning</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="267"/>
        <source>performance</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="271"/>
        <source>portability</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="275"/>
        <source>information</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ResultsView</name>
    <message>
        <location filename="resultsview.cpp" line="199"/>
        <source>%p% (%1 of %2 files checked)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="212"/>
        <location filename="resultsview.cpp" line="223"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="213"/>
        <source>No errors found.</source>
        <translation>Virheitä ei löytynyt.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="220"/>
        <source>Errors were found, but they are configured to be hidden.
To toggle what kind of errors are shown, open view menu.</source>
        <translation>Virheitä löytyi, mutta asetuksissa kyseiset virheet on määritelty piilotettavaksi.
Määrittääksesi minkä tyyppisiä virheitä näytetään, avaa näkymä valikko.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="266"/>
        <location filename="resultsview.cpp" line="284"/>
        <location filename="resultsview.cpp" line="292"/>
        <source>Failed to read the report.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="329"/>
        <source>Summary</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="330"/>
        <source>Message</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="139"/>
        <source>No errors found, nothing to save.</source>
        <translation>Virheitä ei löytynyt, ei mitään tallennettavaa.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="166"/>
        <location filename="resultsview.cpp" line="174"/>
        <source>Failed to save the report.</source>
        <translation>Raportin tallentaminen epäonnistui.</translation>
    </message>
    <message>
        <location filename="resultsview.ui" line="26"/>
        <source>Results</source>
        <translation>Tulokset</translation>
    </message>
</context>
<context>
    <name>SelectFilesDialog</name>
    <message>
        <location filename="selectfilesdialog.ui" line="14"/>
        <source>Select files to check</source>
        <translation type="unfinished">Valitse tarkistettavat tiedostot</translation>
    </message>
    <message>
        <location filename="selectfilesdialog.cpp" line="230"/>
        <source>Check</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>Settings</name>
    <message>
        <location filename="settings.ui" line="14"/>
        <source>Preferences</source>
        <translation>Asetukset</translation>
    </message>
    <message>
        <location filename="settings.ui" line="24"/>
        <source>General</source>
        <translation>Yleiset</translation>
    </message>
    <message>
        <location filename="settings.ui" line="162"/>
        <source>Include paths:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="180"/>
        <location filename="settings.ui" line="232"/>
        <source>Add...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="41"/>
        <source>Number of threads: </source>
        <translation>Säikeiden lukumäärä: </translation>
    </message>
    <message>
        <location filename="settings.ui" line="85"/>
        <source>Ideal count:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="114"/>
        <source>Force checking all #ifdef configurations</source>
        <oldsource>Check all #ifdef configurations</oldsource>
        <translation type="unfinished">Tarkista kaikki #ifdef kombinaatiot</translation>
    </message>
    <message>
        <location filename="settings.ui" line="121"/>
        <source>Show full path of files</source>
        <translation>Näytä tiedostojen täysi polku</translation>
    </message>
    <message>
        <location filename="settings.ui" line="128"/>
        <source>Show &quot;No errors found&quot; message when no errors found</source>
        <translation>Näytä &quot;virheitä ei löytynyt&quot;-viesti jos virheitä ei löydy</translation>
    </message>
    <message>
        <location filename="settings.ui" line="135"/>
        <source>Enable inline suppressions</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="156"/>
        <source>Paths</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="187"/>
        <source>Edit</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="194"/>
        <location filename="settings.ui" line="246"/>
        <source>Remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="219"/>
        <source>Applications</source>
        <translation>Ohjelmat</translation>
    </message>
    <message>
        <location filename="settings.ui" line="239"/>
        <source>Edit...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="253"/>
        <source>Set as default</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="278"/>
        <source>Reports</source>
        <translation>Raportit</translation>
    </message>
    <message>
        <location filename="settings.ui" line="284"/>
        <source>Save all errors when creating report</source>
        <translation>Tallenna kaikki virheet raporttia luodessa</translation>
    </message>
    <message>
        <location filename="settings.ui" line="291"/>
        <source>Save full path to files in reports</source>
        <translation>Tallenna tiedostojen koko polku raportteihin</translation>
    </message>
    <message>
        <location filename="settings.ui" line="312"/>
        <source>Language</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="326"/>
        <source>Advanced</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="332"/>
        <source>&amp;Show inconclusive errors</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settings.ui" line="339"/>
        <source>S&amp;how internal warnings in log</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="settingsdialog.cpp" line="81"/>
        <source>N/A</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="199"/>
        <source>Add a new application</source>
        <translation>Lisää uusi ohjelma</translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="233"/>
        <source>Modify an application</source>
        <translation>Muokkaa ohjelmaa</translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="262"/>
        <source>[Default]</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="308"/>
        <source>Select include directory</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>StatsDialog</name>
    <message>
        <location filename="stats.ui" line="14"/>
        <location filename="stats.ui" line="228"/>
        <location filename="statsdialog.cpp" line="105"/>
        <source>Statistics</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="27"/>
        <location filename="statsdialog.cpp" line="97"/>
        <source>Project</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="33"/>
        <source>Project:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="53"/>
        <source>Paths:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="85"/>
        <source>Include paths:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="108"/>
        <source>Defines:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="145"/>
        <location filename="statsdialog.cpp" line="101"/>
        <source>Previous Scan</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="151"/>
        <source>Path Selected:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="161"/>
        <source>Number of Files Scanned:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="181"/>
        <source>Scan Duration:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="236"/>
        <source>Errors:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="254"/>
        <source>Warnings:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="272"/>
        <source>Stylistic warnings:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="290"/>
        <source>Portability warnings:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="308"/>
        <source>Performance issues:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="326"/>
        <source>Information messages:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="stats.ui" line="365"/>
        <source>Copy to Clipboard</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="77"/>
        <source>1 day</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="77"/>
        <source>%1 days</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="79"/>
        <source>1 hour</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="79"/>
        <source>%1 hours</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="81"/>
        <source>1 minute</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="81"/>
        <source>%1 minutes</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="83"/>
        <source>1 second</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="83"/>
        <source>%1 seconds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="87"/>
        <source>0.%1 seconds</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="89"/>
        <source> and </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="96"/>
        <source>Project Settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="98"/>
        <source>Paths</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="99"/>
        <source>Include paths</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="100"/>
        <source>Defines</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="102"/>
        <source>Path selected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="103"/>
        <source>Number of files scanned</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="104"/>
        <source>Scan duration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="106"/>
        <source>Errors</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="107"/>
        <source>Warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="108"/>
        <source>Style warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="109"/>
        <source>Portability warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="110"/>
        <source>Performance warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="111"/>
        <source>Information messages</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>ThreadResult</name>
    <message>
        <location filename="threadresult.cpp" line="54"/>
        <source>%1 of %2 files checked</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>TxtReport</name>
    <message>
        <location filename="txtreport.cpp" line="75"/>
        <source>inconclusive</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
