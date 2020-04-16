#include "include/Blackjack/Player.h"

// store the last uniqueID used when assigned CPU and/or Players - incremented when each constructor is called
unsigned int uniquePlayerID = 1;
unsigned int uniqueCPUID = 1;

Player::Player(){
    // blank constructor
}

const string Player::getName(){ return name; }
void Player::setName(string name){ this->name = name; }

void Player::addCard(shared_ptr<BlackjackCard> card){ playerHand.push_back(card); }

const std::vector<shared_ptr<BlackjackCard>> Player::getHand(){ return playerHand; }

const int Player::handTotal(){
    int total = 0;
    for(shared_ptr<BlackjackCard> card: playerHand){
        total += card->getPoints();
    }
    return total;
}

const void Player::displayHand(){
    for(shared_ptr<BlackjackCard> card: playerHand){ cout << card->toStr(); } // print each card in the players hand
    cout << " total:" << handTotal() << endl;  
}

// display ascii representation of players cards
const void Player::displayAscii(){
    array<string, 6> asciiCards; // array to hold the 6 lines of ascii strings that makes up a card
    for(shared_ptr<BlackjackCard> card: playerHand){
        array<string, 6> tempCard = card->getAscii(); // get the ascii of each card
        for(int i=0; i<6;i++){ asciiCards[i].append(tempCard[i]); } // append each line to our ascii representation
    }
    for(string s: asciiCards){ cout << s << endl; } // display
}

Human::Human():Player(){ // constructor
    setName("Player"+to_string(uniquePlayerID));
    uniquePlayerID++;
}

void Human::test(){ cout << getName() << endl; }  

void Human::playLoop(Deck<BlackjackCard> *deck){
    while(handTotal() < 17){
        addCard(deck->deal());
        displayHand();
    }
}

CPU::CPU():Player(){ // constructor
    setName("CPU"+to_string(uniqueCPUID));
    uniqueCPUID++;
}

void CPU::test(){ cout << getName() << endl; }  

void CPU::playLoop(Deck<BlackjackCard> *deck){
    while(handTotal() < 17){
        addCard(deck->deal());
        displayHand();
    }
    
}