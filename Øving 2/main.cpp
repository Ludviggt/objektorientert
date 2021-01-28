//

// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include <iostream>
#include <iomanip>
#include<cmath>
# include "Graph.h"
# include "Simple_window.h"

//------------------------------------------------------------------------------'


void inputAndPrintInteger(){
	int x = 0;
	cout <<"Skriv inn ett tall: ";
	cin >> x;
	cout << "Du skrev: " << x << '\n';

}

int inputInteger(){
	cout << "Skriv inn ett tall: ";
	int y = 0;
	cin >> y; 
	return y;

}

void inputIntegersAndPrintSum(){
	int a = 0;
	int b = 0;
	a = inputInteger();
	b = inputInteger();
	cout << "Summen av tallene er : " << a + b << '\n'; 

}

bool isOdd(int number){
	
	bool sjekk = true;
	if (number%2 != 0){
		sjekk = true;
	} else{
		sjekk = false;
	}
	return sjekk; 
}

void printHumanReadableTime(int s){
	int hours = s/3600;
	int minutes = (s%3600)/60;
	int seconds = s - hours*3600 - minutes*60;
	cout <<"Antallet sekunder tilsvarer "<< hours << " timer " << minutes << " minutter " << seconds << " sekunder " << "i klokketid\n";
}

void SummenOfChoosenNumbers(){
	int NrTall = 0;
	cout << "Hvor mange tall vil du summere? ";
	cin >> NrTall; 
	int sum = 0;
	for (int i = 0; i < NrTall; i++){
		cout << "Skriv inn tall: ";
		int tall = 0;
		cin >> tall;
		sum = sum + tall; 
	}
	cout << "Summen av tallene er: " << sum << '\n';
}

void SummenOfChoosenNumbers2(){
	int tall = 2;
	int sum = 0;
	while( tall != 0){
		cout << "Skriv inn ett tall eller avbryt med 0: ";
		cin >> tall;
		sum = sum + tall;

	}
	cout << "Summen av tallene er: " << sum << '\n';
}

double inputDouble(){
	cout << "Skriv inn ett tall: ";
	double y = 0;
	cin >> y; 
	return y;

}

void NOKtoEU(){
	double NOK = inputDouble();
	double vekslingskurs = 9.75;
	if (NOK < 0){
		cout << "Tallet du skrev inn var negativt\n";
		NOK = inputDouble();
	}
	double EU = NOK/vekslingskurs; 
	cout << fixed << setprecision(2) << NOK <<" kr tilsvarer " << EU << " euro." << '\n';
}

void EgenKomponertGangeTabell(){

	int bredde = 0;
	int hoyde = 0;
	cout << "Velg tabellbredde: ";
	cin >> bredde;
	cout << "Velg tabellhoyde: ";
	cin >> hoyde;
	for (int i = 1; i <= hoyde; ++i){
		for (int j = 1; j <= bredde; ++j ){
			if (bredde * hoyde < 99){
					int verdi = i*j;
					cout << setw(3) << verdi;
			} 
				else if (bredde * hoyde > 99) {
					int verdi = i*j;
					cout << setw(4) << verdi;
					}
			cout << endl;


		}
	}
}

double discriminant(double a, double b, double c) {

	double discr = pow(b,2) - 4*a*c;
	return discr;

}

void printRealRoots(double a, double b, double c){
	double x_1 = 0;
	double x_2 = 0;
	if (discriminant( a, b, c) > 0) {
		x_1  = (-b + sqrt(discriminant( a, b, c)))/(2*a);
		x_2 = (-b - sqrt(discriminant( a, b, c)))/(2*a);
		cout << "x_1 = " << x_1 << '\n';
		cout << "x_2 = " << x_2 << '\n';
	}
	else if (discriminant( a, b, c) == 0 ){
		x_1 = (-b)/(2*a);
		cout << x_1 << '\n';
	}
	else{
		cout << "Ingen relle losninger\n";
	}
}
	
