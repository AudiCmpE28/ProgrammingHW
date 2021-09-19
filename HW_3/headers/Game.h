#ifndef GAME_H
#define GAME_H
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
    std::vector<gamedata> Rounds;

public:
    Game();
    void updateRound(int result);
    int calculateResult(int pmove, int cpumove);
};
#endif /* GAME_H */
