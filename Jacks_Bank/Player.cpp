#include "header/Player.h"
#include <iostream>

Player::Player() {
    wallet = 100;
    handIndex = 0;
}

Player::Player(int startBalance) {
    wallet = startBalance;
    handIndex = 0;
}

int Player::getWallet() {
    return wallet;
}

int Player::getBankBalance() {
    return playerBank.getBalance();
}

bool Player::setWallet(int cash) {
    if (wallet + cash >= 0) {
        wallet += cash;
        return true;
    }
    return false;
}

bool Player::depositInBank(int cash) {
    if (cash > 0) { // must deposit a positive amount
        if (wallet - cash >= 0) { // if you have enough money to deposit
            wallet -= cash;
            playerBank.deposit(cash);
        }
    }
    return false;
}

bool Player::withdrawFromBank(int cash) {
    if (cash > 0) {
        if(playerBank.getBalance() >= cash) {
            playerBank.withdraw(cash);
            wallet += cash;
        }
    }

    return false;
}