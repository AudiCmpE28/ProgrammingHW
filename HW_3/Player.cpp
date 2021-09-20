#include "headers/Player.h"
#include <iostream>
using std::string;using std::cout;// using std::srand;

Player::Player()
{
    move = 0;
}

int Player::playMove(int playermove)
{
    if (playermove >= 1 && playermove <= 3)
    {
        cout<<"\nYou Played :"<<playermove;
        return playermove;
        }
    else
        return -1;
};
