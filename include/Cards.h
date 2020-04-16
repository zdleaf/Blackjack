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
        Card(int suit,int value);
        string toStr();

        int getSuit();
        int getValue();
        string getSuitStr();
        string getValueStr();
        array<string, 6> getAscii();

        string lookupSuit(int suit); // abstract/static? can be called anywhere
        string lookupValue(int value);
        static int rlookupValue(string cVal);
};

class BlackjackCard: public Card {
    private:
        int points;

    public:
        BlackjackCard(int suit,int value);
        int getPoints();
};

#endif