#include "headers/Player.h"

Player::Player()
{
    move = 0;
}

int Player::playMove(int playermove)
{
    if (playermove >= 1 && playermove <= 3)
        return playermove;
    else
        return -1;
};
