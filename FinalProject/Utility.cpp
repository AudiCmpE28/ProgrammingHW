#include "headers/Utility.h"

using namespace std::chrono;

time_point<system_clock> starttimer()
{
    auto start= high_resolution_clock::now();
    return start;
}
void endtimer(time_point<system_clock> start)
{
    auto stop= high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"\nExecution time: "<<duration.count()<<" milliseconds\n"<<endl;
}
