//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "Cannonball.h"
#include "std_lib_facilities.h"
#include <math.h>
#define _USE_MATH_DEFINES 
 
#include <cmath>
#include <iostream>
int main(){
	

/*
	testDeviation(acclY(), g, maxError, "accelY()");
	testDeviation(velY(25.0, 2.5), 0.475, maxError, "velY(25.0, 2.5)");
	testDeviation(posX(0.0, 50.0, 2.5), 125.0, maxError, "posX(0.0, 50.0, 2.5)");
	testDeviation(posY(0.0, 25.0, 2.5), 31.84, maxError, "posY(0.0, 25.0, 2.5)");
	testDeviation(flightTime(30.0), 6.116, maxError, "flightTime(30.0)");
	cout << posY(0.0, 25.0, 2.5);


	double deg =  getUserInputTheta();
	double absV =  getUserInputAbsVelocity();
	double thetaRad = degToRad(deg);

	double initVelocityX = getVelocityX(thetaRad, absV);
	double initVelocityY = getVelocityY(thetaRad, absV);

	double time =  flightTime( initVelocityY);
	cout << '\n' <<  targetPractice( 100, initVelocityX, initVelocityY) <<'\n';
*/
	srand(static_cast<unsigned int>(time(nullptr)));
	
	/*
	for(int i = 1; i < 5; ++i ) {
		int randomNumber = randomWithLimits( lowerLimit, Upperlimit);
		cout <<'\n' << randomNumber << '\n';
	}
	*/

	playTargetPractice();
	keep_window_open();
}

//------------------------------------------------------------------------------
