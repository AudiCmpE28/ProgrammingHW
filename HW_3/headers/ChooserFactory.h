#ifndef CHOOSERFACTORY_H
#define CHOOSERFACTORY_H

#include "CPU.h"

enum brainPower
{
    random = 1,
    smart = 2,
    genius = 3
};

class ChooserFactory
{
public:
    static CPU *makeChooser(brainPower bp);
};

#endif /* CHOOSERFACTORY_H */
