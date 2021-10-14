#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int move;

public:
    // Initialize move with an invalid move
    Player(/* args */);
    void setMove(int moveInput);
    int getMove();
    void printPlayerMove();
};

#endif /* PLAYER_H */
