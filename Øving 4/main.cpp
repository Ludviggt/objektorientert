//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include "masterVisual.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{

srand(static_cast<unsigned int>(time(nullptr)));
Student mee{"Ludvig",24,"MTBYGG"};
int valg = 100;

	while(valg !=0){
	cout << '\n' << "0) Avslutt\n";
	cout << "1) TestCallByValue\n";
	cout << "2) TestCallByReference\n";
	cout << "3) TestswapValue\n";
	cout << "4) Printstudent\n";
	cout << "5) Check of studyprogram\n";
	cout << "6) RandomizeString\n";
	cout << "7) testString random grades\n";
	cout << "8) Les input til streng\n";
	cout << "9) Tell forekomster av krakterer i en streng\n";
	cout << "10) Spill mastermind\n";
	cout << "Angi valg (0-10): "; 
	cin >> valg;
		switch (valg){

			case 1:
				testCallByValue();
				break;
			case 2:
				testCallByReference();
				break;
			case 3:
				testswapValue();
				break;
			case 4:
				printStudent(mee);
				break;
			case 5:
				cout << isInProgram(mee, "MvBYGG");
				break;
			case 6:
				cout << randomizeString(11, 10, 5);
				break;
			case 7:
				testString();
				break;
			case 8:
				cout << readInputToString(71, 65, 10) <<endl ;
				break;
			case 9:
				cout << countChar("hallasdjfiudfgbudfbgyufdsgyudfngerybguzsf", 'f') <<endl ;
				break;
			case 10:
				playMastermind();
				break;
			default:
				cout << "Thank you, come again!\n";
		}
	}

	keep_window_open();
}

//------------------------------------------------------------------------------
