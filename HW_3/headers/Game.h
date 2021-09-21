#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include "CPU.h"

using std::cin;
using std::cout;
using std::endl; //needed for string using std::string;
using std::vector;

enum winner
{
    tie = -1,
    playerWin = 1,
    cpuWin = 2
};

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
    void printInitialPrompt();
    void printRoundResult(int result);
    void printFinalResults();
    void executeMatch();

    /**
     * @brief Updates the vector that holds each rounds data and increments roundNumber 
     * 
     * @param result Result of the round (playerWin, cpuWin, tie)
     */
    void updateRound(int result);

    /**
     * @brief If CPU wins: 2 (enum type cpuWin)
     * If player wins: 1 (enum type playerWin)
     * If tied: -1 (enum type tie)
     * @param pmove Player's move
     * @param cpumove Computer's Move
     * @return int  
     */
    int calculateResult(int pmove, int cpumove);
};
#endif /* GAME_H */
