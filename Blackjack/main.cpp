#include <iostream>

#include "header/Card.h"
#include "header/Game.h"
using namespace std;

// for testing
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

// Test drive of an actual game
int main() {
    Game game1;
    int count = 4;
    while(1) {
        sleep_for(2s);
        cout << "<<<<<<<<<NEW GAME>>>>>>>>>" << endl;
        int choice = 100;
        game1.setPlayerBet(10);
        game1.initHands();
        game1.printUI();

        while (choice && !game1.stopGame()) {
            cout << "Do you want to hit(1) or stay(0)? " << endl;
            cout << "Type Choice: ";
            cin >> choice;
            if (choice) 
                game1.playerHit(true);
            else 
                game1.playerHit(false);
            game1.printUI();
        }      

        game1.dealerTurn();

        cout << "Here are the final results!" << endl;
        game1.printUI();
    }

    cout << "Games are done!" << endl;
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