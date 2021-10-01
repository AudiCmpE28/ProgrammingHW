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

void Game::executeMatch()
{
    int playerInput, cpuChoice;
    ofstream fileptr;
    Player playerTurn;
    CPU cpuTurn;
    printUI printer;
    screenclear();

    cout << "Choose how you want the CPU to pick his move:\n"
         << "1 -> Random\n"
         << "2 -> Smart\n"
         << "3 -> Genius\n"
         << "Enter Number: ";
    while (true)
    {
        cin >> cpuChoice;

        if ((cin) && (cpuChoice >= 1) && (cpuChoice <= 3))
            break;
        screenclear();
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input! Please enter a number between 1-3\n"
             << "Enter Number for Choice: ";
    }

    cpuTurn.setchoiceMethod(cpuChoice);
    cpuTurn.makeChooser();
    screenclear();
    printer.printInitialPrompt();
    while (roundNumber < MAXROUNDS)
    {
        cout << "Enter your move for Round #" << roundNumber + 1 << ": ";

        while (true)
        {
            cin >> playerInput;

            if ((cin) && (playerInput >= 1) && (playerInput <= 3))
                break;
            screenclear();
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input! Please enter a number between 1-3\n"
                 << "Your move: ";
        }
        playerTurn.setMove(playerInput);
        cpuTurn.generateMove(playerInput);
        screenclear();

        cout << "###  Round " << roundNumber + 1 << "  ###\n";
        playerTurn.printPlayerMove();
        cpuTurn.printCPUMove();
        int pmove = playerTurn.getMove();
        int cpumove = cpuTurn.getMove();
        int result = calculateResult(pmove, cpumove);
        printer.printRoundResult(roundNumber + 1, result);
        updateRound(result, pmove, cpumove);
        cout << endl;
    }
    screenclear();
    cout << "All 20 Rounds have been played! The game is over!\n";

    if (cpuTurn.getchoiceMethod() == 2)
        ChoiceExport(Rounds);
    printer.printFinalResults(Rounds);
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