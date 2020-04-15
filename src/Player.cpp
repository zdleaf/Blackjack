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

Human::Human():Player(){ // constructor
    setName("Player"+to_string(uniquePlayerID));
    uniquePlayerID++;
}

void Human::test(){ cout << getName() << endl; }  

CPU::CPU():Player(){ // constructor
    setName("CPU"+to_string(uniqueCPUID));
    uniqueCPUID++;
}

void CPU::test(){ cout << getName() << endl; }  