#include "../include/GuessingGame/Guess.h"
#include "../include/Blackjack/Blackjack.h"

// compile command only works in root directory!
// g++ src/*.cpp -I. -o main -std=c++17

int main(){
    
    cout << "---------------------------------------------------------------" << endl;
    cout << "              What game do you want to play: " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << " 1. Card Guessing Game" << endl;
    cout << " 2. Blackjack" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Enter a number 1 or 2: ";
    int gameNumber;
    while(true){
        string input; 
        cin >> input;
        cin.ignore();
        stringstream ss(input); // use stringstream to validate our input
        ss >> gameNumber;
        if (ss.fail()) { cout << "Invalid input. Please enter a number 1-2" << endl; } // if to int fails for any reason e.g. non-number entered
        else if (gameNumber > 2 || gameNumber < 1){ cout << "Invalid input. Please enter a number 1-2" << endl; }
        else { break; }
    }
    if(gameNumber == 1){
        Guess *guess = new Guess();
        guess->newGame();
    }
    else if(gameNumber == 2){
        Blackjack *blackjack = new Blackjack();
        blackjack->newGame();
        delete blackjack;
    }

/*     Guess *guess = new Guess();
    guess->newGame(); */

/*     Deck<Card> *deck = new Deck<Card>();
    deck->shuffle();
    Card *card = deck->deal();
    delete newGame;

   //TEST END OF VECTOR/OUT OF BOUNDS
    for(int i=0; i < 55; i++){
        if(card != nullptr){
            cout << card->toStr() << endl;
        } else { cout << "end of deck - no more cards left" << endl; }
        card = deck->deal();
    }  
    
    delete deck;
    
    */

    
}