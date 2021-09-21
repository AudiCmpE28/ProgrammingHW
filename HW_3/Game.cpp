#include "headers/Game.h"
// #include "headers/CPU.h"
// #include "headers/Player.h"
#include "stdio.h"
#include "stdlib.h"
#include <iomanip>

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

void Game::gameMatch()
{
    int playerInput;
    CPU cpuTurn;
    Player playerTurn;

    cout << endl
         << "\n1 -> Rock\n"
         << "2 -> Paper\n"
         << "3 -> Scissors\n"
         << "Please Enter a Number between 1-3: ";
    // while (roundNumber < 20)
    while (roundNumber < 20) //testing purposes: rounds = 5
    {
        cin >> playerInput;
        screenclear();
        cout << "\n###Rock Paper Scissors###\n";

        if (playerTurn.playMove(playerInput) == -1)
        {
            cout << "\n\nInvalid Input! TRY AGAIN\n\n";
        }
        else
        {
            int res = (calculateResult(playerInput, cpuTurn.playMove()));
            cout << "\nRound " << roundNumber + 1 << " winner is " << res << "\n";
            updateRound(res);
        }
    }
    screenclear();
    cout << "\nEnd of Game";
    outputresults();
}
void Game::outputresults()
{
    int CPU, Player = 0;

    cout << "\n######################################### Round details #########################################";
    cout << "\n# Round \t:";
    for (int i = 0; i < Rounds.size(); i++)
    {
        cout.setf(std::ios_base::right);
        cout.width(4);
        cout << i + 1;
    }
    cout << "\n# Player\t:";
    for (int i = 0; i < Rounds.size(); i++)
    {
        cout.setf(std::ios_base::right);
        cout.width(4);
        Player += Rounds[i].scorePlayer;
        cout << Rounds[i].scorePlayer;
    }
    cout << "\n# CPU   \t:";
    for (int i = 0; i < Rounds.size(); i++)
    {
        cout.setf(std::ios_base::right);
        cout.width(4);
        CPU += Rounds[i].scoreCPU;
        cout << Rounds[i].scoreCPU;
    }

    //tally up score
    cout << "\n# Player Total\t:\t" << Player << "\n# CPU Total\t:\t" << CPU;

    if (CPU > Player)
        cout << "\n\n# CPU WINS";

    else if (Player > CPU)
        cout << "\n\n# PLAYER WINS";

    else
        cout << "\n\n# MATCH WAS A DRAW!";

    cout << "\n#################################################################################################";
}

int Game::calculateResult(int pmove, int cpumove)
{
    //Rock =1, Paper=2, Scissors=3
    //Player win, return 1
    //CPU win, return 2
    if (pmove == cpumove)
        return -1; //draw
    else if (pmove == 1 && cpumove == 2)
        return 2; //CPU Win
    else if (pmove == 1 && cpumove == 3)
        return 1; //Player win
    else if (pmove == 2 && cpumove == 1)
        return 1; //Player win
    else if (pmove == 2 && cpumove == 3)
        return 2; //CPU win
    else if (pmove == 3 && cpumove == 1)
        return 2; //CPU win
    else if (pmove == 3 && cpumove == 2)
        return 1; //Player win
    else
        return 0;
}

void Game::updateRound(int result)
{
    gamedata rounddata;
    if (result == 1)
    {
        rounddata.scoreCPU = 0;
        rounddata.scorePlayer = 1;
    }
    else if (result == 2)
    {
        rounddata.scoreCPU = 1;
        rounddata.scorePlayer = 0;
    }
    else if (result == -1)
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
