#ifndef BLACKJACKPLAYER_H
#define BLACKJACKPLAYER_H

#include "Card.h"

class BlackjackPlayer
{
protected:
    Card hand[11];
    int handIndex;
public:
    BlackjackPlayer();
    void gainCard(Card hitCard);
};



#endif /* BLACKJACKPLAYER_H */