void solveQuadraticEquation(){

	double a = 0;
	double b = 0;
	double c = 0;
	cout << "Skriv inn en verdi for a: ";
	cin >> a;
	cout << "Skriv inn en verdi for b: ";
	cin >> b;
	cout << "Skriv inn en verdi for c: ";
	cin >> c;
	printRealRoots(a,b,c);
}
void pythagoras(int a, int b){
	
	using namespace Graph_lib;
	
	
	int x1 = 550, x2 = x1, x3 = x1 + a; // koord for trianglet 
	int x4 = x3 + a, x5 = x1 + b; // koord for høyre kvadrat
	int y1 = 300, y2 = y1 + b, y3 = y2; // koord for trianglet
	int y4 = y3 - a, y5 = y1 - a; // koord for høyre kvadrat
	int x6 = x1 -b, x7 = x2 - b; // koord for venstre kvadrat
	int y6 = y1, y7 = y2; // koord for venstre kvadrat
	int x8 = x2, x9 = x3; // koord for nedre kvadrat
	int y8 = y2 + a, y9 = y8;  // koord for nedre kvadrat
	Simple_window win{Point{100,100}, 1200, 800, "Pyhtagoras"};
	
	Polygon rightTriangle;
	rightTriangle.add(Point{x1, y1});
	rightTriangle.add(Point{x2, y2});
	rightTriangle.add(Point{x3, y3});
	rightTriangle.set_fill_color(Color::black);

	Polygon rightSquare;
	rightSquare.add(Point{x1, y1});
	rightSquare.add(Point{x3, y3});
	rightSquare.add(Point{x4, y4});
	rightSquare.add(Point{x5, y5});
	rightSquare.set_fill_color(Color::blue);
	
	Polygon leftSquare;
	leftSquare.add(Point{x1, y1});
	leftSquare.add(Point{x2, y2});
	leftSquare.add(Point{x7, y7});
	leftSquare.add(Point{x6, y6});
	leftSquare.set_fill_color(Color::green);

	Polygon lowerSquare;
	lowerSquare.add(Point{x2, y2});
	lowerSquare.add(Point{x3, y3});
	lowerSquare.add(Point{x9, y9});
	lowerSquare.add(Point{x8, y8});
	lowerSquare.set_fill_color(Color::red);

	win.attach(rightTriangle);
	win.attach(leftSquare);
	win.attach(rightSquare);
	win.attach(lowerSquare);
	win.wait_for_button();
	

}

 vector<int> calculateBalance(int nowSaldo, int rente, int years){
	 vector<int> saldoer;
	 
	 for (int i = 0; i< years + 1; ++i ){

		double endring = pow(1 + (static_cast<double>(rente)/100),i);
		saldoer.push_back(nowSaldo*endring);
	 	
	 }
	 return saldoer; 
 }
void printBalance(vector<int> saldoer){
	cout << setw(7) << "Ar:"<< setw(7) << "Saldo:" << endl;
	for (int i = 0; i < saldoer.size(); ++i){
		cout << setw(7) << i << setw(7) << saldoer[i] << endl;


	}
	
}
	/*
	int NOK = 0;
	double vekslingskurs = 9.75;
	cout << "Skriv inn ett antall NOK: ";
	cin >> NOK;
	if (NOK<0){
		cout << "Antall NOK var negativt, skriv et positivt antall: " << '\n';
		cin >> NOK;
	}
	double EU = NOK/vekslingskurs; 
	cout << fixed << setprecision(2) << NOK << " kr tilsvarer " << EU << " euro" << '\n';
	*/


// C++ programs start by executing the function main
int main() {
/*
cout << "Dette er oppgave 1a\n";
inputAndPrintInteger();
keep_window_open();

cout << "Dette er oppgave 1b\n";
int number = inputInteger();
cout << "Du skrev: " << number << '\n';

cout << "Dette er oppgave 1c\n";
inputIntegersAndPrintSum();
// Teori 1d: Jeg valgte å bruke InputInteger fordi denne funksjonen returnerer en verdi, inputAndPrintInteger skriver kun ut til skjerm, 
//derfor kan en ikke lagre verdien som skrives inn

cout << "Dette er oppgave 1e, sjekker tall fra 0 til 15\n";
	vector<int> v;
	for ( int i = 0; i <= 15; ++i){

		v.push_back(isOdd(i));
		cout << v[i] << " " << i << '\n';
	}

cout << "Dette er oppgave 1f\n";
printHumanReadableTime(5450);

cout << "Dette er oppgave 2a\n";
SummenOfChoosenNumbers();

cout << "Dette er oppgave 2b\n";
SummenOfChoosenNumbers2();

// teori oppgave 2c: det er best å bruke for-løkke i a) siden da er antallet tall som skal summeres forutbestemt
// While-løkke er best når brukeren ikke vet hvor mange tall som skal summeres, og dermed kan avbryte underveis
cout << "Dette er oppgave 2d\n";
cout << inputDouble() << '\n';

cout << "Dette er oppgave 2e\n";
NOKtoEU();
//Teori oppgave 2f: jeg velger å bruke inputdouble fordi da slipper jeg å caste fra integer til double i funskjonen
//Jeg laget en void-funskjon da den kun skulle skrive ut til skjerm, ikke returnere en verdi

int valg = 10;

	while(valg !=0){
	cout << "0) Avslutt\n";
	cout << "1) Summer to tall\n";
	cout << "2) Summer flere tall\n";
	cout << "3) Konverter NOK til EURO.\n";
	cout << "4) Los en andregradsligning med selvvalgte verdier for a,b og c.\n";
	cout << "Angi valg (0-4): "; 
	cin >> valg;
		switch (valg){

			case 1:
				inputIntegersAndPrintSum();
				break;
			case 2:
				SummenOfChoosenNumbers2();
				break;
			case 3:
				NOKtoEU();
				break;
			case 4:
				solveQuadraticEquation();
				break;
			default:
				cout << "Thank you, come again!\n";
		}
	}



EgenKomponertGangeTabell();


cout << discriminant(5,2,2);

printRealRoots(5, 2, 2);


solveQuadraticEquation();

pythagoras(100, 100);

vector<int> v = calculateBalance(10000,5,2);
for (int i=0; i< v.size();++i){
	cout << v[i] << " in year: " << i << '\n';
}
*/
vector<int> saldoer = calculateBalance(10000,5,10);
printBalance(saldoer); 
keep_window_open();
}

//------------------------------------------------------------------------------
