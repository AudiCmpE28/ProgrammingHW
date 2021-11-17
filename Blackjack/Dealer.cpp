#include "header/Dealer.h"
#include <iostream>

Dealer::Dealer() {
    deckiter = currentDeck.createIterator();
    handIndex = 0;
}

Card Dealer::dealCard() {
    return deckiter.pop();
}
