#ifndef BLACKJACKPLAYER_H
#define BLACKJACKPLAYER_H

#include "Card.h"
#include <iostream>
#include <vector>
using std::vector;

class BlackjackPlayer
{
protected:
    Card hand[11];
    int handIndex;
public:
    BlackjackPlayer();
    void gainCard(Card hitCard);
    vector<Card> getHand();
    void clearHand();
};



#endif /* BLACKJACKPLAYER_H */