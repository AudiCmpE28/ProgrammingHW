#include "headers/CPU.h"
#include <random>
#include <iostream>
using std::rand;
using std::string;using std::cout;

CPU::CPU()
{
    this->move = 0;
};
int CPU::playMove()
{
    int randmove;
    randmove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    cout<<"\nCPU Played : "<<randmove<<'\n';
    return randmove;
};
