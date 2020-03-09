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
        uniform_int_distribution<std::mt19937::result_type> initRandomSeed();
        mt19937 initRng();

        Card(int value, int suit){
            this->value = value;
            this->suit = suit;
            std::cout << "Created card " << returnValue(value) << returnSuit(suit) << endl;
        }

        string returnSuit(int suit);
        string returnValue(int value);

};


#endif