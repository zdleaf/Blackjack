#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "../Deck.h"
#include "../Cards.h"

class Player{
    private:
        string name;

    protected:
        std::vector<shared_ptr<BlackjackCard>> playerHand; // hand is a vector of shared_ptrs to cards in the deck

    public:
        Player();
        const string getName();
        void setName(string name);

        void addCard(shared_ptr<BlackjackCard> card);
        const std::vector<shared_ptr<BlackjackCard>> getHand(); // return the vector that comprises of a players hand
        void clearHand();
        const int handTotal();
        const void displayHand();
        const void displayAscii();
        const void displayFullHand();
        const void displayHiddenHand();
 
        virtual bool playLoop(Deck<BlackjackCard> *deck) = 0; // make Player abstract - cannot be directly instantiated and all sub classes must implement this function

};

class Human: public Player {
    private:

    public:
        Human();
        bool playLoop(Deck<BlackjackCard> *deck);

};

class CPU: public Player {
    private:

    public:
        CPU();
        bool playLoop(Deck<BlackjackCard> *deck);
};

#endif