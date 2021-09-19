#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
private:
    int move;
public:
    Player(/* args */);
    int playMove(int playermove);    
};

Player::Player()
{
this->move =0;
}


#endif