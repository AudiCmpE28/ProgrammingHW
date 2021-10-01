#ifndef SMARTCPU_H
#define SMARTCPU_H

#include <iostream>

#include "Chooser.h"

class SmartCPU : public Chooser
{
private:
    int recent5[5];
    int MLdata[243];
    int dataCount[243];
    int recentIndex;
    int arrCount;

public:
    int make_choice(int playerChoice);
    void insertRecent(int move1, int move2);
    void readData();
    int searchArray();
};

#endif /* SMARTCPU_H */