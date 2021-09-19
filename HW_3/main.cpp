#include <iostream>
#include "classes/Game.h"
// #include "classes/Player.h"
// #include "classes/CPU.h"

using namespace std;

int main()
{
    Game initgame;
    cout << "Rock vs Paper: " << initgame.calculateResult(1, 1) << endl;
    return 0;
}