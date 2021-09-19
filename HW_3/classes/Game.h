#ifndef GAME_H_
#define GAME_H_
#pragma once

class Game
{
private:
    char scorePlayer;
    char scoreCPU;
    char turn;
public:
    Game(char turn);
    calculateResult(char Playermove, char CPUmove);
};

Game::Game(char turn)
{
this->turn = turn & 1; //0 or 1, start game with player or CPU turn
this->scoreCPU=0;
this->scorePlayer=0;
}


#endif