#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include <random>
#include <sstream>
#include "Deck.h"
#include "Cards.h"

using namespace std;

class Guess{
    private:
        int numberOfGuesses;
        int randomNumber;
        Deck<Card> *deck;
        Card *card;

    public:
        Guess();
        ~Guess();
        void generate();

        int getRandomNumber();
        int getNumberOfGuesses();

        void newGame();
        void gameLoop();

        int validateInput();
        void invalidInput();
        bool guessLoop();
        bool compareGuess(string guess) const;
        void playAgain();
};


#endif