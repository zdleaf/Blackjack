#include "include/Blackjack/Player.h"

// store the last uniqueID used when assigned CPU and/or Players - incremented when each constructor is called
unsigned int uniquePlayerID = 1;
unsigned int uniqueCPUID = 1;

Player::Player(){

}

string Player::getName(){ return name; }
void Player::setName(string name){ this->name = name; }

void Player::setCard1(shared_ptr<Card> card){ card1 = card; }
void Player::setCard2(shared_ptr<Card> card){ card2 = card; }
shared_ptr<Card> Player::getCard1(){ return card1; }
shared_ptr<Card> Player::getCard2(){ return card2; }

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