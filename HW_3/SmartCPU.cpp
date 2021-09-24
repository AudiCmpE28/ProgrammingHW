#include "headers/SmartCPU.h"
//empty for now.. assignment 4


void SmartCPU::generateMove()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    move = randMove;
}
