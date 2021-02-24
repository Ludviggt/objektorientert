#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

CardDeck::CardDeck(){

    for ( auto x : rankStrings){
        for ( auto y : suitStrings){    
            Card gjeldendeKort(y.first, x.first);
            cards.push_back(gjeldendeKort);


        }
    
    }
    
}

void CardDeck::swap( int a, int b){
    Card store = cards[a];
    cards[a] = cards[b]; 
    cards[b] = store;
}

void CardDeck::print(){

    for (auto kort : cards){
        string  streng = kort.toString();
        cout << streng <<endl;
    }
}

void CardDeck::printShort(){
    for ( auto kort : cards){
        string  streng = kort.toStringShort();
        cout << streng <<endl;
    }
}
void CardDeck::shuffle(){
    
    for (unsigned int i = 0 ; i < cards.size(); ++i){
        int tilfeldigTall = (rand() & (cards.size()-1));  
        swap(i , tilfeldigTall);
    }
    for (unsigned int i = 0 ; i < cards.size(); ++i){
        int tilfeldigTall = (rand() & (cards.size()-1));  
        swap(i , tilfeldigTall);
    }

}
Card CardDeck::drawCard(){
    if(size(cards)>0){
        Card topCard  = cards[cards.size() - 1];
        cards.pop_back();
        return topCard;
    }
    error("Alle kortene er delt ut.\n");
}