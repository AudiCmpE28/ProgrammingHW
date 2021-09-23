#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "CPU.h"
#include "printUI.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
// using std::vector;

enum winner
{
    tie = -1,
    playerWin = 1,
    cpuWin = 2
};

extern std::vector<gamedata> Rounds;

class Game
{
private:
    int roundNumber; //tracks actual round

public:
    Game();

    /**
     * @brief Prints the prompt, ask for input per round for 20 rounds, then display a summary table and overall winner
     */
    void executeMatch();

    /**
     * @brief Updates the vector that holds each rounds data and increments roundNumber
     * 
     * @param result: Result of the round (playerWin, cpuWin, tie)
     */
    void updateRound(int result);

    /**
     * @brief 
     * 
     * @param pmove: Player's move (rock, paper, or scissors)
     * @param cpumove CPU's move (rock, paper, or scissors)
     * @return int 
     * If CPU wins: 2 (enum type cpuWin)
     * If player wins: 1 (enum type playerWin)
     * If tied: -1 (enum type tie)
     * @param pmove Player's move
     * @param cpumove Computer's Move
     * @return int  
     */
    int calculateResult(int pmove, int cpumove);
};
#endif /* GAME_H */
