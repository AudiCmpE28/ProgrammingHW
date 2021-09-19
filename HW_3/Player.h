#ifndef PLAYER_H
#define PLAYER_H

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


#endif /* PLAYER_H */