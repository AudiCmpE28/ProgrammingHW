#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "Card.h"

class DeckOfCards
{
private:
    Card Deck[52];
    int indexOfTop;
public:
    DeckOfCards();
    void initialize_deck();
    void randomize_deck();
    Card getTop();
};


#endif /* DECKOFCARDS_H */