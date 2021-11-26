#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Bank.h"
#include "blackjackPlayer.h"

class Player : public BlackjackPlayer
{
private:
    double wallet;
    Bank playerBank;
public:
    Player();
    Player(double startBalance);
    double getWallet();
    bool setWallet(double cash);
    bool depositInBank(double cash);
    bool withdrawFromBank(double cash);
};



#endif /* PLAYER_H */