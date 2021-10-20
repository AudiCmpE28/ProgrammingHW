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

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::to_string;

void Game::ChoiceExport(vector<vector<int>> choices)
{
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

Game::Game()
{
    // this->turn = turn & 1; //0 or 1, start game with player or CPU turn
    Rounds.reserve(20);
    roundNumber = 0;
}

void Game::initializeGame(int max_rounds, int cpuChoice) {
    maxRounds = max_rounds;
    computer.setchoiceMethod(cpuChoice);
    computer.makeChooser(); // Make chooser based on the cpu choice
}

void Game::executeRound(int playerMove)
{
    player.setMove(playerMove); // use button input to set move
    computer.generateMove(playerMove); // make a move based on educated guest from player move

    int result = calculateResult(player.getMove(), computer.getMove()); // Gets the round result based on the move
    updateRound(result, player.getMove(), computer.getMove()); // Updates the vector with the moves, and who won

}

void Game::exportGameData() {
    if (computer.getchoiceMethod() == 2) // if the game was a smartCPU game
        ChoiceExport(Rounds);
}

void Game::updateRound(int result, int pmove, int cpumove)
{
    vector<int> scores;
    if (result == playerWin)
    {
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
    // Rock =1, Paper=2, Scissors=3
    if ((pmove == cpumove - 1) || (pmove - 2 == cpumove))
        return cpuWin;
    else if ((cpumove == pmove - 1) || (cpumove - 2 == pmove))
        return playerWin;
    else
        return tie;
}

string convertNumToMove(int move) {
    string retValue;
    if (move == 1) 
        retValue = "Rock";
    else if (move == 2) 
        retValue = "Paper";
    else if (move == 3)
        retValue = "Scissors";

    return retValue;
}

string convertNumToWinner(int winner) {
    string retValue;
    if (winner == 1) 
        retValue = "Player Wins!";
    else if (winner == 2) 
        retValue = "CPU Wins!";
    else if (winner == -1)
        retValue = "Tie!";

    return retValue;
}