#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "../Deck.h"
#include "../Cards.h"
#include "Blackjack.h"

class Blackjack; // forward declaration

class Player{
    private:
        string name;

    protected:
        std::vector<shared_ptr<BlackjackCard>> playerHand; // hand is a vector of shared_ptrs to cards in the deck

    public:
        Player();
        string getName() const;
        void setName(string name);

        void addCard(shared_ptr<BlackjackCard> card);
        std::vector<shared_ptr<BlackjackCard>> getHand() const; // return the vector that comprises of a players hand
        void clearHand();
        int handTotal() const;
        void displayHand() const;
        void displayAscii() const;
        void displayFullHand() const;
        void displayHiddenHand() const;
        bool bust() const;

        virtual bool playLoop(Deck<BlackjackCard> *deck) = 0; // make Player abstract with pure virtual - cannot be directly instantiated and all sub classes must implement this function

};

class Human: public Player {
    private:

    public:
        Human();
        bool playLoop(Deck<BlackjackCard> *deck); // handles actions for game play

};

class CPU: public Player {
    private:
        Blackjack *blackjack; // pointer to blackjack game object so CPU has access to game info

    public:
        CPU(Blackjack* blackjack);
        bool playLoop(Deck<BlackjackCard> *deck); // handles actions for CPU gameplay
};

#endif