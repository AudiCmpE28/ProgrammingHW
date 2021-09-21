#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"
#include "CPU.h"

using std::string;
using std::cout; using std::cin; using std::endl; //needed for string
using std::vector;

enum winner {tie= -1, playerWin = 1, cpuWin = 2};

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


    void updateRound(int result);
    /* Parameters: Result of the round (playerWin, cpuWin, tie)
     * Updates the vector that holds each rounds data and increments roundNumber
     */

    int calculateResult(int pmove, int cpumove);
    /* Parameters: Player's move (pmove), Computer's Move (cpumove)
     * returns:
     * If CPU wins: 2 (enum type cpuWin)
     * If player wins: 1 (enum type playerWin)
     * If tied: -1 (enum type tie)
     */
    
};
#endif /* GAME_H */
