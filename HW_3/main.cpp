#include <iostream>
#include "Game.h"
#include "Player.h"
#include "CPU.h"
#include <random>
using std::srand;
using std::cout;using std::endl;using std::rand;
int main()
{
    srand(124719279); //input time null
    Game initgame;
    cout<<"Wtf man\n";
    for (int i = 0; i < 23; i++)
    {
    cout<<rand()<<endl;
    }
    
    cout<<"Rock vs Paper: "<<initgame.calculateResult(1,2)<<endl;
    return 0;
}