#include <iostream>
#include "headers/Game.h"
#include <time.h>
// #include "headers/Player.h"
// #include "headers/CPU.h"

#include <random>
using std::cout;
using std::endl;

int main()
{
    //string which = "random";
    Game rockPaperScissors;
    rockPaperScissors.executeMatch();
    return 0;
}
//----------------------HOW TO RUN in VS code------------------------
//Make sure you're in the HW3 directory in terminal then copy and paste:
//cd "$cwd" ; if ($?) { g++ Game.cpp main.cpp CPU.cpp Player.cpp RandomChooser.cpp printUI.cpp -o main } ; if ($?) { .\main }