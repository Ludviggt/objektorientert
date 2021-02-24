#include "std_lib_facilities.h"
#include<iostream> 
#include<vector> 
using namespace std;
#pragma once
constexpr double pi = 3.14159265;
constexpr int lowerLimit = 10;

constexpr int Upperlimit = 1000;
double acclY();
double velY(double initVelocityY, double time);
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);
void printTime(double seconds);
double flightTime(double initVelocityY);
void testDeviation(double compareOperand, double toOperand, double maxError, string name);

double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double thetaRad, double absV);
double getVelocityY(double thetaRad, double absV);
double getDistanceTraveled(double velocityX, double velocityY);

vector<double> getVelocityVector(double thetaRad, double absV);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);
int randomWithLimits(int lowerLimit, int Upperlimit); 
void playTargetPractice();

