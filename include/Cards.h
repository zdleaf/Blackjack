#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <random>
#include <sstream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;


class Card {
    private:
        int suit;
        int value;

    public:
        // constructor
        Card(int suit,int value); 
        
        // get functions
        int getSuit() const;
        int getValue() const;
        string getSuitStr() const;
        string getValueStr() const;
        string toStr() const; // string representation of the hand e.g. Ah, 5d
        array<string, 6> getAscii() const; // get ascii card representation

        // lookup functions
        static string lookupSuit(int suit);
        static string lookupValue(int value);
        static int rlookupValue(string cVal);

        // user input to return card suit/value
        static std::vector<int> inputToCard(); // returns a vector {suit, value} after getting input from cin
        static void invalidInput();
        static int getValFromInput(string &input, int charsToProcess = 1);
};

class BlackjackCard: public Card {
    private:
        int points;

    public:
        BlackjackCard(int suit,int value);
        int getPoints() const;
};

#endif