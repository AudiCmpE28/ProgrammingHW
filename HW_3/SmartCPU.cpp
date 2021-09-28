#include "headers/SmartCPU.h"
#include "headers/Chooser.h"
#include <iostream>
#include <fstream>

using std::cout;using std::endl;
using std::ofstream;

int SmartCPU::make_choice()
{
    int move = 1; // to do later.
    ofstream choicefile;
    choicefile.open("Choices.txt", std::ios_base::app);
    if(choicefile.is_open())
    {

    }
    
    choicefile.close();
    return move;
}