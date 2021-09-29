#include "headers/SmartCPU.h"
#include "headers/Chooser.h"
#include <iostream>
#include <fstream>
#include <vector>
using std::cout;using std::endl;
using std::ofstream;
using std::vector;
using std::string;
int SmartCPU::make_choice()
{
    vector<vector<string>> choicesvector;
    int move = 1; // to do later.
    ofstream choicefile;
    choicefile.open("Choices.txt", std::ios_base::app);
    if(choicefile.is_open())
    {
        
    }
    
    choicefile.close();
    return move;
}