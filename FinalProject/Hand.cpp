#include "headers/Hand.h"
/**
Scuffed implimentation
TODO: Circular array hand
*/
Hand::Hand(int size){
    this->handsize=size;
}
Hand::Hand(Deck &DecktoHand)
{
    this->handsize=5;
    for (int i = 0; i < handsize; i++)
    {
        CardsInHand.push_back(DecktoHand.DealFromDeck());
    }
}
Card Hand::PlayCard(int cardIndex){
    if (cardIndex <= CardsInHand.size()-1 && cardIndex>=0)//5 cards, 0-4 index
    {   
        Card PlayedCard = this->CardsInHand[cardIndex];
        if(DEBUG)
            cout<<"\nCard "<<cardIndex<<" Played: "+this->CardsInHand[cardIndex].GetCard();
        this->CardsInHand.erase(CardsInHand.begin() + cardIndex);
        return PlayedCard;
    }
    else
    {
        if (DEBUG)
            cout << "\nHand is empty, or index out of range!";
        // throw int(-3); //use throws sparesly in wxwidgets
    }
}
Card Hand::AddtoHand(Card &C){
    this->CardsInHand.push_back(C);
    return C;
}
