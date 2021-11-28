#include "header/Card.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// utility function
string cardValue(int val);
string cardSuit(int s);

// Class Functions

Card::Card() {
    value = 0;
    suit = 0;
}

Card::Card(int val, int s) {
    value = val;
    suit = s;
}

int Card::getValue() {
    return value;
}

bool Card::setValue(int val) {
    if (val >=0 && val <= 13) {
        value = val;
        return true;
    }
    return false;
}

int Card::getSuit() {
    return suit;
}

bool Card::setSuit(int s) {
    if (s > 0 && s < 5) {
        suit = s;
        return true;
    }
    return false;
}

void Card::printCardDetails() {
    string val = cardValue(value);
    string s = cardSuit(suit);
    cout << val << " of " << s << endl;
}

// utility functions
string Card::cardValue(int val) {
    string stringVal;
    switch(val) {
        case ace: stringVal = "Ace";
            break;
        case two: stringVal = "Two";
            break;
        case three: stringVal = "Three";
            break;
        case four: stringVal = "Four";
            break;
        case five: stringVal = "Five";
            break;
        case six: stringVal = "Six";
            break;
        case seven: stringVal = "Seven";
            break;
        case eight: stringVal = "Eight";
            break; 
        case nine: stringVal = "Nine";
            break;
        case ten: stringVal = "Ten";
            break;
        case jack: stringVal = "Jack";
            break;
        case queen: stringVal = "Queen";
            break; 
        case king: stringVal = "King";
            break;
        default: stringVal = "Error";
    } 
    return stringVal;
}

string Card::cardSuit(int val) {
    string stringVal;
    switch(val) {
        case spade: stringVal = "Spades";
            break;
        case club: stringVal = "Clubs";
            break;
        case diamond: stringVal = "Diamonds";
            break;
        case heart: stringVal = "Hearts";
            break;
        default: stringVal = "Error";
    } 
    return stringVal;
}