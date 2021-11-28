#include "header/Player.h"
#include <iostream>

Player::Player() {
    wallet = 100;
    handIndex = 0;
}

Player::Player(double startBalance) {
    wallet = startBalance;
    handIndex = 0;
}

double Player::getWallet() {
    return wallet;
}

bool Player::setWallet(double cash) {
    if (wallet + cash > 0) {
        wallet += cash;
        return true;
    }
    return false;
}

bool Player::depositInBank(double cash) {
    if (cash > 0) { // must deposit a positive amount
        if (wallet - cash > 0) { // if you have enough money to deposit
            wallet -= cash;
            playerBank.deposit(cash);
        }
    }
    return false;
}

bool Player::withdrawFromBank(double cash) {
    if (cash > 0) {
        if(playerBank.getBalance() >= cash) {
            playerBank.withdraw(cash);
            wallet += cash;
        }
    }

    return false;
}