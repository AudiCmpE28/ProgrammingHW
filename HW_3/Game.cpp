#include <iostream>
#include <iomanip>

#include "headers/Game.h"
// #include "headers/printUI.h"
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
    int playerInput;
    CPU cpuTurn;
    Player playerTurn;
    printUI printer;

    printer.printInitialPrompt();
    while (roundNumber < 20)
    {
        cout << "Enter your move for Round #" << roundNumber + 1 << ": ";
        cpuTurn.generateMove();

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
        screenclear();

        cout << "###  Round " << roundNumber + 1 << "  ###\n";
        playerTurn.printPlayerMove();
        cpuTurn.printCPUMove();
        int result = calculateResult(playerTurn.getMove(), cpuTurn.getMove());
        printer.printRoundResult(result);
        updateRound(result);
        cout << endl;
    }
    screenclear();
    cout << "All 20 Rounds have been played! The game is over!\n";

    printer.printFinalResults();
}

void Game::updateRound(int result)
{
    gamedata rounddata;
    if (result == playerWin)
    {
        rounddata.scoreCPU = -1;
        rounddata.scorePlayer = 1;
    }
    else if (result == cpuWin)
    {
        rounddata.scoreCPU = 1;
        rounddata.scorePlayer = -1;
    }
    else if (result == tie)
    {
        rounddata.scoreCPU = 0;
        rounddata.scorePlayer = 0;
    }
    else
    {
        return; //dont push invalid data into vector
    }
    Rounds.push_back(rounddata);
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