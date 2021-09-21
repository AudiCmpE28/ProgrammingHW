#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "headers/CPU.h"

using std::cout;
using std::rand;
using std::string;

CPU::CPU()
{
    this->move = -1;
    srand(time(NULL)); // seed the rand function
};

void CPU::generateMove()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    move = randMove;
}

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
