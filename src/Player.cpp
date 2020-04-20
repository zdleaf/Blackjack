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

void Player::clearHand(){ playerHand.clear(); }

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


const void Player::displayAscii(){ // display ascii representation of players cards
    array<string, 6> asciiCards; // array to hold the 6 lines of ascii strings that makes up a card
    for(shared_ptr<BlackjackCard> card: playerHand){
        array<string, 6> tempCard = card->getAscii(); // get the ascii of each card
        for(int i=0; i<6;i++){ asciiCards[i].append(tempCard[i]); } // append each line to our ascii representation
    }
    for(string s: asciiCards){ cout << s << endl; } // display
}

const void Player::displayFullHand(){ // display full hand, including name, ascii and total
    cout << "\n" << name << ": " << endl;
    displayAscii(); 
    displayHand();
}

const void Player::displayHiddenHand(){
    cout << "\n" << name << ": " << endl;
    array<string, 6> hiddenCard = {".------.", "|------|", "|------|", "|------|", "|------|", "'------'"};
    array<string, 6> asciiCards;
    for(int i = 0; i<playerHand.size(); i++){ // display a hidden card for the number of cards in playerHand
        for(int i=0; i<6;i++){ asciiCards[i].append(hiddenCard[i]); } // append each line to our ascii representation
    }
    for(string s: asciiCards){ cout << s << endl; } 
}

const bool Player::bust(){
    if(handTotal() > 21){ return true; }
    return false;
}

Human::Human():Player(){ // constructor
    setName("Player"+to_string(uniquePlayerID));
    uniquePlayerID++;
}

bool Human::playLoop(Deck<BlackjackCard> *deck){
    string input;
    string validatedInput;
    while(true){
        cout << "\n[s]tick or [t]wist: ";
        cin >> input;
        cin.ignore();
        if (input == "quit"){ exit(0); }
        else if(input == "t" || input == "T"){
            addCard(deck->deal());
            displayFullHand();
            if(handTotal() > 21){ cout << "\n" << getName() << " BUST!" << endl; return false; }
        }
        else if(input == "s" || input == "S"){
            if(handTotal() <= 21){ return true; }
        }
        else { cout << "Invalid input. Enter \"s\" to stick or \"t\" to twist: "; }
    }
    return false;
}

CPU::CPU(Blackjack *blackjack):Player(){ // constructor
    setName("CPU"+to_string(uniqueCPUID));
    uniqueCPUID++;
    this->blackjack = blackjack;
}

bool CPU::playLoop(Deck<BlackjackCard> *deck){
    int highestScore = blackjack->highestScore(); cout << "\nHighest player score to beat: " << highestScore << endl;
    while(handTotal() < highestScore){
        cout << "\nCPU thinking "; for(int i=0;i<10;i++){ this_thread::sleep_for(chrono::milliseconds(100)); cout << "."; cout.flush(); }
        cout << "\nCPU twists" << endl;
        cout << "Dealing another card: " << endl;
        addCard(deck->deal());
        displayFullHand();
    }
    if(handTotal() > 21){ cout << "\nCPU BUSTS!" << endl; return false; }
    return true;
}