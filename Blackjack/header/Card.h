#ifndef CARD_H
#define CARD_H

enum value {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
enum suits {spade = 1, club, diamond, heart};

class Card
{
private:
    int value;
    int suit;

public:
    Card();
    Card(int val, int s);
    int getValue();
    int getSuit();

    // Returns true if value was set successfully
    bool setValue(int val);
    bool setSuit(int s);

    void printCardDetails();
};


#endif /* CARD_H */