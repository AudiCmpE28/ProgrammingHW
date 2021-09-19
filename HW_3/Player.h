#ifndef PLAYER_H_
#define PLAYER_H_
#pragma once

class Player
{
private:
    char move;
public:
    Player(/* args */);
    char playMove(char playermove);    
};

Player::Player()
{
move =0;
}


#endif