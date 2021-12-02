#include "header/Dealer.h"
#include <iostream>

Dealer::Dealer() {
    deckiter = currentDeck.createIterator();
}

Card Dealer::dealCard() {
    if (deckiter.is_done()) 
        resetDeck();
    return deckiter.pop();
}

void Dealer::resetDeck() {
    deckiter = currentDeck.createIterator();
}

