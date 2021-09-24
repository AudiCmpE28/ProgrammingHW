#include"headers/RandomCPU.h"

void RandomCPU::generateMove()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    move = randMove;
}
