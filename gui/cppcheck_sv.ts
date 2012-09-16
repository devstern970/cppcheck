<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="sv_SE">
<context>
    <name>About</name>
    <message>
        <location filename="about.ui" line="14"/>
        <source>About Cppcheck</source>
        <translation>Om Cppcheck</translation>
    </message>
    <message>
        <location filename="about.ui" line="64"/>
        <source>Version %1</source>
        <translation>Version %1</translation>
    </message>
    <message>
        <location filename="about.ui" line="71"/>
        <source>Cppcheck - A tool for static C/C++ code analysis.</source>
        <translation>Cppcheck - Ett verktyg för statisk analys av C/C++ kod.</translation>
    </message>
    <message utf8="true">
        <location filename="about.ui" line="81"/>
        <source>Copyright © 2007-2012 Daniel Marjamäki and cppcheck team.</source>
        <oldsource>Copyright © 2007-2011 Daniel Marjamäki and cppcheck team.</oldsource>
        <translation type="unfinished">Copyright (C) 2007-2010 Daniel Marjamäki and cppcheck team.</translation>
    </message>
    <message>
        <location filename="about.ui" line="91"/>
        <source>This program is licensed under the terms
of the GNU General Public License version 3</source>
        <translation>This program is licensed under the terms
of the GNU General Public License version 3</translation>
    </message>
    <message>
        <location filename="about.ui" line="102"/>
        <source>Visit Cppcheck homepage at %1</source>
        <translation>Hemsida: %1</translation>
    </message>
</context>
<context>
    <name>ApplicationDialog</name>
    <message>
        <location filename="application.ui" line="23"/>
        <source>Add an application</source>
        <translation>Lägg till program</translation>
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
        <translation>Här kan du ange en applikation som kan användas för att visa fel. Ange applikationens namn, körbara fil samt kommandorads parametrar.

Följande texter i parametrarna ersätts med motsvarande värden när applikationen körs:
(file) - filnamn för källkodsfil
(line) - radnummer
(message) - felmeddelande
(severity) - typ / svårighetsgrad

Exempel för att öppna en fil med Kate och ange att Kate skall skrolla till rätt rad:
Körbar fil: kate
Parametrar: -l(line) (file)</translation>
    </message>
    <message>
        <location filename="application.ui" line="76"/>
        <source>&amp;Name:</source>
        <translation>Namn:</translation>
    </message>
    <message>
        <location filename="application.ui" line="86"/>
        <source>&amp;Executable:</source>
        <translation>Körbar fil:</translation>
    </message>
    <message>
        <location filename="application.ui" line="96"/>
        <source>&amp;Parameters:</source>
        <translation>Parametrar:</translation>
    </message>
    <message>
        <location filename="application.ui" line="138"/>
        <source>Browse</source>
        <translation>Bläddra</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="58"/>
        <source>Executable files (*.exe);;All files(*.*)</source>
        <translation>Exekverbara filer (*.exe);;Alla filer(*.*)</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="61"/>
        <source>Select viewer application</source>
        <translation>Välj program</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="85"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="applicationdialog.cpp" line="86"/>
        <source>You must specify a name, a path and parameters for the application!</source>
        <translation>Du måste ange ett namn, en sökväg samt parametrar för programmet!</translation>
    </message>
</context>
<context>
    <name>FileViewDialog</name>
    <message>
        <location filename="fileviewdialog.cpp" line="42"/>
        <source>Could not find the file: %1</source>
        <oldsource>Could not find the file:
</oldsource>
        <translation>Kunde inte hitta filen: %1</translation>
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
        <translation>Kunde inte läsa filen: %1</translation>
    </message>
