#ifndef OBSERVER_H
#define OBSERVER_H

#include "Card.h"

class Observer
{
public:
    virtual ~Observer() {}
    virtual void update(vector<Card> playerH, vector<Card> dealerH) = 0;
};

#endif /* OBSERVER_H */