#include "headers/GeniusCPU.h"
//empty for now

void GeniusCPU::generateMove()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    move = randMove;
}