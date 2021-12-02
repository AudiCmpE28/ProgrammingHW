#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dealer.h"
#include "Card.h"
#include "Subject.h"
#include <iostream>
#include <algorithm>
#include <vector>

class Game : public Subject
{
private:
    vector<Observer *> observers;
    Player *player;
    Dealer dealer;

    int playerBet;

    int playerScore;
    int dealerScore;

    //Flags 
    bool playerBust;
    bool playerStay;
    bool gameover;

    void addToHand(int participant);
    void hand_changed();
    void updatePlayerScore();
    void updateDealerScore();
    
public:
    Game();
    Game(Player *playerinstance);

    const int forPlayer = 1;
    const int forDealer = 2;
    void initHands();
    vector<Card> getHand(int participant);
    
    bool setPlayerBet(int cash);
    void playerHit(bool stop);
    void payWinnings();
    
    int getPlayerScore();
    int getDealerScore();

    void dealerTurn();
    int returnWinner();
    bool stopGame();

    void register_observer(Observer *o);
    void remove_observer(Observer *o);
    void notify_observer();
    
};

#endif /* GAME_H */