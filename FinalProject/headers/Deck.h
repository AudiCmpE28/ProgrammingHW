#include "Cards.h"
#include <vector>
#ifndef DECK_H_
#define DECK_H_
#pragma once

using std::vector;

class Deck{
    public:
    Deck();
    void Shuffle(bool shuffleType);
    void AddToDeckCheat(Card &C);
    void AddToDeck(Card &C);
    Card DealFromDeck();
    vector<Card> ReturnDeck();
    int getdecksize();

    private:
    vector<Card> CardsInDeck;
    int DeckSize,currentcard;
};
#endif
