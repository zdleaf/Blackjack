#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>

#include "../Deck.h"
#include "../Cards.h"
#include "Player.h"

class Blackjack{
    private:
        Deck<Card> *deck; // deck is initialised in constructor

        // store players in vector<Player>? or vector<CPU> vector<Human> - need to handle adding players and adding a hand for them
        // each player has 2 pointers to cards dealt from this deck

        Human p1;
        CPU p2;
        std::vector<Player*> playerVec = { (Player*)&p1, (Player*)&p2 }; // upcasting

    public:
        Blackjack();
        ~Blackjack();
        void newGame();
};

#endif