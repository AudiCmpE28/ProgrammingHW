#ifndef SMARTCPU_H
#define SMARTCPU_H

#include <iostream>

#include "Chooser.h"

class SmartCPU : public Chooser
{
private:
    //int recent5[5] = {0, 0, 0, 0, 0};
    int MLdata[243];
    int dataCount[243];
    //int recentIndex = 0;
    int arrCount;

public:
    SmartCPU();
    int make_choice(int playerChoice);
    //void insertRecent(int move1, int move2);
    void readData();
    int searchArray(int search);
};

#endif /* SMARTCPU_H */