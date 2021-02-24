#include "std_lib_facilities.h"
//#include "CardDeck.h"
#pragma once

enum class Suit{clubs, diamonds, hearts, spades};

enum class Rank{
    two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, 
    ten = 10, jack = 11, queen = 12, king = 13, ace = 14
};

const map<Suit, string> suitStrings{
        {Suit::clubs, "Clubs"},
        {Suit::diamonds, "Diamonds"},
        {Suit::hearts, "Hearts"},
        {Suit::spades, "Spades"},
    };

const map<Rank, string> rankStrings{
        {Rank::two, "Two"},
        {Rank::three, "Three"},
        {Rank::four, "Four"},
        {Rank::five, "Five"},
        {Rank::six, "Six"},
        {Rank::seven, "Seven"},
        {Rank::eight, "Eight"},
        {Rank::nine, "Nine"},
        {Rank::ten, "Ten"},
        {Rank::jack, "Jack"},
        {Rank::queen, "Queen"},
        {Rank::king, "King"},
        {Rank::ace, "Ace"},
    };

string suitToString(Suit suit);
string rankToString(Rank rank);

class Card {

    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank);
        Suit getSuit();
        Rank getRank();
        string toString();
        string toStringShort();
};
