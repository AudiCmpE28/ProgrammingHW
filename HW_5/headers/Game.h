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

#include <wx/wx.h>


class RPS_Frame;

struct GameStats{
    int Round_Winner;
    int CPU_prediction;
    int CPU_move;
    int CPU_wins;
    int Player_wins;
    int total_ties;
};


class Game {
    private:
        int scorePlayer;
        int scoreCPU;
        int roundNumber;            //tracks actual round
        vector<vector<int> > Rounds; //Cpu index 0, player index 1
        enum winner {
            tie = -1,
            playerWin = 1,
            cpuWin = 2
        };
        Player playerTurn;
        CPU cpuTurn;
        RPS_Frame *RPS_Game_Frame; 
        int player_round_amount;
        int cpu_chosen_mode;

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
         * @brief Prints the prompt, ask for input per round for 20 rounds, then display a summary table and overall winner
         */
        
        
        void executeSetup(int setRounds, int setCPUmode);
        GameStats executeMatch(int playerInput); //play players move
        int get_Round_Winner();
        int get_CPU_prediction();
        int get_CPU_wins();
        int get_Player_wins();
        int get_total_ties();

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
