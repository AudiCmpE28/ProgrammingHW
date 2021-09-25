#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "headers/CPU.h"

using std::cout;

CPU::CPU()
{
    this->move = 0;
    this->choiceMethod = 0; // init with random choice selection
    srand(time(NULL));      // seed the rand function
};

void CPU::generateMove()
{
    Chooser *chooser = ChooserFactory::make_chooser(choiceMethod);
    move = chooser->make_choice();
}

int CPU::getMove()
{
    return move;
}

int CPU::getchoiceMethod()
{
    return choiceMethod;
}

int CPU::setchoiceMethod(int choice)
{
    choiceMethod = choice;
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
