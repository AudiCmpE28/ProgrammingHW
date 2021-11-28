#include "header/Game.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

Game::Game() {
    playerBet = 0;
    playerScore = 0;
    dealerScore = 0;
    gameover = false;
    playerStay = false;
    playerBust = false;
}
// Game::Game(Player *playerinstance) {
//     player=playerinstance; //set pointer to that of passed player pointer
//     playerBet = 0;
//     playerScore = 0;
//     dealerScore = 0;
//     gameover = false;
//     playerStay = false;
//     playerBust = false;
// }
void Game::initHands() {
    player.clearHand();
    dealer.clearHand();
    gameover = false;
    playerStay = false;
    playerBust = false;
    addToHand(forPlayer);
    addToHand(forPlayer);
    addToHand(forDealer);
    addToHand(forDealer);

    if (playerScore == 21 || dealerScore == 21) {
        gameover = true;
    }
}

bool Game::setPlayerBet(double cash) { 
    cout << player.getWallet();
    if (player.getWallet() >= cash) {
        if (player.setWallet(-cash)) {
            playerBet = cash;
            return true;
        }
    }
    cout << "Error setting bet!" << endl 
         << "Player does not have enough money!" << endl;
    return false;
}

void Game::payWinnings() {
    player.setWallet(2*playerBet);
}

void Game::addToHand(int participant) {
    Card topCard = dealer.dealCard();
    if (participant == forPlayer) {
        player.gainCard(topCard);
        updatePlayerScore();
    }
    else if (participant = forDealer) {
        dealer.gainCard(topCard);
        updateDealerScore();
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
        return player.getHand();
    }
    else if (participant == forDealer) {
        return dealer.getHand();
    }
    return error;
}

void Game::playerHit(bool keepPlaying) {
    if (keepPlaying) 
        addToHand(forPlayer);
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

void Game::printUI() {
    vector<Card> playerHand = getHand(forPlayer);
    vector<Card> dealerHand = getHand(forDealer);
    int count = 1;
    cout << "Dealer hand: " << endl;
    for (int i = 0; i < dealerHand.size(); i++) {
        cout << count << ": ";
        dealerHand[i].printCardDetails();
    }
    cout << "Dealer: " << dealerScore << endl;
    cout << endl;

    count = 1;
    cout << "Player hand: " << endl;
    for (int i = 0; i < playerHand.size(); i++) {
        cout << count << ": ";
        playerHand[i].printCardDetails();
    }
    cout << "Player: " << playerScore << endl;

    cout << endl;

    if (gameover) {
        if (returnWinner() == forPlayer) {
            cout << "-----------The Player won!-----------" << endl;
            payWinnings();
        }
        else if (returnWinner() == forDealer)
            cout << "-----------The Player LOST!-----------" << endl;
        else 
            cout << "-----------TIEEEEEEEEE-----------" << endl;

        cout << "Player current Balance: " << player.getWallet() << endl;
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

bool Game::get_player_busted(){
    return playerBust;
}

bool Game::get_Game_Over_Flag(){
    return gameover;
}