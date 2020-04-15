#include "../include/GuessingGame/Guess.h"
#include "../include/Blackjack/Blackjack.h"

// compile command only works in root directory!
// g++ src/*.cpp -I. -o main -std=c++17

int main(){
    
/*     Blackjack *blackjack = new Blackjack();
    blackjack->newGame();
    delete blackjack; */

    Guess *guess = new Guess();
    guess->newGame();

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