#include "include/GuessingGame/Guess.h"
#include "include/Blackjack/Blackjack.h"

// compile command only works in root directory!
// g++ test.cpp src/Cards.cpp -o test -std=c++11

int main(){
    
    Deck<Card> *deck = new Deck<Card>();
    //deck->shuffle();
    shared_ptr<Card> card = deck->deal();

    //TEST CARDS LEFT IN DECK
    for(int i=0; i < 2; i++){
        if(card != nullptr){
            cout << i << ": " << card->toStr() << endl;
        } else { cout << "end of deck - no more cards left" << endl; }
        card = deck->deal();
    }  

    cout << "Cards left in deck: " << deck->size() << endl;

    cout << "Is deck empty? " << deck->isEmpty() << endl;

   //TEST END OF VECTOR/OUT OF BOUNDS
    for(int i=0; i < 55; i++){
        if(card != nullptr){
            cout << i << ": " << card->toStr() << endl;
        } else { cout << "end of deck - no more cards left" << endl; }
        card = deck->deal();
    }

    cout << "Is deck empty? " << deck->isEmpty() << endl;

    delete deck;
    
   
}


