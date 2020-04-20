#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <unordered_map>

#include "../Deck.h"
#include "../Cards.h"
#include "Player.h"

class Player; // forward declaration

class Blackjack{
    private:
        Deck<BlackjackCard> *deck; // deck is initialised in constructor
        std::vector<Player*> playerVec; // vector of the players in the current game
        Player* dealer; // pointer to the CPU player/dealer (also in the playerVec)

        // statistics
        unordered_map<Player*, int> scoreMap; // hash map to save score
        vector<string> roundWinners; // vector to store the names of the winning players for each round
        int currentRound = 0; // store the current round

    public:
        void addPlayersUI();
        Blackjack();
        ~Blackjack();
        void addHumanPlayer();
        void addCPUPlayer();
        void initialiseScores();
        void newGame();
        void gameLoop();
        void displayStats();
        void playAgain();
        bool playLoop();
        void incrementStats(Player* p);
        void determineWinner();
        int highestScore();

};

#endif