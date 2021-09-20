#include <iostream>
#include "headers/Game.h"
// #include "headers/Player.h"
// #include "headers/CPU.h"

#include <random>
using std::cout;
using std::endl;
using std::rand;
using std::srand;

int main()
{
    // srand(124719279); //input time null
    Game initgame;
    string temp = initgame.gameMatch();

    cout << temp << endl;
    // cout << "Wtf man\n";
    // for (int i = 0; i < 23; i++)
    // {
    //     cout << rand() << endl;
    // }

    // cout << "Rock vs Paper: " << initgame.calculateResult(1, 2) << endl;
    return 0;
}