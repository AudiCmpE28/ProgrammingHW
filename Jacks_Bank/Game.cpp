#include "header/Game.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

Game::Game() {
    player = new Player();
    playerBet = 0;
    playerScore = 0;
    dealerScore = 0;
    gameover = false;
    playerStay = false;
    playerBust = false;
}
Game::Game(Player *playerinstance) {
    player = playerinstance; //set pointer to that of passed player pointer
    playerBet = 0;
    playerScore = 0;
    dealerScore = 0;
    gameover = false;
    playerStay = false;
    playerBust = false;
}

void Game::initHands() {
    player->clearHand();
    dealer.clearHand();
    gameover = false;
    playerStay = false;
    playerBust = false;
    addToHand(forDealer);
    addToHand(forDealer);
    addToHand(forPlayer);
    addToHand(forPlayer);
    if (playerScore == 21 || dealerScore == 21) {
        gameover = true;
    }
}

bool Game::setPlayerBet(int cash) { 
    cout << player->getWallet();
    if (player->getWallet() >= cash) {
        if (player->setWallet(-cash)) {
            playerBet = cash;
            return true;
        }
    }
    cout << "Error setting bet!" << endl 
         << "Player does not have enough money!" << endl;
    playerBet = 0;
    return false;
}

void Game::payWinnings() {
    if (returnWinner() == forPlayer) {
        player->setWallet(2*playerBet);
    }
    else if (returnWinner() == 0) {
        player->setWallet(playerBet);
    }
    else {
        ; // Do nothing if they lost since the bet was deducted at game start
    }
}

void Game::addToHand(int participant) {
    Card topCard = dealer.dealCard();
    if (participant == forPlayer) {
        player->gainCard(topCard);
        updatePlayerScore();
        hand_changed();
    }
    else if (participant = forDealer) {
        dealer.gainCard(topCard);
        updateDealerScore();
        hand_changed();
    }
    if (playerScore > 21) {
        playerBust = true;
    }
}

void Game::updatePlayerScore() {
    vector<Card> playerHand = getHand(forPlayer);
    playerScore = 0; // reset for update
    int oneCount = 0;
    int tenCount = 0;
    for (int i = 0; i < playerHand.size(); i++) {
        if (playerHand[i].getValue() == 1) {
            oneCount++;
        }
        else if (playerHand[i].getValue() >= 10) { // Jack, Queen, and King all count as 10s
            tenCount++;
        }
        else {
            playerScore += playerHand[i].getValue();
        }
    }
    playerScore = playerScore + (tenCount * 10);
    
    if (playerScore + (oneCount*11) > 21) { // Aces = 11 give you a bust, then it counts as 1
        playerScore = playerScore + oneCount;
    }
    else { // if it doesn't bust, aces count as 11
        playerScore = playerScore + (oneCount * 11);
    }
    if (playerScore == 21) gameover = true;
}

void Game::updateDealerScore() {
    vector<Card> dealerHand = getHand(forDealer);
    dealerScore = 0; // reset for update
    int oneCount = 0;
    int tenCount = 0;
    for (int i = 0; i < dealerHand.size(); i++) {
        if (dealerHand[i].getValue() == 1) {
            oneCount++;
        }
        else if (dealerHand[i].getValue() >= 10) { // Jack, Queen, and King all count as 10s
            tenCount++;
        }
        else {
            dealerScore += dealerHand[i].getValue();
        }
    }
    dealerScore = dealerScore + (tenCount * 10);
    
    if (playerScore + (oneCount*11) > 21) { // Aces = 11 give you a bust, then it counts as 1
        dealerScore = dealerScore + oneCount;
    }
    else { // if it doesn't bust, aces count as 11
        dealerScore = dealerScore + (oneCount * 11);
    }
}

vector<Card> Game::getHand(int participant) {
    Card errorCard(99,99);
    vector<Card> error = {errorCard};
    if (participant == forPlayer) {
        return player->getHand();
    }
    else if (participant == forDealer) {
        return dealer.getHand();
    }
    return error;
}

void Game::playerHit(bool keepPlaying) {
    if (keepPlaying) {
        addToHand(forPlayer);
    }
    else
        playerStay = true;
}

void Game::dealerTurn() {
    if (!playerBust && !gameover) 
        while (playerScore > dealerScore) {
            addToHand(forDealer);
        }
    // the dealer's action is last, so once he's done, game is over.
    gameover = true;
}

int Game::returnWinner() {
    if (playerScore > 21)
        return forDealer;
    else if (dealerScore > 21) 
        return forPlayer;
    else {
        if (playerScore > dealerScore) 
            return forPlayer;
        else if (playerScore < dealerScore)
            return forDealer;
        else return 0;
    }
}

void Game::hand_changed() {
    notify_observer();
}

void Game::register_observer(Observer *o) {
    observers.push_back(o);
}
void Game::remove_observer(Observer *o) {
    vector<Observer *>::iterator it;
    it = std::find(observers.begin(), observers.end(), o);
    if (it != observers.end()) observers.erase(it);
}
void Game::notify_observer() {
    for (Observer *o : observers) {
        o->update(getHand(forPlayer), getHand(forDealer));
    }
}

bool Game::stopGame() {
    if (playerStay || playerBust || gameover) {
        return true;
    }
    return false;
}

int Game::getPlayerScore(){
    return playerScore;
}

int Game::getDealerScore(){
    return dealerScore;
}