</context>
<context>
    <name>LogView</name>
    <message>
        <location filename="logview.ui" line="17"/>
        <source>Checking Log</source>
        <translation>Analys logg</translation>
    </message>
    <message>
        <location filename="logview.ui" line="48"/>
        <source>&amp;Save</source>
        <translation>&amp;Spara</translation>
    </message>
    <message>
        <location filename="logview.ui" line="55"/>
        <source>Clear</source>
        <translation>Töm</translation>
    </message>
    <message>
        <location filename="logview.ui" line="62"/>
        <source>Close</source>
        <translation>Stäng</translation>
    </message>
    <message>
        <location filename="logview.cpp" line="66"/>
        <source>Save Log</source>
        <translation>Spara logg</translation>
    </message>
    <message>
        <location filename="logview.cpp" line="67"/>
        <source>Text files (*.txt *.log);;All files (*.*)</source>
        <translation>Text filer (*.txt *.log);;Alla filer (*.*)</translation>
    </message>
    <message>
        <location filename="logview.cpp" line="71"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="logview.cpp" line="72"/>
        <source>Could not open file for writing: &quot;%1&quot;</source>
        <translation>Kunde ej öppna fil för skrivning: &quot;%1&quot;</translation>
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
        <location filename="mainwindow.cpp" line="987"/>
        <location filename="mainwindow.cpp" line="1068"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="main.ui" line="158"/>
        <source>Standard</source>
        <translation>Standard</translation>
    </message>
    <message>
        <location filename="main.ui" line="74"/>
        <source>&amp;File</source>
        <translation>&amp;Arkiv</translation>
    </message>
    <message>
        <location filename="main.ui" line="89"/>
        <source>&amp;View</source>
        <translation>&amp;Visa</translation>
    </message>
    <message>
        <location filename="main.ui" line="93"/>
        <source>&amp;Toolbars</source>
        <translation>Verktygsfält</translation>
    </message>
    <message>
        <location filename="main.ui" line="130"/>
        <source>&amp;Check</source>
        <translation>&amp;Check</translation>
    </message>
    <message>
        <location filename="main.ui" line="145"/>
        <source>&amp;Edit</source>
        <translation>&amp;Redigera</translation>
    </message>
    <message>
        <location filename="main.ui" line="205"/>
        <source>&amp;License...</source>
        <translation>&amp;Licens...</translation>
    </message>
    <message>
        <location filename="main.ui" line="210"/>
        <source>A&amp;uthors...</source>
        <translation>&amp;Utvecklat av...</translation>
    </message>
    <message>
        <location filename="main.ui" line="219"/>
        <source>&amp;About...</source>
        <translation>&amp;Om...</translation>
    </message>
    <message>
        <location filename="main.ui" line="224"/>
        <source>&amp;Files...</source>
        <translation>&amp;Filer...</translation>
    </message>
    <message>
        <location filename="main.ui" line="227"/>
        <location filename="main.ui" line="230"/>
        <source>Check files</source>
        <translation>Analysera filer</translation>
    </message>
    <message>
        <location filename="main.ui" line="233"/>
        <source>Ctrl+F</source>
        <translation>Ctrl+F</translation>
    </message>
    <message>
        <location filename="main.ui" line="242"/>
        <source>&amp;Directory...</source>
        <translation>&amp;Katalog...</translation>
    </message>
    <message>
        <location filename="main.ui" line="245"/>
        <location filename="main.ui" line="248"/>
        <source>Check directory</source>
        <translation>Analysera mapp</translation>
    </message>
    <message>
        <location filename="main.ui" line="251"/>
        <source>Ctrl+D</source>
        <translation>Ctrl+D</translation>
    </message>
    <message>
        <location filename="main.ui" line="260"/>
        <source>&amp;Recheck files</source>
        <translation>Starta &amp;om check</translation>
    </message>
    <message>
        <location filename="main.ui" line="263"/>
        <source>Ctrl+R</source>
        <translation>Ctrl+R</translation>
    </message>
    <message>
        <location filename="main.ui" line="272"/>
        <source>&amp;Stop</source>
        <translation>&amp;Stoppa</translation>
    </message>
    <message>
        <location filename="main.ui" line="275"/>
        <location filename="main.ui" line="278"/>
        <source>Stop checking</source>
        <translation>Stoppa analys</translation>
    </message>
    <message>
        <location filename="main.ui" line="281"/>
        <source>Esc</source>
        <translation>Esc</translation>
    </message>
    <message>
        <location filename="main.ui" line="290"/>
        <source>&amp;Save results to file...</source>
        <translation>&amp;Spara resultat till fil...</translation>
    </message>
    <message>
        <location filename="main.ui" line="293"/>
        <source>Ctrl+S</source>
        <translation>Ctrl+S</translation>
    </message>
    <message>
        <location filename="main.ui" line="298"/>
        <source>&amp;Quit</source>
        <translation>&amp;Avsluta</translation>
    </message>
    <message>
        <location filename="main.ui" line="307"/>
        <source>&amp;Clear results</source>
        <translation>&amp;Töm resultat</translation>
    </message>
    <message>
        <location filename="main.ui" line="316"/>
        <source>&amp;Preferences</source>
        <translation>&amp;Inställningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="346"/>
        <source>Errors</source>
        <translation>Fel</translation>
    </message>
    <message>
        <location filename="main.ui" line="349"/>
        <location filename="main.ui" line="352"/>
        <source>Show errors</source>
        <translation>Visa fel</translation>
    </message>
    <message>
        <location filename="main.ui" line="474"/>
        <source>Warnings</source>
        <translation>Varningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="477"/>
        <location filename="main.ui" line="480"/>
        <source>Show warnings</source>
        <translation>Visa varningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="492"/>
        <source>Performance warnings</source>
        <translation>Prestanda varningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="495"/>
        <location filename="main.ui" line="498"/>
        <source>Show performance warnings</source>
        <translation>Visa prestanda varningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="506"/>
        <source>Show &amp;hidden</source>
        <translation>Visa dolda</translation>
    </message>
    <message>
        <location filename="main.ui" line="518"/>
        <source>Information</source>
        <translation>Information</translation>
    </message>
    <message>
        <location filename="main.ui" line="521"/>
        <source>Show information messages</source>
        <translation>Visa informations meddelanden</translation>
    </message>
    <message>
        <location filename="main.ui" line="533"/>
        <source>Portability</source>
        <translation>Portabilitet</translation>
    </message>
    <message>
        <location filename="main.ui" line="536"/>
        <source>Show portability warnings</source>
        <translation>Visa portabilitets varningar</translation>
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
        <location filename="main.ui" line="552"/>
        <source>Project MRU placeholder</source>
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
        <translation>&amp;Kryssa alla</translation>
    </message>
    <message>
        <location filename="main.ui" line="194"/>
        <source>Filter</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="main.ui" line="362"/>
        <source>&amp;Uncheck all</source>
        <translation>Kryssa &amp;ur alla</translation>
    </message>
    <message>
        <location filename="main.ui" line="367"/>
        <source>Collapse &amp;all</source>
        <translatorcomment>Ingen bra översättning!</translatorcomment>
        <translation>&amp;Fäll ihop alla</translation>
    </message>
    <message>
        <location filename="main.ui" line="372"/>
        <source>&amp;Expand all</source>
        <translation>&amp;Expandera alla</translation>
    </message>
    <message>
        <location filename="main.ui" line="380"/>
        <source>&amp;Standard</source>
        <translation>&amp;Standard</translation>
    </message>
    <message>
        <location filename="main.ui" line="383"/>
        <source>Standard items</source>
        <translation>Standard poster</translation>
    </message>
    <message>
        <location filename="main.ui" line="399"/>
        <source>Toolbar</source>
        <translation>Verktygsfält</translation>
    </message>
    <message>
        <location filename="main.ui" line="407"/>
        <source>&amp;Categories</source>
        <translation>&amp;Kategorier</translation>
    </message>
    <message>
        <location filename="main.ui" line="410"/>
        <source>Error categories</source>
        <translation>Fel kategorier</translation>
    </message>
    <message>
        <location filename="main.ui" line="415"/>
        <source>&amp;Open XML...</source>
        <translation>&amp;Öppna XML...</translation>
    </message>
    <message>
        <location filename="main.ui" line="424"/>
        <source>Open P&amp;roject File...</source>
        <translation>Öppna Projektfil...</translation>
    </message>
    <message>
        <location filename="main.ui" line="429"/>
        <source>&amp;New Project File...</source>
        <translation>Ny projektfil...</translation>
    </message>
    <message>
        <location filename="main.ui" line="434"/>
        <source>&amp;Log View</source>
        <translation></translation>
    </message>
    <message>
        <location filename="main.ui" line="437"/>
        <source>Log View</source>
        <translation>Logg vy</translation>
    </message>
    <message>
        <location filename="main.ui" line="445"/>
        <source>C&amp;lose Project File</source>
        <translation>Stäng projektfil</translation>
    </message>
    <message>
        <location filename="main.ui" line="453"/>
        <source>&amp;Edit Project File...</source>
        <translation>Redigera projektfil...</translation>
    </message>
    <message>
        <location filename="main.ui" line="462"/>
        <source>&amp;Statistics</source>
        <translation>Statistik</translation>
    </message>
    <message>
        <location filename="main.ui" line="388"/>
        <source>&amp;Contents</source>
        <translation>&amp;Innehåll</translation>
    </message>
    <message>
        <location filename="main.ui" line="177"/>
        <source>Categories</source>
        <translation>Kategorier</translation>
    </message>
    <message>
        <location filename="main.ui" line="328"/>
        <source>Style warnings</source>
        <translation>Stil varningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="331"/>
        <location filename="main.ui" line="334"/>
        <source>Show style warnings</source>
        <translation>Visa stil varningar</translation>
    </message>
    <message>
        <location filename="main.ui" line="391"/>
        <source>Open the help contents</source>
        <translation>Öppna hjälp</translation>
    </message>
    <message>
        <location filename="main.ui" line="394"/>
        <source>F1</source>
        <translation>F1</translation>
    </message>
    <message>
        <location filename="main.ui" line="120"/>
        <source>&amp;Help</source>
        <translation>&amp;Hjälp</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="371"/>
        <source>Select directory to check</source>
        <translation>Välj katalog som skall kontrolleras</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="310"/>
        <source>No suitable files found to check!</source>
        <translation>Inga lämpliga filer hittades!</translation>
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
        <translation>Licens</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="756"/>
        <source>Authors</source>
        <translation>Utvecklare</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="764"/>
        <source>XML files version 2 (*.xml);;XML files version 1 (*.xml);;Text files (*.txt);;CSV files (*.csv)</source>
        <oldsource>XML files (*.xml);;Text files (*.txt);;CSV files (*.csv)</oldsource>
        <translation>XML filer version 2 (*.xml);;XML filer version 1 (*.xml);;Text filer (*.txt);;CSV filer (*.csv)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="766"/>
        <source>Save the report file</source>
        <translation>Spara rapport</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="632"/>
        <source>XML files (*.xml)</source>
        <translation>XML filer (*.xml)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="243"/>
        <source>There was a problem with loading the editor application settings.

