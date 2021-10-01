#include <iostream>
//#include "headers/Game.h"
//#include "headers/ChooserFactory.h"
#include <time.h>
// #include "headers/Player.h"
// #include "headers/CPU.h"

#include <random>
using std::cout;
using std::endl;
/*
int main()
{
    Game rockPaperScissors;
    rockPaperScissors.executeMatch();
    return 0;
} */
//----------------------HOW TO RUN in VS code------------------------
//Make sure you're in the HW3 directory in terminal then copy and paste:
//cd "$cwd" ; if ($?) { g++ Game.cpp main.cpp CPU.cpp Player.cpp RandomCPU.cpp printUI.cpp ChooserFactory.cpp SmartCPU.cpp GeniusCPU.cpp -o main } ; if ($?) { .\main }

// test main

#include <fstream>
#include <algorithm>
#include <iterator>

int main()
{
    int PERMUTATION = 243;
    int MLdata[PERMUTATION];
    int dataCount[PERMUTATION];
    for (int i = 0; i < PERMUTATION; i++)
    {
        MLdata[i] = 0;
        dataCount[i] = 0;
    }
    int number;
    int count = 0;
    int indexFound = -1;
    std::ifstream fileData("test.txt");
    if (!fileData.is_open()) //if it cannot open thats bad
    {
        cout << "ERROR: could not open file for SmartCPU";
    }
    else
    {
        while (fileData >> number)
        {
            for (int i = 0; i < PERMUTATION; i++)
            {
                if (MLdata[i] == number)
                {
                    indexFound = i;
                    break;
                }
            }
            if (indexFound >= 0)
            {
                dataCount[indexFound]++;
                indexFound = -1;
            }
            else
            {
                MLdata[count] = number;
                dataCount[count]++;
                count++;
            }
        }

        fileData.close();
    }

    cout << "MLdata index 1: " << MLdata[0] << "\n";
    cout << "MLdata count: " << dataCount[0] << "\n";
    cout << "MLdata index 2: " << MLdata[1] << "\n";
    cout << "MLdata count: " << dataCount[1] << "\n";
}