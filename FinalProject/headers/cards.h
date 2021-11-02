#include <string>
#include <vector>
#include <iostream>
#include "utility.h"
#ifndef CARDS_H_
#define CARDS_H_
#pragma once

using namespace std;

enum color {EMPTY_C,RED=1,BLACK};
enum face {EMPTY_F,ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
enum suit {EMPTY_S,SPADES=1,DIAMONDS,HEARTS,CLUBS};


class Card {
    public:
        // Card(const Card& copycard)
        //     :Color{copycard.Color},Face{copycard.Face},Suit{copycard.Suit},valid{copycard.valid}{
        //         if(DEBUG)
        //             cout<<"Card copy constructor called\n";
        //     }

        Card(color C,face F,suit S)
        {
        if(!(C<3 && C>0 && F>0 && F<14 && S<5 && S>0))
        {
            if(DEBUG)
            {
                cout<<"Bad card ENUM"<<endl;
            }
            this->Color=EMPTY_C;
            this->Face=EMPTY_F;
            this->Suit=EMPTY_S;       
            this->valid=false;
        return;
        }
        this->Color=C;
        this->Face=F;
        this->Suit=S;
        this->valid=true;
        }
        Card(int C,int F,int S)
        {
        if(!(C<3 && C>0 && F>0 && F<14 && S<5 && S>0))
        {
            if(DEBUG)
            {
                cout<<"Bad card INT"<<endl;
            }
            this->Color=EMPTY_C;
            this->Face=EMPTY_F;
            this->Suit=EMPTY_S;
            this->valid=false;
        return;
        }
        this->Color=C;
        this->Face=F;
        this->Suit=S;
        this->valid=true;
        }
        vector<int> GetCardSpec();
        string GetCard();
        bool isValid();
        void operator= (const Card &C){
            // if(this==&C)
                // return *this;
            Color = C.Color;
            Face = C.Face;
            Suit = C.Suit;
            valid = C.valid;
            // return *this;
        }
    private:
    int Color,Face,Suit;
    bool valid;
};

#endif