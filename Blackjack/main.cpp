#include <iostream>
#include "header/DeckOfCards.h"
using namespace std;

int main() {
    DeckOfCards deck1;
    cout << "Initial top 10 cards\n";
    Card temp;
    for (int i = 0; i < 10; i++) {
        temp = deck1.getTop();
        temp.printCardDetails();
    }

    cout << endl;
    cout << "top 10 cards after shuffle\n";
    deck1.randomize_deck();
    for (int i = 0; i < 10; i++) {
        temp = deck1.getTop();
        temp.printCardDetails();
    }

    return 0;
}

// How to compile for testing
// g++ main.cpp Card.cpp DeckOfCards.cpp -o main
// include all cpp that is part of main in that list.