This is probably because the settings were changed between the Cppcheck versions. Please check (and fix) the editor application settings, otherwise the editor program might not start correctly.</source>
        <translation>Det uppstod ett problem när programinställningarna skulle laddas.

En trolig orsak är att inställningarna ändrats för olika Cppcheck versioner. Kontrollera programinställningarna.</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="340"/>
        <source>You must close the project file before selecting new files or directories!</source>
        <translation>Du måste stänga projektfilen innan nya filer eller sökvägar kan väljas!</translation>
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
        <translation>Öppna rapportfilen</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="703"/>
        <source>Checking is running.

Do you want to stop the checking and exit Cppcheck?.</source>
        <translation>Cppcheck kör.

Vill du stoppa analysen och avsluta Cppcheck?</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="773"/>
        <source>XML files version 1 (*.xml)</source>
        <translation>XML filer version 1 (*.xml)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="777"/>
        <source>XML files version 2 (*.xml)</source>
        <translation>XML filer version 2 (*.xml)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="781"/>
        <source>Text files (*.txt)</source>
        <translation>Text filer (*.txt)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="785"/>
        <source>CSV files (*.csv)</source>
        <translation>CSV filer (*.csv)</translation>
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
        <translation>Misslyckades att ändra språk:

%1

Språket har nollställts till Engelska. Öppna Preferences och välj något av de tillgängliga språken.</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="884"/>
        <location filename="mainwindow.cpp" line="951"/>
        <source>Project files (*.cppcheck);;All files(*.*)</source>
        <translation>Projektfiler (*.cppcheck);;Alla filer(*.*)</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="886"/>
        <source>Select Project File</source>
        <translation>Välj projektfil</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="903"/>
        <location filename="mainwindow.cpp" line="963"/>
        <source>Project:</source>
        <translation type="unfinished">Projekt:</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="953"/>
        <source>Select Project Filename</source>
        <translation>Välj Projektfil</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="988"/>
        <source>No project file loaded</source>
        <translation>Inget projekt laddat</translation>
    </message>
    <message>
        <location filename="mainwindow.cpp" line="1063"/>
        <source>The project file

