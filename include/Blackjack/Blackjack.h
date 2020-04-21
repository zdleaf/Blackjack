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
        // game objects
        Deck<BlackjackCard> *deck; // deck is initialised/constructed in constructor
        std::vector<Player*> playerVec; // vector of the players in the current game
        Player* dealer; // pointer to the CPU player/dealer (also last item in the playerVec)

        // statistics
        std::unordered_map<Player*, int> scoreMap; // hash map to save score
        std::vector<string> roundWinners; // vector to store the names of the winning players for each round
        int currentRound = 0; // store the current round

    public:
        Blackjack();
        ~Blackjack();

        // initialise game
        void addPlayersUI();
        void addHumanPlayer();
        void addCPUPlayer();
        void initialiseScores();
        void newGame();

        // gameplay
        void gameLoop();
        bool playLoop();
        void determineWinner();
        void playAgain();
        int highestScore();

        // stats
        void displayStats();
        void incrementStats(Player* p);
};

#endif