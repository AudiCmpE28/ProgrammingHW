#include "headers/Game.h"
// #include "headers/CPU.h"
// #include "headers/Player.h"
#include "stdio.h"
#include "stdlib.h"
#include <iomanip>

void screenclear(){
    system("@cls||clear");
}

Game::Game()
{
    // this->turn = turn & 1; //0 or 1, start game with player or CPU turn
    this->Rounds.reserve(20);
    roundNumber = 0;
}

void Game::printInitialPrompt() {
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

void Game::printRoundResult(int result) {
    if (result == cpuWin)
        cout << "Round #" << roundNumber+1 << " Result: CPU Wins!\n";
    else if (result == playerWin)
        cout << "Round #" << roundNumber+1 << " Result: Player Wins!\n";
    else 
        cout << "Round #" << roundNumber+1 << " Result: Tie!\n";

}
void Game::executeMatch()
{
    int playerInput;
    CPU cpuTurn;
    Player playerTurn;

    printInitialPrompt();

    // while (roundNumber < 20)
    while (roundNumber < 20) //testing purposes: rounds = 5
    {
        cout << "Enter your move for Round #" << roundNumber+1 << ": ";
        cin >> playerInput;
        cout << endl;
        playerTurn.setMove(playerInput);
        cpuTurn.generateMove();
        screenclear();

        while (playerTurn.getMove() == -1)
        {
            cout << "Invalid Input! Please enter a number between 1-3\n"
            << "Your move: ";
            cin >> playerInput;
            playerTurn.setMove(playerInput);
            screenclear();
        }
        cout << "###  Round " << roundNumber+1 << "  ###\n";
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
void Game::printFinalResults(){
    int CPU,Player=0;

    cout<<"\n######################################### Round details #########################################";
    cout<<"\n# Round \t:";
    for(int i=0;i<Rounds.size();i++)
    {
    cout.setf(std::ios_base::right);
    cout.width(4);
    cout<<i+1;
    }
    cout<<"\n# Player\t:";
    for(int i=0;i<Rounds.size();i++)
    {
        cout.setf(std::ios_base::right);
        cout.width(4);
        Player+=Rounds[i].scorePlayer;
        cout<<Rounds[i].scorePlayer;
    }
    cout<<"\n# CPU   \t:";
    for(int i=0;i<Rounds.size();i++)
    {
        cout.setf(std::ios_base::right);
        cout.width(4);
        CPU+=Rounds[i].scoreCPU;
        cout<<Rounds[i].scoreCPU;
    }

    //tally up score
    cout<<"\n# Player Total\t:\t"<<Player<<"\n# CPU Total\t:\t"<<CPU;
    if(CPU>Player) cout<<"\n\n# CPU WINS";
    else if(Player>CPU) cout<<"\n\n# PLAYER WINS";
    else cout<<"\n\n# MATCH WAS A DRAW!";
    cout<<"\n#################################################################################################";

}

void Game::updateRound(int result)
{
    gamedata rounddata;
    if (result == playerWin)
    {
        rounddata.scoreCPU = 0;
        rounddata.scorePlayer = 1;
    }
    else if (result == cpuWin)
    {
        rounddata.scoreCPU = 1;
        rounddata.scorePlayer = 0;
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
    enum move {rock = 1, paper, scissors};
    // Rock =1, Paper=2, Scissors=3
    if ((pmove == cpumove - 1) || (pmove - 2 == cpumove))
        return cpuWin;
    else if ((cpumove == pmove - 1) || (cpumove - 2 == pmove))
        return playerWin;
    else 
        return tie;
}