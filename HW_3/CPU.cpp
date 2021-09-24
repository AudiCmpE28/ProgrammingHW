#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "headers/CPU.h"

using std::cout;
using std::string;

CPU::CPU()
{
    this->move = 0;
    srand(time(NULL)); // seed the rand function
};


int CPU::getMove()
{
    return move;
}

void CPU::printCPUMove()
{
    enum moves
    {
        invalid = -1,
        rock = 1,
        paper = 2,
        scissors = 3
    };
    ;
    cout << "CPU : ";
    if (move == rock)
        cout << "Rock\n";
    else if (move == paper)
        cout << "Paper\n";
    else if (move == scissors)
        cout << "Scissors\n";
}
