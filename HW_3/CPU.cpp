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

void CPU::generateMove(int playerChoice)
{
    Chooser *chooser = ChooserFactory::make_chooser(choiceMethod);
    move = chooser->make_choice(playerChoice);
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

void CPU::insertRecent(int playerMove, int CPUChoice)
{
    if (recentIndex < 3) // if there's less than 4 elements in the recent 5
    {
        recent5[recentIndex] = playerMove;
        recentIndex++;
        recent5[recentIndex] = CPUChoice;
        recentIndex++;
    }
    else // if there's exactly 4 element [2] [3] [New 2] [New 3] [4]
    {    //shift then add
        recent5[0] = recent5[2];
        recent5[1] = recent5[3];
        recent5[2] = playerMove;
        recent5[3] = CPUChoice;
    }
}

int CPU::getrecentIndex()
{
    return recentIndex;
}