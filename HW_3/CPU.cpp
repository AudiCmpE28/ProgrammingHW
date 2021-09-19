#include <random>
#include "classes/CPU.h"
int CPU::playMove()
{
    int randmove;
    return randmove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
}