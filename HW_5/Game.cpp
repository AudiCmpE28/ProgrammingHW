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

#define MAXROUNDS 20

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

void Game::executeMatch()
{
    int playerInput, cpuChoice, maxRounds;
    ofstream fileptr;
    Player playerTurn;
    CPU cpuTurn;

    // somehow get input from screen to cpuChoice
    cin >> cpuChoice;
    // get max rounds from screen
    cin >> maxRounds;
    cpuTurn.setchoiceMethod(cpuChoice);
    cpuTurn.makeChooser(); // make chooser based on CPU choice
    // Print instructions somewhere on the screen around this point
    while (roundNumber < maxRounds) // roundNumber part of the game class, updated in updateRound class
    {
        // get player input from button
        cin >> playerInput;

        playerTurn.setMove(playerInput); // use button input to set move
        cpuTurn.generateMove(playerInput); // make a move based on educated guest from player move

        playerTurn.printPlayerMove(); // Function used to print player move, move this to UI
        cpuTurn.printCPUMove(); // Function used to print CPU move, move this to UI by calling "move" variable in class 
        int pmove = playerTurn.getMove();
        int cpumove = cpuTurn.getMove();
        int result = calculateResult(pmove, cpumove); // Gets the round result based on the move
        // printer.printRoundResult(roundNumber + 1, result); // Print result on UI, so get rid of this and print in UI instead
        updateRound(result, pmove, cpumove); // Updates the vector with the moves, and who won
    }

    // Game is over once while loop is over

    if (cpuTurn.getchoiceMethod() == 2)
        ChoiceExport(Rounds); // Export round results to file
    // printer.printFinalResults(Rounds); // print final results, but this should be moved to UI
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