%1

 could not be found!

Do you want to remove the file from the recently used projects -list?</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="34"/>
        <source>Finnish</source>
        <translation>Finska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="33"/>
        <source>English</source>
        <translation>Engelska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="32"/>
        <source>Dutch</source>
        <translation>Nederländska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="35"/>
        <source>French</source>
        <translation>Franska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="38"/>
        <source>Korean</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="41"/>
        <source>Spanish</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="42"/>
        <source>Swedish</source>
        <translation>Svenska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="36"/>
        <source>German</source>
        <translation>Tyska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="39"/>
        <source>Russian</source>
        <translation>Ryska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="37"/>
        <source>Japanese</source>
        <oldsource>Japanease</oldsource>
        <translation>Japanska</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="40"/>
        <source>Serbian</source>
        <translation>Serbiska</translation>
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
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="project.cpp" line="72"/>
        <source>Could not read the project file.</source>
        <translation>Kunde ej läsa projektfilen.</translation>
    </message>
    <message>
        <location filename="project.cpp" line="116"/>
        <source>Could not write the project file.</source>
        <translation>Kunde ej skriva projektfilen</translation>
    </message>
</context>
<context>
    <name>ProjectFile</name>
    <message>
        <location filename="projectfile.ui" line="14"/>
        <source>Project File</source>
        <translation>Projektfil</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="24"/>
        <source>Project</source>
        <translation>Projekt</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="51"/>
        <source>Root:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="70"/>
        <location filename="projectfile.ui" line="221"/>
        <source>Paths:</source>
        <translation>Sökvägar:</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="97"/>
        <location filename="projectfile.ui" line="162"/>
        <location filename="projectfile.ui" line="235"/>
        <source>Add...</source>
        <translation>Lägg till...</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="104"/>
        <location filename="projectfile.ui" line="169"/>
        <location filename="projectfile.ui" line="242"/>
        <source>Edit</source>
        <translation>Redigera</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="111"/>
        <location filename="projectfile.ui" line="176"/>
        <location filename="projectfile.ui" line="249"/>
        <source>Remove</source>
        <translation>Ta bort</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="138"/>
        <source>Includes</source>
        <translation>Include</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="144"/>
        <source>Include directories:</source>
        <translation>Include sökvägar</translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="196"/>
        <source>Up</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="203"/>
        <source>Down</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="215"/>
        <source>Exclude</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfile.ui" line="34"/>
        <source>Defines:</source>
        <translation>Defines:</translation>
    </message>
