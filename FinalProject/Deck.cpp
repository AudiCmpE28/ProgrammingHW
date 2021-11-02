#include "headers/Deck.h"
#include <algorithm>
#include <vector>
using namespace std;

Deck::Deck()
{
    this->DeckSize=0;
    this->currentcard=-1;
    this->CardsInDeck.reserve(52);
    if(DEBUG)
        cout<<"\nMaking Deck...\n";

    //Red Cards
    for(int j=1;j<=13;j++)
    {
        for(int k=1;k<=2;k++)
        {
            Card newcard(1,j,k);
            this->CardsInDeck.push_back(newcard);
            this->DeckSize++;
            if(DEBUG)cout<<"Deck Size: "<<DeckSize<<'\n';
        }
    }
    //Black Cards
    for(int j=1;j<=13;j++)
    {
        for(int k=3;k<=4;k++)
        {
            Card newcard(2,j,k);
            this->CardsInDeck.push_back(newcard);
            this->DeckSize++;
            if(DEBUG)cout<<"Deck Size: "<<this->DeckSize<<'\n';
        }
    }
    if(DEBUG)
    {
        for(int i=1; i<=DeckSize;i++)
            cout<<this->CardsInDeck[i-1].GetCard()<<'\n';
        cout<<"\nDeck Size is : "<<DeckSize<<'\n';
        // cout<<"\nShuffling the deck...\n";
    }
    // this->Shuffle(1);
    this->currentcard=0;
}

/* 
Shuffles the deck using either Fisher-Yates Shuffle or std::random_shuffle
@param shuffleType True or False, respectively
 */
void Deck::Shuffle(bool shuffleType)
{
    int SIZE = this->CardsInDeck.size();
    if (shuffleType) //Fisher-Yates Shuffle Algorithm
    {
        for (int i = 0; i < SIZE; i++) // 0 - 51 cards
        {
            int j = i + rand() % (SIZE - i);
            swap(this->CardsInDeck[i], this->CardsInDeck[j]);
        }
    }
    else //random_shuffle
    {
        std::random_shuffle(this->CardsInDeck.begin(), this->CardsInDeck.end());
    }
    if (DEBUG)
        for (int i = 0; i < SIZE; i++)
            cout << this->CardsInDeck[i].GetCard() << '\n';
}
/*
    Can go above 52 cards this way, intentional
*/
void Deck::AddToDeckCheat(Card &C)
{
    this->CardsInDeck.push_back(C);
    if (DEBUG)cout<<"\n(!)Added to deck: "<<C.GetCard();
    DeckSize++;
}

/* 
Adds a card C to Deck, Cannot go above 52 cards in Deck, and cannot have duplicate cards.
 */
void Deck::AddToDeck(Card &C)
{
    int size=this->getdecksize();
    bool dupe=false;
    if(size>0)
    {
        for (int i = 0; i < size; i++)
        {
            vector<int> temp=this->CardsInDeck[i].GetCardSpec(); 
            vector<int> temp2= C.GetCardSpec();
            
            if (temp[0]==temp2[0] && temp[1]==temp2[1] && temp[2]==temp2[2]) //TODO: operator== overloading for Card
            {
                dupe=true;
                if (DEBUG)
                    cout<<"\nTried to add Duplicate card";
                // throw int(-2);        
                break;
            }
        }
    }
    if (this->DeckSize < 52 && dupe==false)
        {
            this->CardsInDeck.push_back(C);
            if (DEBUG)cout<<"\nAdded to deck: "<<C.GetCard();
            this->DeckSize++;
        }
    else if(DeckSize>=52){
        if (DEBUG)
        {
            cout<<"\nDeck full: "<<this->DeckSize<<" cards";
        }
        
    }
}
/* Returns a Card from the top of Deck, throws if Deck empty. */
Card Deck::DealFromDeck()
{
    if (this->DeckSize>0)//>0
    {   
    Card DealtCard = this->CardsInDeck[this->DeckSize-1];//Full deck: DeckSize=52 ; index@51
        if(DEBUG)
            cout<<"\nCard "<<this->DeckSize<<" Dealt: "+DealtCard.GetCard();
        this->CardsInDeck.pop_back();
        this->DeckSize--;
        return DealtCard;
    }
    else
    {
        if (DEBUG)
            cout << "\nCard was dealt from empty deck!";
        // throw string("Deck is empty!"); //commenting out throws
    }
    // if(DEBUG)
    //     cout<<"\nCard "<<this->DeckSize<<" Dealt: "<<this->CardsInDeck[currentcard].GetCard();
    // this->DeckSize=this->DeckSize-1;
    // return (this->currentcard<this->DeckSize || this->DeckSize>0) ? this->CardsInDeck[currentcard++] : throw int(-1);
}
int Deck::getdecksize(){
    if(DEBUG)
    cout<<"\nDeckSize :"<<this->DeckSize;
    return this->DeckSize;
}

vector<Card> Deck::ReturnDeck()
{
    // int SIZE = DeckSize;
    // for (int i = 0; i < SIZE; i++)
    //     cout << this->CardsInDeck[i].GetCard() << endl;
    return this->CardsInDeck;
}