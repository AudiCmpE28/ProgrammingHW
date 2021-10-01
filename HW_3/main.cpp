#include <iostream>
#include "headers/Game.h"
#include "headers/ChooserFactory.h"
#include <time.h>
// #include "headers/Player.h"
// #include "headers/CPU.h"

using std::cout;
using std::endl;

int main()
{
    Game rockPaperScissors;
    rockPaperScissors.executeMatch();
    return 0;
}
//----------------------HOW TO RUN in VS code------------------------
//Make sure you're in the HW3 directory in terminal then copy and paste:
//cd "$cwd" ; if ($?) { g++ Game.cpp main.cpp CPU.cpp Player.cpp RandomCPU.cpp printUI.cpp ChooserFactory.cpp SmartCPU.cpp GeniusCPU.cpp -o main } ; if ($?) { .\main }
