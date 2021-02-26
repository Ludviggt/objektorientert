#include "std_lib_facilities.h"
#include "temps.h"

istream& operator>>(istream& is, Temps& t){
   return is >> t.max >> t.min;
}


vector<Temps> readTemps(string filename){
    ifstream inputFile{filename};
    if(!inputFile){
        error("Cannot open file");//sjekker at filen ble åpnet
    }
    vector<Temps> temps;
    for(Temps i; inputFile >> i;)
        temps.push_back(i);
    

return temps;
}

void tempStats(vector<Temps> t){
    double max = 0.0;
    int dagmax,dagmin;
    double min =0.0;
    
    for(int i=0; i<t.size();++i){
        if(t[i].max > max){
            max = t[i].max;
            dagmax = i+1;
        }
        if(t[i].min < min){
            min = t[i].min;
            dagmin = i+1;
        }   
    }
    cout << "The highest registered temperature was: "<< max <<'\n' << "and occured on the: "
    << dagmax <<" day of the year." << endl;
    cout << "The lowest regitered temperature was: "<< min <<'\n' << "and occured on the: "
    << dagmin <<" day of the year." << endl;

}