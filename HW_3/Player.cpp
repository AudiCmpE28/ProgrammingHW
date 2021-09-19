#include "classes/Player.h"
int Player::playMove(int playermove)
{
    if (1 >= playermove <= 3)
        return playermove;
    else
        return -1;
};
