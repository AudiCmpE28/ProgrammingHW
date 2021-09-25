#ifndef CHOOSERFACTORY_H
#define CHOOSERFACTORY_H

#include "SmartCPU.h"
#include "GeniusCPU.h"
#include "RandomCPU.h"
#include "CPU.h"

enum cpuMode
{
    random = 1,
    smart = 2,
    genius = 3
};

class ChooserFactory
{
public:
    static Chooser *make_chooser(int choice);
};

#endif /* CHOOSERFACTORY_H */
