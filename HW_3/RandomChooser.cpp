#include"headers/RandomChooser.h"

void RandomChooser::generateMove()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    move = randMove;
}

int RandomChooser::getMove()
{
    return move;
}

void RandomChooser::printCPUMove()
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
