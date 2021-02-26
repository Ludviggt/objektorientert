#include "std_lib_facilities.h"
#pragma once 

struct Temps{

    double max,min;
};
    
istream& operator>>(istream& is, Temps& t);
vector<Temps> readTemps(string filename);
void tempStats(vector<Temps> t);
