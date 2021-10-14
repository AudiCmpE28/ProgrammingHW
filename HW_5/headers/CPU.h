#ifndef CPU_H
#define CPU_H

#include "ChooserFactory.h"

class CPU
{
private:
    int move;
    int choiceMethod;
    Chooser *chooser;

public:
    CPU(/* args */);
    void generateMove(int playerChoice);
    void makeChooser();
    int getMove();
    int getchoiceMethod();
    void setchoiceMethod(int choice);
    void printCPUMove();
};

#endif /* CPU_H */
