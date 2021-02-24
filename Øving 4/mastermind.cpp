#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"
#include "masterVisual.h"

void playMastermind(){
    //Bruker constexpr for å initialisere en konstant verdi som ikke skal endres, kjøres ved kompilering, const kjøres ved run time
    //som vil si at vi kan angi en verdi ved constexpr konstant utenfor main, der koden kjøres
    
    constexpr int size = 4;
    constexpr int letters = 6;
    string code; // koden som skal gjettes
    string guess; //Koden som er gjettet
    int runde = 1;
    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    code = randomizeString(size, 'A' + letters -1, 'A'); // fyller opp koden med randomiserte bokstaver
    //cout << code << endl;
    cout << "DU har 6 forsok i spillet, fyll inn gjetning i tekstboksen" << endl;
    addGuess(mwin, code, size, 'A', runde);
    int antallforsok = 0; // variabel for antall forsøk
    hideCode(mwin, size);
    while(antallforsok<6){
        ++runde;
        //guess = readInputToString('A' + letters -1, 'A', size); // Leser inn et gjetteforsøk 
        guess = mwin.getInput(size, 'A', 'A' + letters -1);
        cout << guess <<endl;
        addGuess(mwin, guess, size, 'A', runde);
        
        int riktige =  checkCharactersAndPosition(code, guess); // Antall som er riktig plassert
    
        int riktigeChars = checkCharacters(code,  guess); // Antall rikitge tegn uavh av plassering

        addFeedback(mwin, riktige, riktigeChars, size,runde);
        mwin.redraw();
        
        if (riktige == size){
            cout <<"Gratulerer du vant spillet innen antall forsok var brukt opp!"<< endl;
            break;
        }
        cout <<"Ikke riktig"<< endl;
        cout <<"Men du har totalt: " << riktigeChars <<" tegn riktige, og av dem er: "<< riktige <<" plassert riktig, try again!" << endl;
        ++antallforsok;
        
    }

}
int checkCharactersAndPosition(string code, string guess){

    int riktige = 0;
    for ( unsigned int i =0 ; i < size(code); ++i ){
        if (code[i] == guess [i]){
            ++riktige;
        }
    }
return riktige;
}

int checkCharacters(string code, string guess){
    int riktigeChars = 0;
    for(unsigned int i = 0; i < size(code) ; ++i){
        for(unsigned int j = 0; j < size(code); ++j){
            if(code[i] == guess[j]){
                guess[j] = '0';
                ++riktigeChars; 
                break; 
            }
        }
    }
return riktigeChars;
}