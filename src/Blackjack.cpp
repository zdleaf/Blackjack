#include "include/Blackjack/Blackjack.h"

// constructor
Blackjack::Blackjack(){
    deck = new Deck<BlackjackCard>(); // create a deck of card
}

// de-constructor
Blackjack::~Blackjack(){
    cout << "Deconstructor called" << endl;
    delete deck; // delete our deck of cards
    for( Player* p: playerVec){ delete p; }; // delete all our players
}

void Blackjack::addHumanPlayer(){
    Human* player = new Human();
    playerVec.push_back((Player*)player); // upcasting
}

void Blackjack::addCPUPlayer(){
    CPU* player = new CPU();
    playerVec.push_back((Player*)player); // upcasting
}

void Blackjack::newGame(){
    // setup the players
    addCPUPlayer(); 
    addHumanPlayer();
    deck->shuffle(); // shuffle the deck

    // deal two cards to each player in turn - for each player in vector
    for( Player* p: playerVec){ p->addCard(deck->deal()); }
    for( Player* p: playerVec){ p->addCard(deck->deal()); }

/*     p1.setCard1(deck->deal());
    p1.setCard2(deck->deal()); */
    for( Player* p: playerVec){ 
        cout << p->getName() << ": " << endl;
        p->displayAscii(); 
        p->displayHand();
        //p->playLoop(deck);
    }
    
}