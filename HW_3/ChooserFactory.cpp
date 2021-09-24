#include "headers/ChooserFactory.h"

CPU *ChooserFactory::makeChooser(brainPower bp)
{
    if (bp == r)
        return new RandomCPU();
    else if (bp == s)
        return new SmartCPU();
    else if (bp == g)
        return new GeniusCPU();
    else
        return nullptr;
}
