#include "CPU.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;

#ifndef RANDOMCPU_H
#define RANDOMCPU_H

class RandomCPU: public CPU
{
private:
    int move;

public:
    void generateMove();
};

#endif /* RANDOMCPU_H */
