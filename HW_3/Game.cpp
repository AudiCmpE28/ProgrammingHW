#include <iostream>
#include <iomanip>

#include "headers/Game.h"
#include "stdio.h"
#include "stdlib.h"

void screenclear()
{
    system("@cls||clear");
}

Game::Game()
{
    // this->turn = turn & 1; //0 or 1, start game with player or CPU turn
    this->Rounds.reserve(20);
    roundNumber = 0;
}

void Game::printInitialPrompt()
{
    cout
        << "\nWelcome to Rock, Paper, Scissors!\n"
        << "The game is simple, pick rock, paper, or scissors by entering a number between 1 to 3\n"
        << "Paper beats Rock, Scissors beats paper, and Rock bears Scissors.\n"
        << "There will be a total of 20 rounds!\n"
        << "Here are the numbers that represent each moves:\n"
        << "1 -> Rock\n"
        << "2 -> Paper\n"
        << "3 -> Scissors\n";
}

void Game::printRoundResult(int result)
{
    if (result == cpuWin)
        cout << "Round #" << roundNumber + 1 << " Result: CPU Wins!\n";
    else if (result == playerWin)
        cout << "Round #" << roundNumber + 1 << " Result: Player Wins!\n";
    else
        cout << "Round #" << roundNumber + 1 << " Result: Tie!\n";
}

int Game::printRowHelper(string name, int useCase)
{
    enum uses
    {
        incremental,
        playerStats,
        CPUStats
    };
    int winCount = 0;
    cout << "# " << left << setw(15) << name;
    cout << ":";
    for (int i = 0; i < Rounds.size(); i++)
    {
        cout.setf(std::ios_base::right);
        cout << setw(4);
        if (useCase == incremental)
            cout << i + 1;
        else if (useCase == playerStats)
        {
            if (Rounds[i].scorePlayer > 0)
            {
                cout << "W";
                winCount++;
            }
            else if (Rounds[i].scorePlayer < 0)
                cout << "L";
            else
                cout << "-";
        }
        else if (useCase == CPUStats)
        {
            if (Rounds[i].scoreCPU > 0)
            {
                cout << "W";
                winCount++;
            }
            else if (Rounds[i].scoreCPU < 0)
                cout << "L";
            else
                cout << "-";
        }
    }
    cout << "\n";

    return winCount;
}

void Game::executeMatch()
{
    int playerInput, cpuAlgo;
    CPU cpuTurn;
    Player playerTurn;

    printInitialPrompt();
    cout << "Choose how you want the CPU to pick his move:\n"
         << "1 -> Random\n"
         << "2 -> Smart\n"
         << "3 -> Genius\n"
         << "Enter Number: ";
    cin >> cpuAlgo;

    while (roundNumber < 20)
    {
        cout << "Enter your move for Round #" << roundNumber + 1 << ": ";
        cpuTurn.generateMove(cpuAlgo);

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
        printRoundResult(result);
        updateRound(result);
        cout << endl;
    }
    screenclear();
    cout << "All 20 Rounds have been played! The game is over!\n";
    printFinalResults();
}

void Game::printFinalResults()
{
    int CPU, Player = 0;
    enum uses
    {
        incremental,
        playerStats,
        CPUStats
    };

    cout << "#########################################[Round details]##########################################\n";

    printRowHelper("Round", incremental);
    Player = printRowHelper("Player Stats", playerStats);
    CPU = printRowHelper("CPU Stats", CPUStats);

    //tally up score
    cout << "# " << left << setw(15) << "Player Total"
         << left << setw(4) << ":" << Player << "\n";
    cout << "# " << left << setw(15) << "CPU Total"
         << left << setw(4) << ":" << CPU << "\n";
    if (CPU > Player)
        cout << "###########################################[CPU WINS]#############################################";
    else if (Player > CPU)
        cout << "##########################################[PLAYER WINS]###########################################";
    else
        cout << "#############################################[DRAW]###############################################";
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
    this->Rounds.push_back(rounddata);
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