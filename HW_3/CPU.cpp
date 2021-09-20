#include "headers/CPU.h"
#include <random>
using std::rand;
// using std::srand;

CPU::CPU()
{
    this->move = 0;
};
int CPU::playMove()
{
    int randmove;
    return randmove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
};
