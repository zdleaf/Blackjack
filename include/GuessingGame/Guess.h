#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include <tuple>

#include "../Deck.h"
#include "../Cards.h"

using namespace std;

class Guess{
    private:
        int numberOfGuesses;
        Deck<Card> *deck;
        shared_ptr<Card> card;

    public:
        Guess();
        ~Guess();
        void generate();

        // encapsulation/getters
        shared_ptr<Card> getCard();
        int getNumberOfGuesses();

        // gameplay
        void newGame();
        void gameLoop();
        bool guessLoop();
        bool compareGuess(std::vector<int> guessVec);
        void playAgain();
};


#endif