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
    bool playerStay;
    int playerScore;
    bool playerBust;

    int dealerScore;
    bool gameover;
    void addToHand(int participant);
    void hand_changed();
    
public:
    Game();
    Game(Player *playerinstance);

    const int forPlayer = 1;
    const int forDealer = 2;
    void initHands();
    vector<Card> getHand(int participant);
    
    bool setPlayerBet(int cash);
    void payWinnings();
    void playerHit(bool stop);
    void updatePlayerScore();
    
    int getPlayerScore();
    int getDealerScore();

    void dealerTurn();
    void updateDealerScore();
    int returnWinner();
    bool stopGame();

    bool get_Game_Over_Flag();
    bool get_player_busted();

    void register_observer(Observer *o);
    void remove_observer(Observer *o);
    void notify_observer();
    
};

#endif /* GAME_H */