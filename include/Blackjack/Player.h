#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "Blackjack.h"

class Player{
    private:
        Card *card1;
        Card *card2;
        string name;

    public:
        string getName();
};

class Human: public Player{
    private:

    public:

};

class CPU: public Player{
    private:

    public:
};

#endif