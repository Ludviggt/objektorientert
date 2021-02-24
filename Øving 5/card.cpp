
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

string suitToString(Suit suit){
    return suitStrings.at(suit);
}

string rankToString(Rank rank){
    return rankStrings.at(rank);
}

//Teori: enklere å lese koden når en bruker symboler, da dette er mer beskrivende enn heltall 

Card::Card(Suit suit, Rank rank) : s{suit}, r{rank}
{  }

Suit Card::getSuit(){
    
    
    return s;
}
Rank Card::getRank(){

    
    return r;
}

string Card::toString(){

    string kortEgenskaper = rankToString(r) + " of " + suitToString(s);
    return kortEgenskaper;
}

string Card::toStringShort(){
    string suit = suitToString(s);
    string kompaktVersjon = suit[0] + to_string(static_cast<int>(r)); 

    return kompaktVersjon;
}