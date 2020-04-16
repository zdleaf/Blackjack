#include "../include/Cards.h"

Card::Card(int suit, int value){
    this->suit = suit;
    this->value = value;
    // std::cout << "Created card " << returnValue(value) << returnSuit(suit) << endl;
}

string Card::toStr(){
    return lookupValue(value) + lookupSuit(suit);
}

int Card::getSuit(){ return suit; }
int Card::getValue(){ return value; }
string Card::getSuitStr(){ return lookupSuit(getSuit()); }
string Card::getValueStr(){ return lookupValue(getValue()); }


string Card::lookupSuit(int cSuit){
    switch(cSuit){
        case 1: return "h";
        case 2: return "d";
        case 3: return "s";
        case 4: return "c";
        default: return "invalid suit";
    }
}

string Card::lookupValue(int cVal){
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
        case 10: return "T";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return "invalid card value";
    }
}

int Card::rlookupValue(string cVal){ // reverse lookup
    if(cVal == "A"){ return 1; }
    else if(cVal == "2"){ return 2; }
    else if(cVal == "3"){ return 3; }
    else if(cVal == "4"){ return 4; }
    else if(cVal == "5"){ return 5; }
    else if(cVal == "6"){ return 6; }
    else if(cVal == "7"){ return 7; }
    else if(cVal == "8"){ return 8; }
    else if(cVal == "9"){ return 9; }
    else if(cVal == "10"){ return 10; }
    else if(cVal == "J"){ return 11; }
    else if(cVal == "Q"){ return 12; }
    else if(cVal == "K"){ return 13; }
    else return 0;
}

array<string, 6> Card::getAscii(){
    // hjw's card templates from https://ascii.co.uk/art/cards
    array<string, 6> heart = {".------.", "|X_  _ |", "|( \\/ )|", "| \\  / |", "|  \\/ X|", "'------'"};
    array<string, 6> diamond = {".------.", "|X /\\  |", "| /  \\ |", "| \\  / |", "|  \\/ X|", "'------'"};
    array<string, 6> club = {".------.", "|X _   |", "| ( )  |", "|(_x_) |", "|  Y  X|", "'------'"};
    array<string, 6> spade = {".------.", "|X .   |", "| / \\  |", "|(_,_) |", "|  I  X|", "'------'"};
    
    array<string, 6> asciiSuit;
    if(suit == 1){ asciiSuit = heart; }
    else if (suit == 2) { asciiSuit = diamond; }
    else if (suit == 3) { asciiSuit = spade; }
    else { asciiSuit = club; }

    for(int i=0; i<6; i++){ replace(asciiSuit[i].begin(), asciiSuit[i].end(), 'X', lookupValue(value)[0]); } // replace the X on the template card with the char value
    return asciiSuit;
}

BlackjackCard::BlackjackCard(int suit,int value):Card(suit, value){
    // assign a points value to each card
    if(value <= 9){ this->points = value; } // for A-9, each card value is worth the same in points
    else if(value >= 10){ this->points = 10; } // if a picture card (10, J, Q, K), points are worth 10
}

int BlackjackCard::getPoints(){ return points; }