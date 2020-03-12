#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <random>
#include <sstream>

using namespace std;


class Card{
    private:
        int suit;
        int value;

    public:
        Card(int suit,int value);
        string toStr();

        string returnSuit(int suit); // abstract/static? can be called anywhere
        string returnValue(int value);

};

#endif