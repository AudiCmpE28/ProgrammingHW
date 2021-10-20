#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "headers/Game.h"
#include "headers/RandomCPU.h"
#include "headers/SmartCPU.h"
#include "headers/ChooserFactory.h"
#include "stdio.h"
#include "stdlib.h"

// #include <wx/wx.h>
// #include "headers/RPSmain.h"
// #include "headers/RPSsetup.h"
#include "headers/RPSframe.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::to_string;


void Game::ChoiceExport(vector<vector<int>> choices) {
    int roundSIZE = choices.size();
    int count = 0;
    ofstream fileptr;
    fileptr.open("Choices.txt", std::ios_base::app);
    if (fileptr.is_open())
    {
        string temp = "";
        for (int i = 0; i < roundSIZE; i++)
        {
            temp += to_string(choices[i][3]); // Player move
            if (temp.length() == 5)
            {
                ; // do nothing
            }
            else
                temp += to_string(choices[i][2]); // CPU move
            if (temp.length() == 5)
            {
                fileptr << temp << "\n";
                temp = "";
            }
        }
        fileptr.close();
    }
}

void screenclear()
{
    system("@cls||clear");
}

Game::Game()
{
    // this->turn = turn & 1; //0 or 1, start game with player or CPU turn
    Rounds.reserve(20);
    roundNumber = 0;
}

void Game::executeSetup(int setRounds, int setCPUmode) {
    cout << "Rounds: " << setRounds << endl;
    cout << "CPU Mode: " << setCPUmode << endl;
    player_round_amount = setRounds;
    cpu_chosen_mode = setCPUmode;
    
    cpuTurn.setchoiceMethod(cpu_chosen_mode); //cpu_chosen_mode
    cpuTurn.makeChooser();
}


GameStats Game::executeMatch(int playerInput) {
    GameStats Round_stats = {0};
    ofstream fileptr;
            
    
    playerTurn.setMove(playerInput);
    cpuTurn.generateMove(playerInput);
    
    int pmove = playerTurn.getMove();
    Round_stats.CPU_move = cpuTurn.getMove();
    Round_stats.Round_Winner = calculateResult(pmove, Round_stats.CPU_move);

    updateRound(Round_stats.Round_Winner, pmove, Round_stats.CPU_move);
    

    return Round_stats;
}

void Game::updateRound(int result, int pmove, int cpumove)
{
    vector<int> scores;
    if (result == playerWin) {
        scores.push_back(-1); //cpu loss
        scores.push_back(1);  //player win
        scores.push_back(cpumove);
        scores.push_back(pmove);
    }
    else if (result == cpuWin)
    {
        scores.push_back(1);  //cpu win
        scores.push_back(-1); //player loss
        scores.push_back(cpumove);
        scores.push_back(pmove);
    }
    else if (result == tie)
    {
        scores.push_back(0);
        scores.push_back(0);
        scores.push_back(cpumove);
        scores.push_back(pmove);
    }
    else
    {
        return; //dont push invalid data into vector
    }
    Rounds.push_back(scores);
    roundNumber++;
}



int Game::calculateResult(int pmove, int cpumove)
{
    enum move
    {
        rock = 1,
        paper,
        scissors
    };
    // Rock =1, Paper=2, Scissors=3
    if ((pmove == cpumove - 1) || (pmove - 2 == cpumove))
        return cpuWin;
    else if ((cpumove == pmove - 1) || (cpumove - 2 == pmove))
        return playerWin;
    else
        return tie;
}