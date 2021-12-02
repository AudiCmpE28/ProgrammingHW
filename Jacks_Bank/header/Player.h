#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Bank.h"
#include "blackjackPlayer.h"

class Player : public BlackjackPlayer
{
private:
    int wallet;
    Bank playerBank;
public:
    Player();
    Player(int startBalance);
    int getWallet();
    int getBankBalance();
    bool setWallet(int cash);
    bool depositInBank(int cash);
    bool withdrawFromBank(int cash);
};



#endif /* PLAYER_H */