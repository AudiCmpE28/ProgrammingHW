#ifndef CPU_H
#define CPU_H

#include "ChooserFactory.h"

class CPU
{
private:
    int move;
    int choiceMethod;
    int recentIndex = 0;
    vector<int> recent5[5];

public:
    
    CPU(/* args */);
    void generateMove(int playerChoice);
    int getMove();
    int getchoiceMethod();
    int setchoiceMethod(int choice);
    void printCPUMove();
    void insertRecent(int move1, int move2);
    int getrecentIndex();
    vector<int> getrecent5();
};

#endif /* CPU_H */
