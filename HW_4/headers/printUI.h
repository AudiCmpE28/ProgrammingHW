#ifndef PRINTUI_H
#define PRINTUI_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
// #include "Game.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::vector;


class printUI
{
private:
    int roundNumber;
    vector<vector<int> > Rounds;
public:
    printUI();

    void setVariables(int round);

    /**
     * @brief prints the instructions of the game
     */
    void printInitialPrompt();

    /**
     * @brief Prints the round number and who won that round along with newline
     * @param roundNumber: the round number 
     * @param result: pass in the result of the round
     */
    void printRoundResult(int roundNumber,int result);

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
    int printRowHelper(string name, int useCase, vector<vector<int> > Rounds);
    
    /**
     * @brief Displays a table with the rounds, who won, total wins, and game result
     */
    void printFinalResults(vector<vector<int> > Rounds);
};

#endif /* printUI.h */