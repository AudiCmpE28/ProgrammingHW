#ifndef CARDITERATOR_H
#define CARDITERATOR_H

#include "DeckOfCards.h"

class CardIterator {
private:
    const Card *array;
    int size;
    int cursor;

public:
    CardIterator(Card arr[], int sz) : array(arr), size(sz), cursor(0) {}
    Card first()        { return array[0]; }
    Card next()         { return array[++cursor]; }
    Card current_item()   { return array[cursor]; }
    bool is_done()      { return cursor >= size-1; }

};


#endif /* CARDITERATOR_H */