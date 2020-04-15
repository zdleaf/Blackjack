#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "../Deck.h"
#include "../Cards.h"

class Player{
    private:
        Card *card1;
        Card *card2;
        string name;

    public:
        Player();
        string getName();

        void setCard1(Card *card);
        void setCard2(Card *card);
        Card* getCard1();
        Card* getCard2();
};

class Human: public Player {
    private:

    public:
        Human();

};

class CPU: public Player {
    private:

    public:
};

#endif