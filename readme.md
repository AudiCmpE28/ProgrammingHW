<!-- CMPE 135 Group: Snooze Goose -->

By: - Simon Altamirano - Danish Khan - Anh Huynh - Thanh V Nguyen

######################################################################################################################
IMPORTANT:
ADD personal things to GITIGNORE by right clicking it.
Following items MUST be added to .GITIGNORE:
.vscode
any .exe files

######################################################################################################################
If running c++ in VS code:
https://code.visualstudio.com/docs/languages/cpp

If issues such as not printing in terminal:
"Close the visual studio and reopen it by right clicking on it and selecting run as administrator" as seen in
https://github.com/microsoft/vscode-cpptools/issues/1329

Other Solutions:
https://github.com/microsoft/vscode-cpptools/issues/513
debugg
https://stackoverflow.com/questions/51117196/undefined-reference-error-in-vscode

######################################################################################################################

How to Compile c++ c++ in VS code:
cd "c:\Users\Simon\OneDrive\Desktop\CMPE135\ProgrammingHW\HW_3\" ; if ($?) { g++ main.cpp -o main } ; 
if ($?) { .\main }

inside { g++ main.cpp -o main } add any .cpp files used with main such as:
cd "c:\{Where You Created Folder Or Workspace}" ; if ($?) { g++ main.cpp Game.cpp -o main } ; 
if ($?) { .\main }

Shorter entry:
cd "$cwd" ; if ($?) { g++ main.cpp Game.cpp -o main } ; if ($?) { .\main }

Best Way recently discovered by Danke (it compiles all .cpp files):
cd "$cwd" ; if ($?) { g++ -std=c++0x \*.cpp -o main } ; if ($?) { .\main }

---

For convinience, keep all .cpp files in same folder for compilation. ".h" (header) files may be stored
in a different folder, but must be specified in included files such as: #include "folderName/header.h"

---

Homework 4:
smartML.txt contains a file that is learned to counter a player that only swings rock every single time
Choices.txt contains a file with randomly generated "machine learning" data, so it will probably not win that much.



Final Project:
Download CmakeTools extension in vscode
click clean reconfigure projects, and then build/run project in terminal by rightclicking it in the cmake tab.
I have already made the cmakelists.txt files so everything should be set up.