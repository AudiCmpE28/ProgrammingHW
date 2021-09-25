#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "headers/CPU.h"

using std::cin;
using std::cout;
using std::rand;
using std::string;

CPU::CPU()
{
    this->move = -1;
    srand(time(NULL)); // seed the rand function
};

void CPU::generateMove(int which)
{
    Chooser *chooser = ChooserFactory::make_chooser(which);
    move = chooser->make_choice();
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
