#include "../include/Cards.h"

Card::Card(int suit, int value){
    this->suit = suit;
    this->value = value;
    // std::cout << "Created card " << returnValue(value) << returnSuit(suit) << endl;
}

string Card::toStr() const {
    return lookupValue(value) + lookupSuit(suit);
}

int Card::getSuit() const { return suit; }
int Card::getValue() const { return value; }
string Card::getSuitStr() const { return lookupSuit(getSuit()); }
string Card::getValueStr() const { return lookupValue(getValue()); }


string Card::lookupSuit(int cSuit){ // static
    switch(cSuit){
        case 1: return "h";
        case 2: return "d";
        case 3: return "s";
        case 4: return "c";
        default: return "invalid suit";
    }
}

string Card::lookupValue(int cVal){ // static
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

int Card::rlookupValue(string cVal){ // reverse lookup (static)
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

array<string, 6> Card::getAscii() const {
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

std::vector<int> Card::inputToCard(){ // static
    vector<int> result = {0,0}; // default 0,0 - signifies error with input
    string input;
    string validatedInput;

    cin >> input;
    cin.ignore();
    if (input == "quit"){ exit(0); }
    stringstream ss(input); // use stringstream to validate our input
    ss >> validatedInput;
    if (ss.fail()) { invalidInput(); return result; } // if to string fails for any reason
    if (validatedInput.length() > 3){ invalidInput(); return result; } // maximum length should be 3, e.g. 10d

    // test first and/or second character are 1-10 e.g. 10d, 4d
    if(getValFromInput(validatedInput) < 10 && getValFromInput(validatedInput) > 1){ // if first character is 1-9
        result[0] = getValFromInput(validatedInput);
    } 
    else if(validatedInput[0] == '1' && validatedInput[1] == '0'){ result[0] = 10; } 
    else if(validatedInput[0] == '1' && validatedInput[1] != '0'){ result[0] = 1; }
    else if(validatedInput[0] == 'T' || validatedInput[0] == 't'){ result[0] = 10; }
    else if(validatedInput[0] == 'A' || validatedInput[0] == 'a'){ result[0] = 1; }
    else if(validatedInput[0] == 'J' || validatedInput[0] == 'j'){ result[0] = 11; }
    else if(validatedInput[0] == 'Q' || validatedInput[0] == 'q'){ result[0] = 12; }
    else if(validatedInput[0] == 'K' || validatedInput[0] == 'k'){ result[0] = 13; }
    else { invalidInput(); return result; }

    // test if second or third character is a suit: h,d,s,c
    int i;
    if(validatedInput[0] == '1' && validatedInput[1] == '0'){ i = 2; } // if it's a 10, we want to test the third character instead
    else { i = 1; }

    if      (validatedInput[i] == 'h' || validatedInput[i] == 'H'){ result[1] = 1; }
    else if (validatedInput[i] == 'd' || validatedInput[i] == 'D'){ result[1] = 2; }
    else if (validatedInput[i] == 's' || validatedInput[i] == 'S'){ result[1] = 3; }
    else if (validatedInput[i] == 'c' || validatedInput[i] == 'C'){ result[1] = 4; }
    else { invalidInput(); return result; }

    return result; // if we've missed any of the above conditions, return <0,0>
}

void Card::invalidInput(){ // static 
    cout << "Invalid input - please enter a card in the following format: 3h, Qd etc" << endl; 
}

int Card::getValFromInput(string &input, int charsToProcess/* = 1 */){ // static
    int value;
    stringstream ss(input.substr(0,charsToProcess));
    ss >> value;
    if (ss.fail()) { return 0; } // if we input a string for example
    return value;
}

BlackjackCard::BlackjackCard(int suit,int value):Card(suit, value){
    // assign a points value to each card
    if(value <= 9){ this->points = value; } // for A-9, each card value is worth the same in points
    else if(value >= 10){ this->points = 10; } // if a picture card (10, J, Q, K), points are worth 10
}

int BlackjackCard::getPoints() const { return points; }