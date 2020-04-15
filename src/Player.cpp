#include "include/Blackjack/Player.h"

Player::Player(){

}

string Player::getName(){ return name; }

void Player::setCard1(shared_ptr<Card> card){ card1 = card; }
void Player::setCard2(shared_ptr<Card> card){ card2 = card; }
shared_ptr<Card> Player::getCard1(){ return card1; }
shared_ptr<Card> Player::getCard2(){ return card2; }

Human::Human():Player(){
    // constructor
}
