#include "headers/Hand.h"
#include "headers/Deck.h"
#include "headers/cards.h"
#include "headers/utility.h"
using namespace std;

int main()
{
    srand(unsigned(time(0)));

    cout << "###############################\nCard Generation Tests\n###############################\n"
         << endl;

    auto start = starttimer();

    Card newcard666(6, 6, 6); //Bad card
    cout << newcard666.GetCard() << endl;

    endtimer(start);

    start = starttimer();

    for (int j = 1; j <= 13; j++)
    {
        for (int k = 1; k <= 2; k++)
        {
            Card newercard(1, j, k);
            cout << newercard.GetCard() << endl;
        }
    }
    for (int j = 1; j <= 13; j++)
    {
        for (int k = 3; k <= 4; k++)
        {
            Card newercard(2, j, k);
            cout << newercard.GetCard() << endl;
        }
    }
    endtimer(start);

    cout << "###############################\nShuffled Deck Generation Test\n###############################\n"
            << endl;

    start = starttimer();

    Deck aNewDeck;

    endtimer(start);

    cout << "###############################\nDeck Shuffle 0 Test\n###############################\n"
            << endl;
    start = starttimer();
    aNewDeck.Shuffle(0);
    endtimer(start);
    cout << "###############################\nDeck Shuffle 1 Test\n###############################\n"
            << endl;
    start = starttimer();
    aNewDeck.Shuffle(1);
    endtimer(start);
    
    cout << "###############################\nDeck Verification Test\n###############################\n"
         << endl;
    start = starttimer();
    Card newcardfromdeck(1, 2, 3);
    Deck dealingdeck;
    vector<int> testvector;
    for (int i = 1; i <= dealingdeck.getdecksize(); i++)
    {
        testvector.push_back(i);
        cout << "\nTestvector size: " << testvector.size();
        cout << "\nCard " << i;
        cout << ": " << dealingdeck.ReturnDeck()[i - 1].GetCard();
    }
    endtimer(start);

    cout << "###############################\nDeck Popping Test\n###############################\n"
         << endl;
    start = starttimer();
    try
    {
        for (int i = 0; i <52; i++)
        {
            if(dealingdeck.getdecksize()!=0){
            // cout << "\nTestvector size: " << testvector.size();
            // testvector.pop_back();
            dealingdeck.DealFromDeck();
            }
            else{
                cout<<"\nDeck Empty\n";
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    endtimer(start);

    cout << "\n###############################\nAddtodeckTest\n###############################\n"
         << endl;
    start = starttimer();
    for(int j=1;j<=13;j++)
    {
        for(int k=1;k<=2;k++)
        {
            Card newcard(1,j,k);
            dealingdeck.AddToDeck(newcard);
        }
    }
    for(int j=1;j<=13;j++)
    {
        for(int k=3;k<=4;k++)
        {
            Card newcard(2,j,k);
            dealingdeck.AddToDeck(newcard);
        }
    }
    Card newcard(2,13,4);
    dealingdeck.AddToDeck(newcard);
    dealingdeck.AddToDeck(newcard);
    dealingdeck.AddToDeck(newcard);
    Card newcard1(1,13,1);
    Card newcard2(2,13,3);
    dealingdeck.AddToDeckCheat(newcard2);
    dealingdeck.AddToDeckCheat(newcard1);
    dealingdeck.AddToDeck(newcard2);
    dealingdeck.AddToDeck(newcard2);
    dealingdeck.AddToDeckCheat(newcard2);
    dealingdeck.AddToDeckCheat(newcard2);
    dealingdeck.AddToDeckCheat(newcard2);
    dealingdeck.AddToDeck(newcard2);
    endtimer(start);


    cout << "\n###############################\nHand Test\n###############################\n"
         << endl;
    start = starttimer();
    dealingdeck.Shuffle(1);
    Hand myHand(dealingdeck);
    cout<<endl;
    for (int i = 0; i < myHand.CardsInHand.size(); i++)
    {
    cout<<myHand.CardsInHand[i].GetCard()<<endl;
    }
    
    myHand.PlayCard(4);
    myHand.PlayCard(2);
    myHand.AddtoHand(newcard2);
    myHand.PlayCard(2);
    myHand.PlayCard(2);
    myHand.PlayCard(2);

    endtimer(start);
    return 0;
}