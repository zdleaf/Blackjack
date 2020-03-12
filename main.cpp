#include "Cards.h"
#include "Deck.h"

// g++ *.cpp -I. -o main -std=c++17

int main(){
    Deck<Card> *deck = new Deck<Card>();
    Card *card = deck->deal();
    for(int i=0; i < 55; i++){
        if(card != nullptr){
            cout << card->toStr() << endl;
        } else { cout << "end of deck - no more cards left" << endl; }
        card = deck->deal();
    }

    delete deck;
/*     for(Card &c: deck){

    } */
}