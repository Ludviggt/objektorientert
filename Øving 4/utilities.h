
#include "std_lib_facilities.h"
//constexpr char lower = 65; // plassen til A i ascii
//constexpr char upper = 71; // // plassen til F i ascii
struct Student {
    string name;
    int age;
    string Studyprogram;
    
};
int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapValue(int& from, int& to);
void printStudent(Student lab);
string isInProgram(Student lab, string s);
string randomizeString(int numberOfChars, int upper, int lower);
string readInputToString(int upper, int lower, int lengthN);
int countChar(string streng, char tegnSjekkes);
