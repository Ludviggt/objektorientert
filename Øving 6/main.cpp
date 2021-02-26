

#include "std_lib_facilities.h"
#include "fileHandling.h"
#include "temps.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

int main()
{
//countInstancesAndFreq();
//testEmneKatalog("inputFile.txt", "outputFile.txt");
vector<Temps> t;
t = readTemps("temperatures.txt");
tempStats(t);

keep_window_open();
}






//------------------------------------------------------------------------------
