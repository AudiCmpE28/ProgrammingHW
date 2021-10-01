#include <iostream>
#include <fstream>

#include "headers/SmartCPU.h"
#include "headers/Chooser.h"
#include "headers/RandomCPU.h"

using std::cout;

SmartCPU::SmartCPU()
{
    recentIndex = 0;
    arrCount = 0;
    for (int i = 0; i < PERMUTATION; i++)
    {
        dataCount[i] = 0; // set all count to 0
        MLdata[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        recent5[i] = 0;
    }
}

int SmartCPU::make_choice(int playerChoice)
{
    if (recentIndex <= 2)
    { // while there's less than 3 moves inside of the recent5
        int CPUChoice = RandomCPU::make_choice(0);
        insertRecent(playerChoice, CPUChoice);
    }
    else
    {
        // convert the recent5 array into an actual integer, but then add option 1, 2 and 3
        // If the recent 5 contains 1132
        // rock = recent"4 elements" + 1 = 11321
        // paper = recent"4 elements" + 2 = 11322
        // scissors = recent"4 elements" + 3 = 11323
        // string number += recent5 [1-4]

        // 3 temp integers to keep track of the count r = p = s then chuck random
        // if not: swing the winning move
    }
}

void SmartCPU::insertRecent(int playerMove, int CPUChoice)
{
    if (recentIndex < 3) // if there's less than 4 elements in the recent 5
    {
        recent5[recentIndex++] = playerMove;
        recent5[recentIndex++] = CPUChoice;
    }
    else // if there's exactly 4 element [2] [3] [New 2] [New 3] [4]
    {    //shift then add
        recent5[0] = recent5[2];
        recent5[1] = recent5[3];
        recent5[2] = playerMove;
        recent5[3] = CPUChoice;
    }
}

void SmartCPU::readData()
{
    int number;
    int indexFound = -1;
    std::ifstream fileData("Choices.txt");
    if (!choicefile.is_open()) //if it cannot open thats bad
    {
        cout << "ERROR: could not open file for SmartCPU";
    }
    else
    {
        while (fileData >> number)
        {
            indexFound = searchArray(number);
            if (indexFound >= 0)
            {
                dataCount[indexFound]++;
                indexFound = -1;
            }
            else
            {
                MLdata[arrCount] = number;
                dataCount[arrCount]++;
                arrCount++;
            }
        }

        fileData.close();
    }
}

int searchArray(int search)
{
    int index = -1;
    for (int i = 0; i < arrCount; i++)
    {
        if (MLdata[i] == search)
        {
            index = i;
            break;
        }
    }
    return index;
}