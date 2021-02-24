#include "std_lib_facilities.h"
#pragma once
#include "CardDeck.h"

const map<Rank, int> valuesInBlackjack{
        {Rank::two, 2},
        {Rank::three, 3},
        {Rank::four, 4},
        {Rank::five, 5},
        {Rank::six, 6},
        {Rank::seven, 7},
        {Rank::eight, 8},
        {Rank::nine, 9},
        {Rank::ten, 10},
        {Rank::jack, 10},
        {Rank::queen, 10},
        {Rank::king, 10},
        {Rank::ace, 11},
    };

class Blackjack{
    private: 
    CardDeck deck;
    
    vector<Card> spillerensKort;
    vector<Card> dealerensKort;
    
    int spillerensSum;
    int dealerensSum;
    void showStartCards(); // Denne funksjonen skal vise spilleren startkortene sine og et av dealer sine
    
    int getSpillerKort(Card kort); // Skal mappe verdien på kortet fra string til verdi, må aksessere ranken, for å oppdatere summen av hånda
                                   // og returnere kortverdien til spiller 
    int getDealerKort(Card kort); // Skal mappe verdien på kortet fra string til verdi, må aksessere ranken
                                // og returnere kortverdien til dealer
    
    void stokkOgDelKort(); // skal opprette kortstokk, stokke og dele ut to kort til hver av dealer og spiller
    public:
    void spillBlackjack(); // Skal gå gjennom spillet til spiller enten vinner eller taper

};