#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "DeckOfCards.h"
#include "CardIterator.h"
#include "blackjackPlayer.h"

class Dealer : public BlackjackPlayer
{
private:
    DeckOfCards currentDeck;
    CardIterator deckiter;
public:
    Dealer();
    Card dealCard();

};



#endif /* DEALER_H */