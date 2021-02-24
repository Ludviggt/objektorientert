#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Blackjack.h"




void Blackjack::stokkOgDelKort(){ // skal opprette kortstokk, stokke og dele ut to kort til hver av dealer og spiller
    spillerensSum = 0;
    dealerensSum = 0; 
    
    deck = CardDeck{}; 

    deck.shuffle();
    spillerensKort.push_back(deck.drawCard());
    dealerensKort.push_back(deck.drawCard());
    spillerensKort.push_back(deck.drawCard());    
    dealerensKort.push_back(deck.drawCard());
}




void Blackjack::showStartCards(){ // Denne funksjonen skal vise spilleren startkortene sine og et av dealer sine
    cout << "Dette er kortene dine: " << endl;
    for (int i = 0; i<spillerensKort.size(); ++i){
        
        cout << spillerensKort[i].toString() << endl;
    }
    cout << endl;
    cout << "I spillet blackjack skal du se et av startkortene til dealer, som er: "<<endl;
    cout <<dealerensKort[0].toString()<<endl;
    cout << endl;

}

int Blackjack::getSpillerKort(Card kort){
// må sjekke om kortet er et ess, da oppstår 2 forskjellige valg
    if (kort.getRank() == Rank::ace){
        int valg = 0;
        cout << " Hvilken verdi vil du bruke esset som, 1 eller 11? ";
        cin >> valg;
        while(!(valg == 1 || valg == 11)){
            cout << "Valgt verdi er ikke gyldig, 1 eller 11? ";
            
        }
        
        return valg;
    }
    return valuesInBlackjack.at(kort.getRank());

}

int Blackjack::getDealerKort(Card kort){
// må sjekke om kortet er et ess, da oppstår 2 forskjellige valg
    if (kort.getRank() == Rank::ace){
        if( dealerensSum <11 ){
            return 11;
        }
        else if( dealerensSum >= 11){
            return 1;
        }
        
    }
    return valuesInBlackjack.at(kort.getRank());
}

void Blackjack::spillBlackjack(){
    bool resultat = true; 
    cout << "Da spiller du Blackjack, haaper du er kjent med reglene og det er ikke lov til aa telle kort" << endl;
    spillerensKort.clear();
    dealerensKort.clear();
    stokkOgDelKort();
    showStartCards();
    spillerensSum = getSpillerKort(spillerensKort[0]) + getSpillerKort(spillerensKort[1]);
    dealerensSum = getDealerKort(dealerensKort[0]) + getDealerKort(dealerensKort[1]);
    cout << "Du har naa en totalsum paa: "<< spillerensSum<<endl;
    cout << endl;
    int valg = 0;
    
    deck.shuffle();
    
    while(dealerensSum< 17){
        dealerensKort.push_back(deck.drawCard());
        dealerensSum += getDealerKort(dealerensKort[dealerensKort.size() -1]);
        
    }
    
    deck.shuffle();
    while(valg != 2 && spillerensSum < 21){
        cout << "Vil du trekke et kort til? tast 1 for ja og 2 for nei"<<endl;
        cin >> valg;
        if(valg == 1){
            spillerensKort.push_back(deck.drawCard());
            spillerensSum += getSpillerKort(spillerensKort[spillerensKort.size() -1 ]);
            cout << " summen din er naa: " << spillerensSum<< endl;
        }
    }
    cout << endl;
    cout <<"Du har kortene: "<<endl;
    for(auto kort : spillerensKort){
        cout << kort.toString()<< endl;
    }
    cout << endl;
    cout <<"Dealeren har kortene: "<<endl;
    for( auto kort : dealerensKort){
        cout << kort.toString() << endl;
    }
    

    if ( spillerensSum > 21){
       cout << "Du overgikk maksgrense for poeng"<<endl;
       resultat = false;
    }
    else if ( dealerensSum > 21){
        cout << "Dealeren overgikk maks poengsum"<< endl;
        resultat = true;
    }
    else if( spillerensSum == 21 && spillerensKort.size() == 2 && dealerensSum < 21){
        cout <<"Du fikk blakjack et ess og et bildekort"<< endl;
        resultat = true;
    }
    else if ( spillerensSum > dealerensSum && spillerensSum <=21 ){
        cout << "Du fikk hoeyere poengsum enn dealer." << endl;
        resultat =true;
    }
    else if( dealerensSum > spillerensSum && dealerensSum <=21 ){
        cout<<"Dealern fikk hoeyest poengsum"<<endl;
        resultat = false;
    }
    else if ( dealerensSum == spillerensSum && dealerensSum <=21){
        cout <<"Du fikk samme poengsum som dealer"<<endl;
        resultat = false;
    }
    if (resultat) {
        cout <<"Gratulerer du vant spillet"<<endl;
    }
    else{
        cout<<"Dealeren vant spillet, bedre lykke neste gang!"<< endl;
    }
    

}  


