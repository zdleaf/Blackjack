#include "../include/GuessingGame/Guess.h"

Guess::Guess(){
    deck = new Deck<Card>(); // create a deck of cards
}

Guess::~Guess(){
    delete deck; // delete our deck of cards
}

void Guess::newGame(){
    numberOfGuesses = 1; // reset the number of guesses
    deck->shuffle(); // shuffle the deck
    card = deck->deal(); // deal a card
    gameLoop(); // start the game loop
}

Card* Guess::getCard(){ return card; }
int Guess::getNumberOfGuesses(){ return numberOfGuesses; }

void Guess::gameLoop(){
    bool gameWon = false;
    cout << "---------------------------------------------------------------" << endl;
    cout << "               Welcome to the Card Guessing Game!" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Value ranks:   A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K" << endl;
    cout << "Suits:         d = diamonds, h = hearts, c = clubs, s = spades" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << getCard()->toStr() << endl; // debug: display card for debugging purposes
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
        guessVec = validateInput();
        // cout << "guessVec[0]: " << guessVec[0] << " guessVec[1]: " << guessVec[1] << endl; // debug: display suit/value vector
        if(guessVec[0] != 0 && guessVec[1] != 0) { validInput = true; } // validateInput() will always return "0" unless we get a valid input for suit/value
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

int Guess::getValFromInput(string &input, int charsToProcess/* = 1 */) const{
    int value;
    stringstream ss(input.substr(0,charsToProcess));
    ss >> value;
    if (ss.fail()) { return 0; } // if we input a string for example
    return value;
}

std::vector<int> Guess::validateInput(){
    vector<int> result = {0,0}; // default 0,0 - signifies error with input
    string input;
    string validatedInput;

    cin >> input;
    cin.ignore();
    if (input == "quit"){ exit(0); }
    stringstream ss(input); // use stringstream to validate our input
    ss >> validatedInput;
    if (ss.fail()) { invalidInput(); return result; } // if to string fails for any reason
    if (validatedInput.length() > 3){ invalidInput(); return result; } // maximum length should be 3, e.g. 10d

    // test first and/or second character are 1-10 e.g. 10d, 4d
    if(getValFromInput(validatedInput) < 10 && getValFromInput(validatedInput) > 1){ // if first character is 1-9
        result[0] = getValFromInput(validatedInput);
    } 
    else if(validatedInput[0] == '1' && validatedInput[1] == '0'){ result[0] = 10; } 
    else if(validatedInput[0] == '1' && validatedInput[1] != '0'){ result[0] = 1; }
    else if(validatedInput[0] == 'A' || validatedInput[0] == 'a'){ result[0] = 1; }
    else if(validatedInput[0] == 'J' || validatedInput[0] == 'j'){ result[0] = 11; }
    else if(validatedInput[0] == 'Q' || validatedInput[0] == 'q'){ result[0] = 12; }
    else if(validatedInput[0] == 'K' || validatedInput[0] == 'k'){ result[0] = 13; }
    else { invalidInput(); return result; }

    // test if second or third character is a suit: h,d,s,c
    int i;
    if(validatedInput[1] == '0'){ i = 2; } // if it's a 10, we want to test the third character instead
    else { i = 1; }

    if      (validatedInput[i] == 'h' || validatedInput[i] == 'H'){ result[1] = 1; }
    else if (validatedInput[i] == 'd' || validatedInput[i] == 'D'){ result[1] = 2; }
    else if (validatedInput[i] == 's' || validatedInput[i] == 'S'){ result[1] = 3; }
    else if (validatedInput[i] == 'c' || validatedInput[i] == 'C'){ result[1] = 4; }
    else { invalidInput(); return result; }

    return result; // if we've missed any of the above conditions, return <0,0>
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
    cout << "Invalid input - please enter a card in the following format: 3h, Qd etc" << endl; 
}