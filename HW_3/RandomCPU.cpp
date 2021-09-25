#include <iostream>
#include <time.h>

#include "headers/RandomCPU.h"
#include "headers/Chooser.h"

using std::cout;
using std::rand;

int RandomCPU::make_choice()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    return randMove;
}