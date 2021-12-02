#include "header/Bank.h"

Bank::Bank() {
    // Defaults at 500 dollars
    balance = 500;
}

void Bank::deposit(double cash) {
    balance += cash;
}

bool Bank::withdraw(double cash) {
    if (cash <= balance) {
        balance -= cash;
        return true;
    }
    
    return false;
}

double Bank::getBalance() {
    return balance;
}