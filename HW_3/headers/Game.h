#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include "CPU.h"

using std::string;
using std::cout;using std::cin;using std::endl; //needed for string
using std::vector;

class Game
{
private:
    struct gamedata
    {
        int scorePlayer;
        int scoreCPU;
    };
    std::vector<gamedata> Rounds; //tracks score
    int roundNumber;              //tracks actual round

public:
    Game();
    void gameMatch();
    void updateRound(int result);
    void outputresults();
    int calculateResult(int pmove, int cpumove);
};
#endif /* GAME_H */
