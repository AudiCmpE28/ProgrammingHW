#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
using std::vector;

class Game
{
private:
    struct gamedata
    {
        int scorePlayer;
        int scoreCPU;
    };
    std::vector<gamedata> Rounds;

public:
    Game(/* int turn */);
    int calculateResult(int pmove, int cpumove);
    void updateRound(int result);
};

#endif