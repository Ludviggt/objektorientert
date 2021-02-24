#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }

}

void swapValue(int& from, int& to){
    int temp = from;
    from = to;
    to = temp; 

}

void printStudent(Student lab){
    
    
    cout << setw(size("Name:  ")) << "Name:  "<< setw(5) << "Age:  " << setw(size("Stydyprogram")+1) << "Studyprogram: "<< endl;
    cout << setw(size(lab.name)) << lab.name << setw(size("Age:  ")-2)<< lab.age << setw(size("Stydyprogram")) << lab. Studyprogram << endl;
    
    
}

string isInProgram(Student lab, string s){
    string retur = "";
    if (lab.Studyprogram == s){
        retur = "The studyprogram equals the one the students attends";

    }
    else {
        retur = "wrong studyprogram";
    }
    return retur;
}

string randomizeString(int numberOfChars, int upper, int lower){
    string s;
    
    int range = upper - lower; 
    for (int i{0}; i < numberOfChars; ++i){
        char randomNumber = (rand() % range) + lower; 
        s.push_back(toupper(randomNumber));

        
    }
    return s;
}
string readInputToString(int upper, int lower, int lengthN){
    int counter = 0;
    char letter;
    string s;
    while ( counter < lengthN){
        cout << "Skriv inn et tegn du vil ha i strengen: ";
        cin >> letter;
        if(toupper(letter) >= lower && toupper(letter) <= upper){
            cout << "Godkjent input\n";
            s.push_back(toupper(letter));
            ++counter; 
        }
        else{
        cout <<"ikke godkjent input\n";
        }
    }
    return s;
}
int countChar(string streng, char tegnSjekkesMot){
    int forekomster = 0;
    for ( unsigned int i{0}; i <size(streng); ++i){

        if (streng[i] == tegnSjekkesMot){
            ++forekomster;
        }
    }
    return forekomster;
}