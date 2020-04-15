#include "include/Blackjack/Blackjack.h"

// constructor
Blackjack::Blackjack(){
    deck = new Deck<Card>(); // create a deck of cards
}

// de-constructor
Blackjack::~Blackjack(){
    delete deck; // delete our deck of cards
}

void Blackjack::newGame(){
    deck->shuffle(); // shuffle the deck
    cout << "shuffled" << endl;

    // deal two cards to each player in turn - for each player in vector
/*     for( Human p: playerVec){ p.setCard1(deck->deal()); } // deal first card
    for( Human p: playerVec){ p.setCard2(deck->deal()); } // deal second card */

    for( Human* p: playerVec){ p->setCard1(deck->deal()); }
    for( Human* p: playerVec){ p->setCard2(deck->deal()); }

/*     p1.setCard1(deck->deal());
    p1.setCard2(deck->deal()); */
    for( Human* p: playerVec){ cout << p->getCard1()->toStr() << "," << p->getCard2()->toStr() << endl; }


    
}