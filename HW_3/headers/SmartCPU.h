#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

#ifndef SMARTCPU_H
#define SMARTCPU_H

class SmartCPU: public CPU
{
private:
    int move;

public:
    void generateMove();
};

#endif /* SMARTCPU_H */
