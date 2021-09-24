#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

#ifndef GENIUSCHOOSER_H
#define GENIUSCHOOSER_H

class GeniusChooser : public CPU
{
private:
    int move;

public:
    void generateMove();
    int getMove();
    void printCPUMove();
};

#endif /* GENIOUSCHOOSER_H */
