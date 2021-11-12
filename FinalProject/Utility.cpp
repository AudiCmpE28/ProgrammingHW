#include "headers/Utility.h"

using namespace std;
using namespace std::chrono;
/**
 * @brief Place before a function. Pass the returned time_point to endtimer function at the end.
 * 
 * @return time_point<system_clock> 
 */
time_point<system_clock> starttimer()
{
    auto start= high_resolution_clock::now();
    return start;
}

/**
 * @brief Takes the time_point object returned by starttimer. Outputs execution time.
 * 
 * @param start 
 */
void endtimer(time_point<system_clock> start)
{
    auto stop= high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"\nExecution time: "<<duration.count()<<" milliseconds\n"<<endl;
}
