#include "Guess.h"

Guess::Guess(){
    deck = new Deck<Card>(); // create a deck of cards
}

Guess::~Guess(){
    delete deck;
    delete card;
}

void Guess::newGame(){
    numberOfGuesses = 1; // reset the number of guesses
    deck->shuffle(); // shuffle the deck
    card = deck->deal(); // deal a card
    gameLoop(); // start the game loop
}

int Guess::getRandomNumber(){ return randomNumber; }
int Guess::getNumberOfGuesses(){ return numberOfGuesses; }

void Guess::gameLoop(){
    bool gameWon = false;
    cout << "-----------------------------------" << endl;
    cout << "Welcome to the Card Guessing Game!" << endl;
    //cout << getRandomNumber() << endl;
    cout << "Type \"quit\" to exit at any time" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Guess a card e.g. 3h, Qd" << endl;
    cout << "-----------------------------------" << endl;
    
    while(!gameWon){ gameWon = guessLoop(); } // run guessLoop() until the game is won
    if(gameWon){ playAgain(); } // if we've won, display play again dialog
}

bool Guess::guessLoop(){
    string input = "";
    bool validInput = false;
    cout << "Enter a guess (attempt " << getNumberOfGuesses() << "): " << endl;
    while(!validInput){
        input = validateInput();
        if(input != 0) { validInput = true; } // validateInput() will always return 0 unless we get a valid input
    }
    return compareGuess(input); // compare our guess and return true or false
}

bool Guess::compareGuess(string guess) const{
    if(guess  getRandomNumber()){ cout << "Too low! Try again." << endl; numberOfGuesses++; return false; }
    if(guess > getRandomNumber()){ cout << "Too high! Try again." << endl; numberOfGuesses++; return false; }
    if(guess == card->toStr()){ cout << "Correct!" << endl << "You guessed in " << getNumberOfGuesses() << " attempts." << endl; return true; }
    return false; // default condition should never return
}

int Guess::validateInput(){
    int number;
    string input;

    cin >> input;
    cin.ignore();

    if (input == "quit"){ exit(0); }

    stringstream ss(input); // use stringstream to validate our input
    ss >> number;
    if (ss.fail()) { invalidInput(); return 0; } // if we input a string for example
    else if (number < 1000 || number > 9999) { invalidInput(); return 0; }
    else if (number >= 1000 && number <= 9999){ return number; }
    return 0; // if we've missed any of the above conditions, return 0
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

void Guess::invalidInput(){ 
    cout << "Incorrect input - please enter a number between 1000 and 9999" << endl; 
    cout << "Enter a guess (attempt " << getNumberOfGuesses() << "): " << endl; 
}