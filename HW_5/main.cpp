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
