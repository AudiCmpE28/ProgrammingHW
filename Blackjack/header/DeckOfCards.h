#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "Card.h"
#include "CardIterator.h"

class DeckOfCards
{
private:
    Card Deck[52];
    void initialize_deck();
    void randomize_deck();

public:
    DeckOfCards();
    CardIterator createIterator();
};


#endif /* DECKOFCARDS_H */