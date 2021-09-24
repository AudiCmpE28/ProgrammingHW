#include "headers/printUI.h"
#include "stdio.h"
#include "stdlib.h"

// using std::srand;

printUI::printUI()
{
    roundNumber = 0;
};

void printUI::setVariables(int round)
{
    roundNumber = round;
}

void printUI::printInitialPrompt()
{
    cout
        << "\nWelcome to Rock, Paper, Scissors!\n"
        << "The game is simple, pick rock, paper, or scissors by entering a number between 1 to 3\n"
        << "Paper beats Rock, Scissors beats paper, and Rock bears Scissors.\n"
        << "There will be a total of 20 rounds!\n"
        << "Here are the numbers that represent each moves:\n"
        << "1 -> Rock\n"
        << "2 -> Paper\n"
        << "3 -> Scissors\n"
        << "Please Enter a Number between 1-3 to choose your move! \n";
}

void printUI::printRoundResult(int roundNumber,int result)
{
    if (result == 2) //cpuWin
        cout << "Round #" << roundNumber<< " Result: CPU Wins!\n";
    else if (result == 1) //playerWin
        cout << "Round #" << roundNumber<< " Result: Player Wins!\n";
    else
        cout << "Round #" << roundNumber<< " Result: Tie!\n";
}

int printUI::printRowHelper(string name, int useCase, vector<vector<int>> Rounds)
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
            //Round [i] is the round number, Round[5][1] === Round 6, Player Score 
            if (Rounds[i][1] > 0)
            {
                cout << "W";
                winCount++;
            }
            else if (Rounds[i][1] < 0)
                cout << "L";
            else
                cout << "-";
        }
        else if (useCase == CPUStats)
        {
            if (Rounds[i][0] > 0)
            {
                cout << "W";
                winCount++;
            }
            else if (Rounds[i][0] < 0)
                cout << "L";
            else
                cout << "-";
        }
    }
    cout << "\n";

    return winCount;
}

void printUI::printFinalResults(vector<vector<int>> Rounds)
{
    int CPU, Player = 0;
    enum uses
    {
        incremental,
        playerStats,
        CPUStats
    };

    cout << "#########################################[Round details]##########################################\n";

    printRowHelper("Round", incremental,Rounds);
    Player = printRowHelper("Player Stats", playerStats,Rounds);
    CPU = printRowHelper("CPU Stats", CPUStats,Rounds);

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