</context>
<context>
    <name>ProjectFileDialog</name>
    <message>
        <location filename="projectfiledialog.cpp" line="39"/>
        <source>Project file: %1</source>
        <translation>Projektfil: %1</translation>
    </message>
    <message>
        <location filename="projectfiledialog.cpp" line="210"/>
        <source>Select include directory</source>
        <translation>Välj include sökväg</translation>
    </message>
    <message>
        <location filename="projectfiledialog.cpp" line="233"/>
        <source>Select a directory to check</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="projectfiledialog.cpp" line="273"/>
        <source>Select directory to ignore</source>
        <translation>Välj sökväg att ignorera</translation>
    </message>
</context>
<context>
    <name>QObject</name>
    <message>
        <location filename="translationhandler.cpp" line="76"/>
        <source>Unknown language specified!</source>
        <translation>Okänt språk valt!</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="88"/>
        <source>Language file %1 not found!</source>
        <oldsource>Language file %1.qm not found!</oldsource>
        <translation>Språk filen %1 hittades ej!</translation>
    </message>
    <message>
        <location filename="translationhandler.cpp" line="94"/>
        <source>Failed to load translation for language %1 from file %2</source>
        <oldsource>Failed to load translation for language %1 from file %2.qm</oldsource>
        <translation>Misslyckades med att ladda översättningen för %1 från filen %2</translation>
    </message>
