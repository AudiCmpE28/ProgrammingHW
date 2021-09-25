#include <iostream>
#include "headers/Game.h"

int main()
{
    Game rockPaperScissors;
    rockPaperScissors.executeMatch();
    return 0;
}

// For Anh's personal use: Compile using
// cd "$cwd" ; if ($?) { g++ Game.cpp main.cpp CPU.cpp Player.cpp -o main } ; if ($?) { .\main }