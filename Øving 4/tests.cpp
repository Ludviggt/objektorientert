#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"
#include "masterVisual.h"
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations;

}

void testswapValue(){

    int a = 10;
    int b = 5;
    swapValue(a,b);
    cout << a << '\n';
    cout << b << '\n';
}

void testString(){
    
    string grades ="";
    grades = readInputToString(71,65, 10);
    
    for(char& c : grades){
        c = toupper(c);
    }

    vector<int> gradeCount;
    char karakter = 'A';
    
        
    for( int i = 0; i < 6; ++i){
            int forekomster = countChar(grades,karakter);
            gradeCount.push_back(forekomster);
            ++karakter;
            cout << forekomster<< endl;  
    }

    double sum = 5*gradeCount[0] + 4*gradeCount[1] + 3*gradeCount[2] + 2*gradeCount[3] + 1*gradeCount[4] + 0*gradeCount[5];
    double snitt = sum/10;
    cout << snitt << '\n';

}