</context>
<context>
    <name>ResultsTree</name>
    <message>
        <location filename="resultstree.cpp" line="58"/>
        <location filename="resultstree.cpp" line="990"/>
        <source>File</source>
        <translation>Fil</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="58"/>
        <location filename="resultstree.cpp" line="990"/>
        <source>Severity</source>
        <translation>Typ</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="58"/>
        <location filename="resultstree.cpp" line="990"/>
        <source>Line</source>
        <translation>Rad</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="58"/>
        <location filename="resultstree.cpp" line="990"/>
        <source>Summary</source>
        <translation>Sammanfattning</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="106"/>
        <source>Undefined file</source>
        <translation>Odefinierad fil</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="208"/>
        <location filename="resultstree.cpp" line="731"/>
        <source>[Inconclusive]</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="282"/>
        <source>debug</source>
        <translation>debug</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="546"/>
        <source>Copy filename</source>
        <translation>Kopiera filnamn</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="547"/>
        <source>Copy full path</source>
        <translation>Kopiera full sökväg</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="548"/>
        <source>Copy message</source>
        <translation>Kopiera meddelande</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="549"/>
        <source>Hide</source>
        <translation>Dölj</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="592"/>
        <location filename="resultstree.cpp" line="606"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="593"/>
        <source>No editor application configured.

Configure the editor application for Cppcheck in preferences/Applications.</source>
        <oldsource>Configure the text file viewer program in Cppcheck preferences/Applications.</oldsource>
        <translation type="unfinished">Konfigurera program i inställningar/program.</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="607"/>
        <source>No default editor application selected.

Please select the default editor application in preferences/Applications.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="636"/>
        <source>Could not find the file!</source>
        <translation>Kunde inte hitta filen!</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="682"/>
        <source>Could not start %1

Please check the application path and parameters are correct.</source>
        <translation>Kunde inte starta %1

Kontrollera att sökvägen och parametrarna är korrekta.</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="696"/>
        <source>Could not find file:
%1
Please select the directory where file is located.</source>
        <translation>Kunde inte hitta filen:
%1
Välj mappen där filen finns.</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="703"/>
        <source>Select Directory</source>
        <translation>Välj mapp</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="258"/>
        <source>style</source>
        <translation>stil</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="262"/>
        <source>error</source>
        <translation>fel</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="266"/>
        <source>warning</source>
        <translation>varning</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="270"/>
        <source>performance</source>
        <translation>prestanda</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="274"/>
        <source>portability</source>
        <translation>portabilitet</translation>
    </message>
    <message>
        <location filename="resultstree.cpp" line="278"/>
        <source>information</source>
        <translation>information</translation>
    </message>
</context>
<context>
    <name>ResultsView</name>
    <message>
        <location filename="resultsview.cpp" line="202"/>
        <source>%p% (%1 of %2 files checked)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="215"/>
        <location filename="resultsview.cpp" line="226"/>
        <source>Cppcheck</source>
        <translation>Cppcheck</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="216"/>
        <source>No errors found.</source>
        <translation>Inga fel hittades.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="223"/>
        <source>Errors were found, but they are configured to be hidden.
To toggle what kind of errors are shown, open view menu.</source>
        <translation>Fel hittades, men de visas ej.
För att ställa in vilka fel som skall visas använd visa menyn.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="269"/>
        <location filename="resultsview.cpp" line="287"/>
        <location filename="resultsview.cpp" line="295"/>
        <source>Failed to read the report.</source>
        <translation>Misslyckades att läsa rapporten.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="332"/>
        <source>Summary</source>
        <translation>Sammanfattning</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="333"/>
        <source>Message</source>
        <translation>Meddelande</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="142"/>
        <source>No errors found, nothing to save.</source>
        <translation>Inga fel hittades, ingenting att spara.</translation>
    </message>
    <message>
        <location filename="resultsview.cpp" line="169"/>
        <location filename="resultsview.cpp" line="177"/>
        <source>Failed to save the report.</source>
        <translation>Misslyckades med att spara rapporten.</translation>
    </message>
    <message>
        <location filename="resultsview.ui" line="26"/>
        <source>Results</source>
        <translation>Resultat</translation>
    </message>
