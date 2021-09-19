#include "Game.h"


void Game::updateRound(int result)
{
    gamedata rounddata;
    if(result==1)
    {
        rounddata.scoreCPU=0;
        rounddata.scorePlayer=1;
    }
    else if(result==2)
    {
        rounddata.scoreCPU=1;
        rounddata.scorePlayer=0;
    }
    else if(result==-1)
    {
        rounddata.scoreCPU=0;
        rounddata.scorePlayer=0;
    }
    else{
        return; //dont push invalid data into vector
    }
    this->Rounds.push_back(rounddata);
}

int Game::calculateResult(int pmove, int cpumove)
{
    //Rock =1, Paper=2, Scissors=3
    //Player win, return 1
    //CPU win, return 2
    if(pmove==cpumove)
    return -1; //draw
    else if(pmove==1 && cpumove ==2)
    return 2; //CPU Win
    else if(pmove==1 && cpumove ==3)
    return 1; //Player win
    else if(pmove==2 && cpumove ==1)
    return 1; //Player win
    else if(pmove==2 && cpumove ==3)
    return 2; //CPU win
    else if(pmove==3 && cpumove ==1)
    return 2; //CPU win
    else if(pmove==3 && cpumove ==2)
    return 1; //Player win
}
