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
        Card *card;

    public:
        Guess();
        ~Guess();
        void generate();

        Card* getCard();
        int getNumberOfGuesses();

        void newGame();
        void gameLoop();

        std::vector<int> validateInput();
        void invalidInput();
        int getValFromInput(string &input, int charsToProcess = 1) const;
        bool guessLoop();
        bool compareGuess(std::vector<int> guessVec);
        void playAgain();
};


#endif