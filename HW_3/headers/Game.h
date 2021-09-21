#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "CPU.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
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
    /**
     * @brief prints the instructions of the game
     */
    void printInitialPrompt();

    /**
     * @brief Prints the round number and who won that round along with newline
     * @param result: pass in the result of the round
     */
    void printRoundResult(int result);
    
    /**
     * @brief Used to help print in printFinalResults()
     * 
     * @param name: Name of row
     * @param useCase: what is the row used for
     * incremental: prints increasing number from 1 to size of gamedata vector
     * playerStats: Prints whether the player won or lost in order of round 1 to size of gamedata vector
     * CPUStats: Prints whether the CPU won or lost in order of round 1 to size of gamedata vector
     * @return int: the amount of wins the row calculated (if the use case is playerStats or CPUStats)
     */
    int printRowHelper(string name, int useCase);

    /**
     * @brief Displays a table with the rounds, who won, total wins, and game result
     */
    void printFinalResults();

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
     */
    int calculateResult(int pmove, int cpumove);

};
#endif /* GAME_H */
