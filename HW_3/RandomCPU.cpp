#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "headers/RandomCPU.h"

using std::cout;


int RandomCPU::make_choice()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    return randMove;
}