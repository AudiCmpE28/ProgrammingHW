#include "Deck.h"

#ifndef HAND_H_
#define HAND_H_

class Hand{
    public:
    Hand(int size);
    Hand(Deck &DecktoHand);
    Card PlayCard(int cardIndex);
    Card AddtoHand(Card &C);
    vector<Card> CardsInHand;
    private:
    int handsize;

};

#endif