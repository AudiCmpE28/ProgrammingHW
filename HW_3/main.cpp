/*
TO compile in VS code:
cd "$cwd" ; if ($?) { g++ main.cpp Game.cpp Player.cpp CPU.cpp -o main } ; if ($?) { .\main }
*/

#include <iostream>
#include "headers/Game.h"
#include <time.h>
// #include "headers/Player.h"
// #include "headers/CPU.h"

#include <random>
using std::cout;
using std::endl;
using std::rand;
using std::srand;

int main()
{
    srand(time(NULL)); //input time null
    Game initgame;
    initgame.gameMatch();

    // cout << "Wtf man\n";
    // for (int i = 0; i < 23; i++)
    // {
    //     cout << rand() << endl;
    // }

    // cout << "Rock vs Paper: " << initgame.calculateResult(1, 2) << endl;
    return 0;
}