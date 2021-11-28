#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dealer.h"
#include "Card.h"

class Game
{
private:
    Player *player;
    Dealer dealer;

    int playerBet;
    bool playerStay;
    int playerScore;
    bool playerBust;

    int dealerScore;
    bool gameover;
    void addToHand(int participant);
    
public:
    Game();
    Game(Player *playerinstance);

    const int forPlayer = 1;
    const int forDealer = 2;
    void initHands();
    vector<Card> getHand(int participant);
    
    bool setPlayerBet(double cash);
    void payWinnings();
    void playerHit(bool stop);
    void updatePlayerScore();

    void dealerTurn();
    void updateDealerScore();
    int returnWinner();
    bool stopGame();


    // Temporary print functions for testing
    void printUI();
};

#endif /* GAME_H */