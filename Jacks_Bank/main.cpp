// #include <iostream>

// #include "header/Card.h"
// #include "header/Game.h"
// using namespace std;

// // for testing
// #include <chrono>
// #include <thread>
// using namespace std::this_thread;
// using namespace std::chrono_literals;

// #if 0
// // Test drive of an actual game
// int main() {
//     Game game1;
//     int count = 4;
//     while(1) {
//         sleep_for(2s);
//         cout << "<<<<<<<<<NEW GAME>>>>>>>>>" << endl;
//         int choice = 100;
//         game1.setPlayerBet(10);
//         game1.initHands();
//         game1.printUI();

//         while (choice && !game1.stopGame()) {
//             cout << "Do you want to hit(1) or stay(0)? " << endl;
//             cout << "Type Choice: ";
//             cin >> choice;
//             if (choice) 
//                 game1.playerHit(true);
//             else 
//                 game1.playerHit(false);
//             game1.printUI();
//         }      

//         game1.dealerTurn();

//         cout << "Here are the final results!" << endl;
//         game1.printUI();
//     }

//     cout << "Games are done!" << endl;
//     return 0;
// }
// #endif

// #if 1
// int main()
// {
//     Player *playerinstance= new Player(); //original player instance, which is modified via pointers in game
//     Bank playerbank;
//     cout<<"Please enter your username\n";
//     string usrn;
//     cin>>usrn;
//     while(usrn.size()==0 || usrn.size()>16)
//         cin>>usrn;

//     while(1)
//     { //A: goto this after player finishes game or bank transactions
//         cout<<"Hello "<<usrn<<endl;
//         int option;
//         cout << "Press 1 to start a match, or press 2 to view your Bank\n";
//         cin>>option;
//         // while(option!=1 || option!=2)cin>>option;

//         if(option==1)
//         {
//             Game gameinstance(playerinstance); //instantiate the game when player chooses to play it, then pass in player pointer
//             sleep_for(2s);
//             while(option==1 && !gameinstance.stopGame())
//             {
//                 //TODO: Add betting options, easy 10, med 50, hard 100.

//                 gameinstance.setPlayerBet(10);
//                 gameinstance.initHands();
//                 gameinstance.printUI();
//                 int choice=1;
//                 while(choice && !gameinstance.stopGame()) //TODO: end game when N rounds played, or player reaches $0
//                 {
//                     cout << "Do you want to hit(1) or stay(0)? " << endl;
//                     cout << "Type Choice: ";
//                     cin >> choice;
//                     // while(choice!=1 || choice!=0)cin>>choice;
                    
//                     if (choice) 
//                         gameinstance.playerHit(true);
//                     else 
//                         gameinstance.playerHit(false);
//                     gameinstance.printUI();
//                 }
//                 gameinstance.dealerTurn();

//                 cout << "Here are the final results!" << endl;
//                 gameinstance.printUI();
//             }
//             cout << "Games are done!" << endl;
//             continue;//reset back to A
//         }
//         else if(option==2)
//         {
            
//             cout<<"Welcome to Jack's Bank\nYour current Balance is "<<playerbank.getBalance()<<endl;
//             cout<<"Would you like to Withdraw(1) or Deposit(2)?\n";
//             while(option==2)
//                 {
//                 int bankchoice=-1;
//                 cin>>bankchoice;
//                 // while(bankchoice!=1 ||bankchoice!=2)cin>>bankchoice;
//                 double cash;
//                 if(bankchoice==1)
//                 {
//                     cout<<"How much would you like to withdraw?\n";
//                     cin>>cash;
//                     // while(!isdigit(cash))cin>>cash;
//                     playerinstance->withdrawFromBank(cash);
//                     playerbank.withdraw(cash);
//                 }
//                 else if (bankchoice==2)
//                 {
//                     cout<<"How much would you like to deposit?\n";
//                     cin>>cash;
//                     // while(!isdigit(cash))cin>>cash;
//                     playerinstance->depositInBank(cash);
//                     playerbank.deposit(cash);
//                 }
//                 break;//i was intending for it to prompt forever to W/D until user picked a 3rd choice but this is more simple
//             }
//             continue;
//         }
//     }

// }
// #endif
// #if 0
// // Example of testing iterator, Card class, DeckOfCards class
// int main() {
//     int count = 1;
//     DeckOfCards deck1;
//     cout << "Initial top 10 cards\n";
//     CardIterator CardIter = deck1.createIterator();
//     Card temp = CardIter.current_item();

//     cout << count << ": ";
//     count++;
//     temp.printCardDetails();
//     while(!CardIter.is_done()) {
//         cout << count << ": ";
//         count++;
//         temp = CardIter.next();
//         temp.printCardDetails();
//     }

//     count = 1;
//     CardIter = deck1.createIterator();
//     temp = CardIter.current_item();

//     cout << count << ": ";
//     count++;
//     temp.printCardDetails();
//     while(!CardIter.is_done()) {
//         cout << count << ": ";
//         count++;
//         temp = CardIter.next();
//         temp.printCardDetails();
//     }


//     return 0;
// }

// #endif

// // How to compile for testing
// // g++ main.cpp Card.cpp DeckOfCards.cpp -o main
// // include all cpp that is part of main in that list.