#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "headers/SmartCPU.h"
#include "headers/Chooser.h"
#include "headers/RandomCPU.h"

using std::cout;
using std::string;
using std::stringstream;
using std::to_string;

int randomChoice()
{
    int randMove = rand() % 3 + 1; //1-3 Rock, Paper, Scissors
    return randMove;
}

SmartCPU::SmartCPU()
{
    recentIndex = 0;
    arrCount = 0;
    for (int i = 0; i < 243; i++)
    {
        dataCount[i] = 0; // set all count to 0
        MLdata[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        recent5[i] = 0;
    }
    readData();
}

int SmartCPU::make_choice(int playerChoice)
{
    int CPUChoice = -1;
    if (recentIndex <= 2)
    { // while there's less than 3 moves inside of the recent5
        // CPUChoice = randomChoice();
        CPUChoice = 2; // forced input for testing
    }
    else
    {
        int counterPlayer[3] = {0, 0, 0}; // 0 = Rock, 1 = Paper, 2 = Scissors in this array
        int highestOccuranceIndex = 0;
        string recent = "";
        for (int i = 0; i < recentIndex; i++)
        {
            recent += to_string(recent5[i]);
        }
        string temp = "";
        for (int i = 1; i < 4; i++)
        {
            temp = recent + to_string(i);
            stringstream num(temp);
            num >> counterPlayer[i - 1];
        }
        for (int i = 0; i < 3; i++) // set the occurance of the player's next move
        {
            if (searchArray(counterPlayer[i]) >= 0)
            {
                int temp = searchArray(counterPlayer[i]);
                counterPlayer[i] = dataCount[temp];
            }
            else
                counterPlayer[i] = 0;
        }

        if (counterPlayer[1] > counterPlayer[0])
            highestOccuranceIndex = 1;
        else if (counterPlayer[2] > counterPlayer[0])
            highestOccuranceIndex = 2;

        if (highestOccuranceIndex == 0) // if player usually goes rock
        {
            if (counterPlayer[0] == counterPlayer[1]) // if there's no highest
            {
                CPUChoice = randomChoice(); // random move
                cout << "Random Move played\n";
            }
            else
                CPUChoice = 2; // counter with paper
        }
        else if (highestOccuranceIndex == 1) // if player usually goes Paper
            CPUChoice = 3;                   // Counter with scissors
        else                                 // if player usually goes scissors
            CPUChoice = 1;                   // Counter with rock
    }
    insertRecent(playerChoice, CPUChoice);
    if (CPUChoice < 0)
    {
        cout << "THERE HAS BEEN AN ERROR WITH PROGRAM CHOICE, RESETTING TO ROCK";
        CPUChoice = 1;
    }
    return CPUChoice;
}

void SmartCPU::insertRecent(int playerMove, int CPUChoice)
{
    if (recentIndex < 3) // if there's less than 4 elements in the recent 5
    {
        recent5[recentIndex] = playerMove;
        recentIndex++;
        recent5[recentIndex] = CPUChoice;
        recentIndex++;
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
    if (!fileData.is_open()) //if it cannot open thats bad
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

int SmartCPU::searchArray(int search)
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
