#include "../include/GuessingGame/Guess.h"

Guess::Guess(){
    deck = new Deck<Card>(); // create a deck of cards
}

Guess::~Guess(){
    delete deck; // delete our deck of cards when deconstructor called
}

void Guess::newGame(){
    numberOfGuesses = 1; // reset the number of guesses
    deck->shuffle(); // shuffle the deck
    card = deck->deal(); // deal a card
    gameLoop(); // start the game loop
}

shared_ptr<Card> Guess::getCard(){ return card; }
int Guess::getNumberOfGuesses(){ return numberOfGuesses; }

void Guess::gameLoop(){
    bool gameWon = false;
    cout << "---------------------------------------------------------------" << endl;
    cout << "               Welcome to the Card Guessing Game!" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Value ranks:   A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K" << endl;
    cout << "Suits:         d = diamonds, h = hearts, c = clubs, s = spades" << endl;
    cout << "---------------------------------------------------------------" << endl;
    // cout << getCard()->toStr() << endl; // debug: display card for debugging purposes
    cout << "Type \"quit\" to exit at any time" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Guess a card e.g. 3h, Qd, Ac, 10s" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    while(!gameWon){ gameWon = guessLoop(); } // run guessLoop() until the game is won
    if(gameWon){ playAgain(); } // if we've won, display play again dialog
}

bool Guess::guessLoop(){
    vector<int> guessVec;
    int value; int suit;
    string input = "";
    bool validInput = false;
    while(!validInput){
        cout << "Enter a guess (attempt " << getNumberOfGuesses() << "): " << endl;
        guessVec = Card::inputToCard(); // get card input from Card class and return the card {suit,value}
        // cout << "guessVec[0]: " << guessVec[0] << " guessVec[1]: " << guessVec[1] << endl; // debug: display suit/value vector
        if(guessVec[0] != 0 && guessVec[1] != 0) { validInput = true; } // inputToCard() will always return "0" unless we get a valid input for suit/value
    }
    return compareGuess(guessVec); // compare our guess and return true or false
}

bool Guess::compareGuess(vector<int> guessVec){
    if      (guessVec[0] > card->getValue() && guessVec[1] != card->getSuit()){ cout << "Value of card too high and suit is wrong" << endl; numberOfGuesses++; return false; }
    else if (guessVec[0] < card->getValue() && guessVec[1] != card->getSuit()){ cout << "Value of card too low and suit is wrong" << endl; numberOfGuesses++; return false; }
    else if (guessVec[0] == card->getValue() && guessVec[1] != card->getSuit()){ cout << "Value of card is correct, however the suit is wrong" << endl; numberOfGuesses++; return false; }
    else if (guessVec[0] > card->getValue() && guessVec[1] == card->getSuit()){ cout << "Value of card too high, however the suit is correct" << endl; numberOfGuesses++; return false; }
    else if (guessVec[0] < card->getValue() && guessVec[1] == card->getSuit()){ cout << "Value of card too low, however the suit is correct" << endl; numberOfGuesses++; return false; }
    if(guessVec[0] == card->getValue() && guessVec[1] == card->getSuit()){ cout << "Correct!" << endl << "You guessed in " << getNumberOfGuesses() << " attempts." << endl; return true; }
    return false; // default condition should never return
}

void Guess::playAgain(){
    cout << "Do you want to play again?" << endl;
    cout << "Press \"y\" for yes, or anything else to quit" << endl;
    string input;
    cin >> input;
    cin.ignore();
    if (input == "y") { newGame(); }
    exit(0);
}