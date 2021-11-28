#include "header/DeckOfCards.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;

// utility functions
void swapCards (Card *a, Card *b) {
    Card temp = *a;
    *a = *b;
    *b = temp;
}

// Class Functions
DeckOfCards::DeckOfCards() {
    initialize_deck();
    randomize_deck();
}

void DeckOfCards::initialize_deck() {
    // Outer loop inits suit, inner loop inits value
    int count = 0;
    for (int i = 1; i < 5; i++) {
        for(int j = 1; j < 14; j++) {
            Deck[count].setSuit(i);
            Deck[count].setValue(j);
            count++;
        }
    }

    // for Debugging
    if (count != 52) {
        cout << "Well what the hell happened?? [Count = " << count << "]\n";
    }
    else {
        cout << "Deck created successfully\n";
    }
}

void DeckOfCards::randomize_deck() {
    srand(time(NULL));

    // Shuffle the deck [Fisher-Yates Shuffle Algorithm]
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        swapCards(&Deck[i], &Deck[j]);
    }

    // Emulates a deck cut
    for (int i = 0; i < 26; i++) {
        swapCards(&Deck[i], &Deck[i+26]);
    }
}

CardIterator DeckOfCards::createIterator() {
    randomize_deck();
    return CardIterator(Deck, 52);
}