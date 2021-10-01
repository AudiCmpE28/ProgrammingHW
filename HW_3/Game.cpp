#include <iostream>
#include <iomanip>

#include "headers/Game.h"
#include "headers/RandomCPU.h"
#include "headers/ChooserFactory.h"
#include "stdio.h"
#include "stdlib.h"

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
    Player playerTurn;
    CPU cpuTurn;
    printUI printer;
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
    screenclear();
    printer.printInitialPrompt();
    while (roundNumber < 20)
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
        cpuTurn.insertRecent(playerInput, cpuTurn.getMove());
        //screenclear();

        cout << "###  Round " << roundNumber + 1 << "  ###\n";
        playerTurn.printPlayerMove();
        cpuTurn.printCPUMove();
        int result = calculateResult(playerTurn.getMove(), cpuTurn.getMove());
        printer.printRoundResult(roundNumber + 1, result);
        updateRound(result);
        cout << endl;
    }
    screenclear();
    cout << "All 20 Rounds have been played! The game is over!\n";

    printer.printFinalResults(Rounds);
}

void Game::updateRound(int result)
{
    vector<int> scores;
    if (result == playerWin)
    {
        scores.push_back(-1); //cpu loss
        scores.push_back(1);  //player win
    }
    else if (result == cpuWin)
    {
        scores.push_back(1);  //cpu win
        scores.push_back(-1); //player loss
    }
    else if (result == tie)
    {
        scores.push_back(0);
        scores.push_back(0);
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

// vector<vector<int>> Game::returnRounds()
// {
//     //A vector of 20 vectors (20 rounds)
//     return this->Rounds;
// }

// int Game::getRoundNumber(){
//     return this->roundNumber;
// }
