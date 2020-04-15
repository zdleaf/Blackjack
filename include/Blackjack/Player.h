#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "../Deck.h"
#include "../Cards.h"

class Player{
    private:
        shared_ptr<Card> card1;
        shared_ptr<Card> card2;
        string name = "zach";

    public:
        Player();
        string getName();

        void setCard1(shared_ptr<Card> card);
        void setCard2(shared_ptr<Card> card);
        shared_ptr<Card> getCard1();
        shared_ptr<Card> getCard2();

        virtual void test() = 0; // make Player abstract - cannot be directly instantiated and all sub classes must implement this function

};

class Human: public Player {
    private:

    public:
        Human();
        void test();

};

class CPU: public Player {
    private:

    public:
        CPU();
        void test();
};

#endif