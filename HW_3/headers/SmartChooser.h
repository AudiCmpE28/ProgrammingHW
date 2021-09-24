#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

#ifndef SMARTCHOOSER_H
#define SMARTCHOOSER_H

class SmartChooser: public CPU
{
private:
    int move;

public:
    void generateMove();
    int getMove();
    void printCPUMove();
};

#endif /* SMARTCHOOSER_H */
