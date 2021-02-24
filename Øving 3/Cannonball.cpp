#include "Cannonball.h"
#include "std_lib_facilities.h"
#define _USE_MATH_DEFINES 
 
#include <cmath>
#include <iostream>
using namespace std;
#include<vector> 
#include "cannonball_viz.h"

double acclY(){
    double g = -9.81;
    return g;
}


double velY(double initVelocityY, double time){

    double FartY = initVelocityY + acclY()*time;
    return FartY;
}


double posX(double initPosition, double initVelocity, double time){

    double PosisjonX = initPosition + initVelocity * time;
    return PosisjonX;
}

double posY(double initPosition, double initVelocity, double time){

    double PosisjonY = initPosition + initVelocity * time + (acclY() * pow(time,2))/2;
    return PosisjonY;
}

void printTime(double seconds){
    int hours = seconds/3600;
	int minutes = (static_cast<int> (seconds)%3600)/60;
	int s = seconds - hours*3600 - minutes*60;
    cout <<"Antallet sekunder tilsvarer "<< hours << " timer " << minutes << " minutter " << s << " sekunder " << "i klokketid\n";
}


double flightTime(double initVelocityY){

    double FlygeTid = -(2 * initVelocityY)/acclY();
    return FlygeTid; 

}
void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if (abs(compareOperand - toOperand) >= maxError ){
        cout << name << " De sammenlignede tallene fraviker mer en maks feil" << '\n';
    }
    else {
        cout << name << " Innafor" << '\n';
    }

}
double getUserInputTheta(){
    double theta = 0;
    cout << "Oppgi en startvinkel: ";
    cin >> theta;
    return theta; 
}

double getUserInputAbsVelocity(){
    double absV = 0;
    cout << "Oppgi en absoluttfart: ";
    cin >> absV;
    return absV;
}

double degToRad(double deg){
    
    double thetaRad = deg*pi/180;
    return thetaRad;
}

double getVelocityX(double thetaRad, double absV){

    double FartX = absV * cos(thetaRad);
    return FartX;
}

double getVelocityY(double thetaRad, double absV){
    double FartY = absV * sin(thetaRad);
    return FartY;
}
vector<double> getVelocityVector(double thetaRad, double absV) {
    vector<double> FartsVektor(2);
    FartsVektor[0] = getVelocityX(thetaRad, absV);
    FartsVektor[1] = getVelocityY(thetaRad, absV);
    return FartsVektor; 

}
double getDistanceTraveled(double FartX, double FartY){
    double time = flightTime(FartY);
    double DistanceTraveled = posX(0, FartX, time); 
    return DistanceTraveled;
}
double targetPractice(double distanceToTarget, double velocityX, double velocityY){

    double DistanceTraveled = getDistanceTraveled(velocityX, velocityY);
    double deviation = distanceToTarget - DistanceTraveled; 
    return deviation;
}

int randomWithLimits(int lowerLimit, int Upperlimit) {
    int range = Upperlimit - lowerLimit + 1;
    int randomNumber = (rand() % range) + lowerLimit; 
    return randomNumber; 
}

void playTargetPractice(){
    
    int distanceToTarget = randomWithLimits(lowerLimit, Upperlimit);
    for( int i = 1; i < 10; ++i){
        cout << distanceToTarget << '\n';
        double theta = getUserInputTheta();
        double thetaRad = degToRad(theta);
        double absV = getUserInputAbsVelocity();
        vector<double> Fart =  getVelocityVector(thetaRad, absV);
        double time = flightTime(Fart[1]);
        
        double deviation = targetPractice(distanceToTarget, Fart[0], Fart[1]);
        cannonBallViz(distanceToTarget, 1000, Fart[0], Fart[1],
				   7);
        if (deviation < -5){
            cout << "\n Du tapte spillet, kanonkulen gikk for langt og avstaden fra blinken er: " << abs(deviation) << " konnonkulen brukte: " << time << " fram til nedslagspunktet.\n";
        }
        else if(deviation > 5){
            cout << "\n Du tapte spillet, kanonkulen gikk for kort og avstaden fra blinken er: " << deviation << " konnonkulen brukte: " << time << " fram til nedslagspunktet.\n";

        }
        else if ( deviation < 0) {
            cout << "\n Gratulerer du vant spillet, kanonkulen gikk litt for langt og avstanden fra blinken er: " << abs(deviation) << " konnonkulen brukte: " << time << " fram til nedslagspunktet.\n";
        }
        else{
            cout << "\n Gratulerer du vant spillet, kanonkulen gikk for litt for kort og avstanden fra blinken er: " << deviation << " konnonkulen brukte: " << time << " fram til nedslagspunktet.\n";
        }



    }
    
}

