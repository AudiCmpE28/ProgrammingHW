#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "CPU.h"
#include "printUI.h"
#include "ChooserFactory.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::ofstream;
using std::right;
using std::setw;
using std::string;
using std::vector;
<<<<<<< HEAD

enum winner
{
    tie = -1,
    playerWin = 1,
    cpuWin = 2
};
=======
>>>>>>> 9bb993587a9342a9ec542450dfd79874961d8471

class Game
{
private:
    int scorePlayer;
    int scoreCPU;
    int roundNumber;            //tracks actual round
    vector<vector<int>> Rounds; //Cpu index 0, player index 1
    enum winner
    {
        tie = -1,
        playerWin = 1,
        cpuWin = 2
    };

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
<<<<<<< HEAD
    void updateRound(int result, int pmove, int cpumove);
=======
    void updateRound(int result);
>>>>>>> 9bb993587a9342a9ec542450dfd79874961d8471

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
<<<<<<< HEAD
=======

    // /**
    //  * @brief getter for Rounds
    //  *
    //  * @return vector<gamedata>
    //  */
    // vector<vector<int>> returnRounds();

    // /**
    //  * @brief Get the roundNumber
    //  *
    //  * @return int
    //  */
    // int getRoundNumber();
>>>>>>> 9bb993587a9342a9ec542450dfd79874961d8471
};
#endif /* GAME_H */
