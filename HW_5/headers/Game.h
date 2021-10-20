#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "CPU.h"
#include "ChooserFactory.h"
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::vector;
using std::ofstream;

class Game
{
private:
    int roundNumber;            //tracks actual round
    int maxRounds;
    vector<vector<int>> Rounds; //Cpu index 0, player index 1
    Player player;
    CPU computer;
    enum winner
    {
        tie = -1,
        playerWin = 1,
        cpuWin = 2
    };
    enum moveTypes
    {
        rock = 1,
        paper,
        scissors
    };

public:
    Game();

    /**
     * @brief Pass in a filepointer and vector<vector<int> > Rounds
     * 
     * @param fileptr 
     * @param choices 
     */
    void ChoiceExport(vector<vector<int> > choices);

    /**
     * @brief Set the player move, make the CPU move, calculate and save winner, update round
     */
    void executeRound(int playerMove);

    /**
     * @brief Initialize how many rounds and what the CPU chooser is
     */
    void initializeGame(int round, int cpuChoice);

    /**
     * @brief Used at the end of the game to export game data for smartCPU games
     */
    void exportGameData();

    /**
     * @brief Updates the vector that holds each rounds data and increments roundNumber
     * @param result: Result of the round (playerWin, cpuWin, tie)
     * @param pmove: Player move, 1, 2, 3
     * @param cpumove: CPU move, 1, 2, 3
     */
    void updateRound(int result,int pmove, int cpumove);

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
