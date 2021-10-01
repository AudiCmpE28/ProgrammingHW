#include "headers/SmartCPU.h"
#include "headers/Chooser.h"
#include <algorithm> //for std::unique, std::distance

int SmartCPU::make_choice()
{
    if (!data_analyzed)
    {
        analizeData();
        data_analyzed = true;
    }
    int user_expected_move = user_game_pattern();
    // for (int i = 0; i < choicesvector.size(); i++)  //debug purpose
    // {
    //     cout << "NUM: " << choicesvector[i][0] << " Freq: " << choicesvector[i][1] << endl;
    // }

    if (user_expected_move == 1)
    {
        cout << "CPU: 1 \n";
    }
    else if (user_expected_move == 2)
    {
        cout << "CPU: 2 \n";
    }
    else
    { //user_expected_move == 3
        cout << "CPU: 3 \n";
    }

    return (rand() % 3 + 1); //1-3 Rock, Paper, Scissors
}

int SmartCPU::user_game_pattern()
{
    vector<int> testing;
    testing.push_back(11212);
    int freq1 = 0, freq2 = 0, freq3 = 0;
    // for (int i = 0; i < choicesvector.size(); i++) //debug purpose
    // {
    //     if ((testing[1] / 10000 % 10) == (choicesvector[i][0] / 10000 % 10))
    //     {
    //         if ((testing[1] / 1000 % 10) == (choicesvector[i][0] / 1000 % 10))
    //         {
    //             if ((testing[1] / 100 % 10) == (choicesvector[i][0] / 100 % 10))
    //             {
    //                 if ((testing[1] / 10 % 10) == (choicesvector[i][0] / 10 % 10))
    //                 {
    //                     if (choicesvector[i][0] % 10 == 1)
    //                     {
    //                         freq1 = choicesvector[i][1];
    //                     }
    //                     if (choicesvector[i][0] % 10 == 2)
    //                     {
    //                         freq2 = choicesvector[i][1];
    //                     }
    //                     if (choicesvector[i][0] % 10 == 3)
    //                     {
    //                         freq3 = choicesvector[i][1];
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    if (freq3 > freq2 && freq3 > freq1)
    {
        return 3;
    }
    else if (freq2 > freq3 && freq2 > freq1)
    {
        return 2;
    }
    return 1;
}

/*reads txt file to collect data*/
void SmartCPU::analizeData()
{
    vector<string> temp;   //grabs text file data
    vector<int> frequency; //will count frequency with its data
    int tracker = 1;       // all data is there once
    string line;           //used to grab each line in text file
    bool duplicate = false;

    std::ifstream choicefile("Choices.txt");
    if (!choicefile.is_open()) //if it cannot open thats bad
    {
        cout << "ERROR: could not open file for SmartCPU";
    }
    else
    {
        while (std::getline(choicefile, line))
        {
            // std::cout << "Element found: " << line << endl;  //debug purpose
            temp.push_back(line);
        }

        choicefile.close();
    }

    int i = 0;
    //will collect frequency by traversing through vector
    for (auto it1 = temp.begin(); it1 != temp.end(); it1++)
    {
        frequency.push_back(std::stoi(*it1));
        /*for loop counts frequency*/
        for (auto it2 = it1 + 1; it2 != temp.end(); it2++)
        {
            if (*it1 == *it2)
            {
                tracker++;
            }
        }
        frequency.push_back(tracker);

        duplicate = duplicate_frequency(std::stoi(*it1));
        if (!duplicate)
        {
            choicesvector.push_back(frequency);
        }

        /*resets all values and vector */
        duplicate = false;
        tracker = 1;
        frequency.clear();
    }
    /*removes duplicates in 2D vector*/
    // choicesvector.erase(std::unique(choicesvector.begin(), choicesvector.end()), choicesvector.end());  //debug purpose
}

bool SmartCPU::duplicate_frequency(int val)
{
    for (int i = 0; i < choicesvector.size(); i++)
    {
        if (choicesvector[i][0] == val)
        {
            return true;
        }
    }
    return false;
}