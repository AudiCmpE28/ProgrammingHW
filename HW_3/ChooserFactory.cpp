#include <iostream>

#include "headers/ChooserFactory.h"
#include "headers/Chooser.h"
#include "headers/RandomChooser.h"
#include "headers/SmartChooser.h"
#include "headers/GeniusChooser.h"

using std::cout;
using std::rand;
using std::string;

Chooser *ChooserFactory::make_chooser(int which)
{
    if (which == Random)
        return new RandomChooser();
    else if (which == Smart)
        return new SmartChooser();
    else if (which == Genius)
        return new GeniusChooser();
};
