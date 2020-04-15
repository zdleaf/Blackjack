#include "include/Blackjack/Player.h"

Player::Player(){

}

string Player::getName(){ return name; }

void Player::setCard1(Card *card){ card1 = card; }
void Player::setCard2(Card *card){ card2 = card; }
Card* Player::getCard1(){ return card1; }
Card* Player::getCard2(){ return card2; }

Human::Human():Player(){
    // constructor
}
