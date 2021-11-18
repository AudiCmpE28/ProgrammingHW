#include "header/Dealer.h"
#include <iostream>

Dealer::Dealer() {
    deckiter = currentDeck.createIterator();
    handIndex = 0;
}

Card Dealer::dealCard() {
    if (!deckiter.is_done()) 
        return deckiter.pop();
    Card blank;
    return blank;
}