</context>
<context>
    <name>SelectFilesDialog</name>
    <message>
        <location filename="selectfilesdialog.ui" line="14"/>
        <source>Select files to check</source>
        <translation type="unfinished">Välj filer att kontrollera</translation>
    </message>
    <message>
        <location filename="selectfilesdialog.cpp" line="232"/>
        <source>Check</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>Settings</name>
    <message>
        <location filename="settings.ui" line="14"/>
        <source>Preferences</source>
        <translation>Inställningar</translation>
    </message>
    <message>
        <location filename="settings.ui" line="24"/>
        <source>General</source>
        <translation>Allmänt</translation>
    </message>
    <message>
        <location filename="settings.ui" line="162"/>
        <source>Include paths:</source>
        <translation>Include sökvägar:</translation>
    </message>
    <message>
        <location filename="settings.ui" line="180"/>
        <location filename="settings.ui" line="232"/>
        <source>Add...</source>
        <translation>Lägg till...</translation>
    </message>
    <message>
        <location filename="settings.ui" line="41"/>
        <source>Number of threads: </source>
        <translation>Antal trådar:</translation>
    </message>
    <message>
        <location filename="settings.ui" line="85"/>
        <source>Ideal count:</source>
        <translation>Optimalt värde:</translation>
    </message>
    <message>
        <location filename="settings.ui" line="92"/>
        <source>TextLabel</source>
        <translation>TextLabel</translation>
    </message>
    <message>
        <location filename="settings.ui" line="114"/>
        <source>Force checking all #ifdef configurations</source>
        <oldsource>Check all #ifdef configurations</oldsource>
        <translation>Kontrollera alla #ifdef konfigurationer</translation>
    </message>
    <message>
        <location filename="settings.ui" line="121"/>
        <source>Show full path of files</source>
        <translation>Visa den fulla sökvägen för filer</translation>
    </message>
    <message>
        <location filename="settings.ui" line="128"/>
        <source>Show &quot;No errors found&quot; message when no errors found</source>
        <translation>Visa &quot;Inga fel hittades&quot; meddelande när inga fel hittas</translation>
    </message>
    <message>
        <location filename="settings.ui" line="135"/>
        <source>Enable inline suppressions</source>
        <translation>Använd inline suppressions</translation>
    </message>
    <message>
        <location filename="settings.ui" line="156"/>
        <source>Paths</source>
        <translation>Sökvägar</translation>
    </message>
    <message>
        <location filename="settings.ui" line="187"/>
        <source>Edit</source>
        <translation>Redigera</translation>
    </message>
    <message>
        <location filename="settings.ui" line="194"/>
        <location filename="settings.ui" line="246"/>
        <source>Remove</source>
        <translation>Ta bort</translation>
    </message>
    <message>
        <location filename="settings.ui" line="219"/>
        <source>Applications</source>
        <translation>Program</translation>
    </message>
    <message>
        <location filename="settings.ui" line="239"/>
        <source>Edit...</source>
        <translation>Redigera...</translation>
    </message>
    <message>
        <location filename="settings.ui" line="253"/>
        <source>Set as default</source>
        <translation>Sätt förvald</translation>
    </message>
    <message>
        <location filename="settings.ui" line="278"/>
        <source>Reports</source>
        <translation>Rapporter</translation>
    </message>
    <message>
        <location filename="settings.ui" line="284"/>
        <source>Save all errors when creating report</source>
        <translation>Spara alla fel</translation>
    </message>
    <message>
        <location filename="settings.ui" line="291"/>
        <source>Save full path to files in reports</source>
        <translation>Spara fulla sökvägar</translation>
    </message>
    <message>
        <location filename="settings.ui" line="312"/>
        <source>Language</source>
        <translation>Språk</translation>
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
        <location filename="settingsdialog.cpp" line="84"/>
        <source>N/A</source>
        <translation>Ej tillgängligt</translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="202"/>
        <source>Add a new application</source>
        <translation>Lägg till program</translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="236"/>
        <source>Modify an application</source>
        <translation>Ändra program</translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="265"/>
        <source>[Default]</source>
        <translation>[Förvald]</translation>
    </message>
    <message>
        <location filename="settingsdialog.cpp" line="311"/>
        <source>Select include directory</source>
        <translation>Välj include mapp</translation>
    </message>
