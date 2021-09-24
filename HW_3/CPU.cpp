#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "headers/CPU.h"

using std::cout;
using std::string;

CPU::CPU()
{
    this->move = 0;
    srand(time(NULL)); // seed the rand function
};
