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

    // deal two cards to each player in turn - for each player in vector
/*     for( Human p: playerVec){ p.setCard1(deck->deal()); } // deal first card
    for( Human p: playerVec){ p.setCard2(deck->deal()); } // deal second card */

    for( Player* p: playerVec){ p->setCard1(deck->deal()); }
    for( Player* p: playerVec){ p->setCard2(deck->deal()); }

/*     p1.setCard1(deck->deal());
    p1.setCard2(deck->deal()); */
    for( Player* p: playerVec){ p->test(); cout << p->getCard1()->toStr() << "," << p->getCard2()->toStr() << endl; }


    
}