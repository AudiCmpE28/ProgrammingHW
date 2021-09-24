#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

#ifndef GENIUSCPU_H
#define GENIUSCPU_H

class GeniusCPU: public CPU
{
private:
    int move;

public:
    void generateMove();
};

#endif /* GENIUSCPU_H */
