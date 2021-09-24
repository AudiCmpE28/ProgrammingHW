#ifndef RANDOMCHOOSER_H
#define RANDOMCHOOSER_H

#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

class RandomChooser : public CPU
{
private:
    int move;

public:
    void generateMove();
    int getMove();
    void printCPUMove();
};

#endif /* RANDOMCHOOSER_H */
