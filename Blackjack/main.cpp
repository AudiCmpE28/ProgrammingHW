#include <iostream>
#include "header/DeckOfCards.h"
#include "header/CardIterator.h"
#include "header/Dealer.h"
using namespace std;

int main() {
    Dealer dealer1;
    Card temp;
    int count = 0;
    while (count < 52) {
        temp = dealer1.dealCard();
        temp.printCardDetails();
        count++;
    }


    return 0;
}

#if 0
// Example of testing iterator, Card class, DeckOfCards class
int main() {
    int count = 1;
    DeckOfCards deck1;
    cout << "Initial top 10 cards\n";
    CardIterator CardIter = deck1.createIterator();
    Card temp = CardIter.current_item();

    cout << count << ": ";
    count++;
    temp.printCardDetails();
    while(!CardIter.is_done()) {
        cout << count << ": ";
        count++;
        temp = CardIter.next();
        temp.printCardDetails();
    }

    count = 1;
    CardIter = deck1.createIterator();
    temp = CardIter.current_item();

    cout << count << ": ";
    count++;
    temp.printCardDetails();
    while(!CardIter.is_done()) {
        cout << count << ": ";
        count++;
        temp = CardIter.next();
        temp.printCardDetails();
    }


    return 0;
}

#endif

// How to compile for testing
// g++ main.cpp Card.cpp DeckOfCards.cpp -o main
// include all cpp that is part of main in that list.