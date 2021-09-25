#ifndef CHOOSERFACTORY_H
#define CHOOSERFACTORY_H
#include "Chooser.h"

enum choice
{
    Random = 1,
    Smart,
    Genius
};

class ChooserFactory
{
public:
    static Chooser *make_chooser(int which);
};

#endif /* CHOOSERFACTORY_H */