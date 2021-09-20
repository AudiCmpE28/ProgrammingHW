#include "headers/Game.h"
// #include "headers/CPU.h"
// #include "headers/Player.h"

Game::Game()
{
    // this->turn = turn & 1; //0 or 1, start game with player or CPU turn
    this->Rounds.reserve(20);
    roundNumber = 0;
}

string Game::gameMatch()
{
    int playerInput;
    CPU cpuTurn;
    Player playerTurn;

    // while (roundNumber < 20)
    while (roundNumber < 5) //testing purposes: rounds = 5
    {
        cout << endl
             << "1 -> Rock\n"
             << "2 -> Paper\n"
             << "3 -> Scissors\n"
             << "Please Enter a Number between 1-3: ";
        cin >> playerInput;

        if (playerTurn.playMove(playerInput) == -1)
        {
            cout << "\n\nInavlid Input Dumbass! TRY AGAIN\n\n";
        }
        else
        {
            updateRound(calculateResult(playerInput, cpuTurn.playMove()));
        }
    }
    return "End of Game";
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
