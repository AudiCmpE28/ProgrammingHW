#include "headers/CPU.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
using std::string;using std::cout;

CPU::CPU()
{
    this->move = 0;
};

void CPU::generateMove() {
    srand(time(NULL)); // seed the rand function
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    move = randMove;
}

int CPU::getMove() {
    return move;
}

void CPU::printCPUMove()
{
    enum moves {invalid = -1, rock = 1, paper = 2, scissors = 3};;
    cout<<"CPU : ";
    if (move == rock) cout << "Rock\n";
    else if (move == paper) cout << "Paper\n";
    else if (move == scissors) cout << "Scissors\n";
}
