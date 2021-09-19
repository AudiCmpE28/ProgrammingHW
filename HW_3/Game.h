#ifndef GAME_H_
#define GAME_H_
#include <vector>
using std::vector;
class Game
{
private:
    struct gamedata
    {
        int scorePlayer;
        int scoreCPU;
    };
    std::vector<gamedata>Rounds;
public:
    Game(/* int turn */);
    int calculateResult(int pmove, int cpumove);
    void updateRound(int result);

};

Game::Game(/* int turn */)
{
// this->turn = turn & 1; //0 or 1, start game with player or CPU turn
Rounds.reserve(20);
}


#endif