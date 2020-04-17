#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>

#include "../Deck.h"
#include "../Cards.h"
#include "Player.h"

class Player; // forward declaration

class Blackjack{
    private:
        Deck<BlackjackCard> *deck; // deck is initialised in constructor
        std::vector<Player*> playerVec; // vector of the players in the current game
        Player* dealer; // pointer to the CPU player/dealer (also in the playerVec)

    public:
        Blackjack();
        ~Blackjack();
        void addHumanPlayer();
        void addCPUPlayer();
        void newGame();
        void gameLoop();
        void playAgain();
        bool playLoop();
        void determineWinner();
        int highestScore();

};

#endif