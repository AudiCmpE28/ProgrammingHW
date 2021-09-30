#ifndef SMARTCPU_H
#define SMARTCPU_H

#include "Chooser.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::ofstream;

#include <vector>
#include <string>

using std::string;
using std::vector;

class SmartCPU : public Chooser
{
private:
    vector<vector<int>> choicesvector;
    bool data_analyzed = false;

public:
    int make_choice();
    int user_game_pattern();
    void analizeData();
    bool duplicate_frequency(int val);
};

#endif /* SMARTCPU_H */