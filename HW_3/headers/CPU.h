#ifndef CPU_H
#define CPU_H

#include "ChooserFactory.h"

class CPU
{
private:
    int move;
    int choiceMethod;

public:
    CPU(/* args */);
    void generateMove();
    int getMove();
    int getchoiceMethod();
    void setchoiceMethod(int choice);
    void printCPUMove();
};

#endif /* CPU_H */
