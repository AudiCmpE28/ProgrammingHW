#include "headers/Player.h"
#include <iostream>
using std::cout;
using std::string;
// using std::srand;

Player::Player()
{
    move = -1;
}

void Player::setMove(int moveInput)
{
    enum moves
    {
        invalid = -1,
        rock = 1,
        paper = 2,
        scissors = 3
    };
    if (moveInput >= rock && moveInput <= scissors)
        move = moveInput;
    else
        move = -1;
}

int Player::getMove()
{
    return move;
}

void Player::printPlayerMove()
{
    enum moves
    {
        invalid = -1,
        rock = 1,
        paper = 2,
        scissors = 3
    };
    if (move < 0)
        cout << "The player move is invalid!\n";
    else
    {
        cout << "Player : ";
        if (move == rock)
            cout << "Rock\n";
        else if (move == paper)
            cout << "Paper\n";
        else if (move == scissors)
            cout << "Scissors\n";
    }
}
