#include "Cards.h"

Card::Card(int suit, int value){
    this->suit = suit;
    this->value = value;
    // std::cout << "Created card " << returnValue(value) << returnSuit(suit) << endl;
}

string Card::toStr(){
    return returnValue(value) + returnSuit(suit);
}

string Card::returnSuit(int cSuit){
    switch(cSuit){
        case 1: return "h";
        case 2: return "d";
        case 3: return "s";
        case 4: return "c";
        default: return "invalid suit";
    }
}

string Card::returnValue(int cVal){
    switch(cVal){
        case 1: return "A";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return "invalid card value";
    }
}