</context>
<context>
    <name>StatsDialog</name>
    <message>
        <location filename="stats.ui" line="14"/>
        <location filename="stats.ui" line="228"/>
        <location filename="statsdialog.cpp" line="106"/>
        <source>Statistics</source>
        <translation>Statistik</translation>
    </message>
    <message>
        <location filename="stats.ui" line="27"/>
        <location filename="statsdialog.cpp" line="98"/>
        <source>Project</source>
        <translation>Projekt</translation>
    </message>
    <message>
        <location filename="stats.ui" line="33"/>
        <source>Project:</source>
        <translation>Projekt:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="53"/>
        <source>Paths:</source>
        <translation>Sökvägar:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="85"/>
        <source>Include paths:</source>
        <translation>Include sökvägar:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="108"/>
        <source>Defines:</source>
        <translation>Defines:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="145"/>
        <location filename="statsdialog.cpp" line="102"/>
        <source>Previous Scan</source>
        <translation>Föregående analys</translation>
    </message>
    <message>
        <location filename="stats.ui" line="151"/>
        <source>Path Selected:</source>
        <translation>Vald sökväg:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="161"/>
        <source>Number of Files Scanned:</source>
        <translation>Antal analyserade filer:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="181"/>
        <source>Scan Duration:</source>
        <translation>Analys tid:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="236"/>
        <source>Errors:</source>
        <translation>Fel:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="254"/>
        <source>Warnings:</source>
        <translation>Varningar:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="272"/>
        <source>Stylistic warnings:</source>
        <translation>Stil varningar:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="290"/>
        <source>Portability warnings:</source>
        <translation>Portabilitets varningar:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="297"/>
        <location filename="stats.ui" line="333"/>
        <source>TextLabel</source>
        <translation>TextLabel</translation>
    </message>
    <message>
        <location filename="stats.ui" line="308"/>
        <source>Performance issues:</source>
        <translation>Prestanda varningar:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="326"/>
        <source>Information messages:</source>
        <translation>Informations meddelanden:</translation>
    </message>
    <message>
        <location filename="stats.ui" line="362"/>
        <source>Copy to Clipboard</source>
        <translation>Kopiera</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="78"/>
        <source>1 day</source>
        <translation>1 dag</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="78"/>
        <source>%1 days</source>
        <translation>%1 dagar</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="80"/>
        <source>1 hour</source>
        <translation>1 timme</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="80"/>
        <source>%1 hours</source>
        <translation>%1 timmar</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="82"/>
        <source>1 minute</source>
        <translation>1 minut</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="82"/>
        <source>%1 minutes</source>
        <translation>%1 minuter</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="84"/>
        <source>1 second</source>
        <translation>1 sekund</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="84"/>
        <source>%1 seconds</source>
        <translation>%1 sekunder</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="88"/>
        <source>0.%1 seconds</source>
        <translation>0.%1 sekunder</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="90"/>
        <source> and </source>
        <translation> och </translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="97"/>
        <source>Project Settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="99"/>
        <source>Paths</source>
        <translation type="unfinished">Sökvägar</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="100"/>
        <source>Include paths</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="101"/>
        <source>Defines</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="103"/>
        <source>Path selected</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="104"/>
        <source>Number of files scanned</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="105"/>
        <source>Scan duration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="107"/>
        <source>Errors</source>
        <translation type="unfinished">Fel</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="108"/>
        <source>Warnings</source>
        <translation type="unfinished">Varningar</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="109"/>
        <source>Style warnings</source>
        <translation type="unfinished">Stil varningar</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="110"/>
        <source>Portability warnings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="111"/>
        <source>Performance warnings</source>
        <translation type="unfinished">Prestanda varningar</translation>
    </message>
    <message>
        <location filename="statsdialog.cpp" line="112"/>
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
        <location filename="txtreport.cpp" line="76"/>
        <source>inconclusive</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
