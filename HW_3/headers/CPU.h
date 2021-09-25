#ifndef CPU_H
#define CPU_H

#include "ChooserFactory.h"

class CPU
{
private:
    int move;

public:
    CPU(/* args */);

    void generateMove(int which);
    int getMove();
    void printCPUMove();
};

#endif /* CPU_H */
