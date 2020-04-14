#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>

#include "include/Deck.h"
#include "include/Cards.h"
#include "include/Blackjack/Player.h"

class Blackjack{
    private:
        Deck<Card> *deck; // deck is initialised in constructor

        // store players in vector<Player>? or vector<CPU> vector<Human> - need to handle adding players and adding a hand for them
        // each player has 2 pointers to cards dealt from this deck

/*         Human p1;
        Human p2;
        vector<Human> playerVec = { p1, p2 }; */


    public:
        Blackjack();
        ~Blackjack();
        void newGame();
};

#endif