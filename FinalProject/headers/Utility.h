#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#ifndef UTILITY_H_
#define UTILITY_H_
#pragma once


#define DEBUG 1

using namespace std;
using namespace std::chrono;
time_point<system_clock> starttimer();
void endtimer(time_point<system_clock> start);
#endif
