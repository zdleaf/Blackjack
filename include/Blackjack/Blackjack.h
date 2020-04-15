#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>

#include "../Deck.h"
#include "../Cards.h"
#include "Player.h"

class Blackjack{
    private:
        Deck<BlackjackCard> *deck; // deck is initialised in constructor
        std::vector<Player*> playerVec; // vector of the players in the current game

    public:
        Blackjack();
        ~Blackjack();
        void addHumanPlayer();
        void addCPUPlayer();
        void newGame();

        
};

#endif