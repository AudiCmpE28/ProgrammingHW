#include "headers/ChooserFactory.h"
#include "headers/Chooser.h"
#include "headers/RandomCPU.h"
#include "headers/SmartCPU.h"
#include "headers/GeniusCPU.h"

Chooser *ChooserFactory::make_chooser(int choice)
{
    if (choice == random)
        return new RandomCPU();
    else if (choice == smart)
        return new SmartCPU();
    else if (choice == genius)
        return new GeniusCPU();
    else
        return nullptr;
}
