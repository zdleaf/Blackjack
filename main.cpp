#include "Cards.h"
#include "Deck.h"
#include "Guess.h"

// g++ *.cpp -I. -o main -std=c++17

int main(){
    Guess *newGame = new Guess();
    newGame->newGame();
/*     Deck<Card> *deck = new Deck<Card>();
    deck->shuffle();
    Card *card = deck->deal();

   //TEST END OF VECTOR/OUT OF BOUNDS
    for(int i=0; i < 55; i++){
        if(card != nullptr){
            cout << card->toStr() << endl;
        } else { cout << "end of deck - no more cards left" << endl; }
        card = deck->deal();
    }  
    
    delete deck;
    
    */

    delete newGame;
}