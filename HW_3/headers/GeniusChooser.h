#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

#ifndef GENIOUSCHOOSER_H
#define GENIOUSCHOOSER_H

class GeniousChooser: public CPU
{
private:
    int move;

public:
    void generateMove();
    int getMove();
    void printCPUMove();
};

#endif /* GENIOUSCHOOSER_H */
