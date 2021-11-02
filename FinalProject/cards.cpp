#include "headers/cards.h"
const string strColor[]={"Empty","Red","Black"};
const string strFace[]= {"Empty","Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
const string strSuit[]={"Empty","Hearts","Diamonds","Spades","Clubs"};

bool Card::isValid()
{
    return this->valid;
}
vector<int> Card::GetCardSpec(){
    vector<int> specs;
    specs.push_back(this->Color);
    specs.push_back(this->Face);
    specs.push_back(this->Suit);
    specs.push_back(int(this->valid));
    return specs;
}
string Card::GetCard(){
    string desc;
    if(!this->isValid())
    {
        desc="InvalidCard";
        return desc;
    }
    desc= strColor[this->Color]+" "+strFace[this->Face] + " of " + strSuit[this->Suit];
    // cout<<desc<<endl;
    return desc;
}