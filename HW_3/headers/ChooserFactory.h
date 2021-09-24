#include "SmartCPU.h"
#include "GeniusCPU.h"
#include "RandomCPU.h"
#include "CPU.h"

#ifndef CHOOSERFACTORY_H
#define CHOOSERFACTORY_H

#include "CPU.h"

enum brainPower
{
    r = 1,
    s = 2,
    g = 3
};

class ChooserFactory 
{
public:
    CPU *makeChooser(brainPower);
};

#endif /* CHOOSERFACTORY_H */
