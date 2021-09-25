#ifndef RANDOMCPU_H
#define RANDOMCPU_H

#include "Chooser.h"

class RandomCPU : public Chooser
{
public:
    int make_choice();
};

#endif /* RANDOMCPU_H */