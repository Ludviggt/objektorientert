#include "std_lib_facilities.h"
#pragma once 
void skrivInnOrd();
void readFromFileWriteToFile();
void countInstancesAndFreq();
void testEmneKatalog(string inputfilename, string outputfilename);

class CourseCatalog{
    
    private:
    map<string,string> emneKodeToEmneNavn;

    public:
    void addCourse(string emneKode, string emneNavn);
    void removeCourse(string emneKode);
    string getCourse(string emneKode);
    friend ostream& operator<<(ostream& os, const CourseCatalog& cc);
    void saveData(const string& fileName);
    void writeToFile(const string& fileName);


};