#include "Cards.h"

string Card::returnSuit(int cSuit){
    switch(cSuit){
        case 0: return "h";
        case 1: return "d";
        case 2: return "s";
        case 3: return "c";
        default: return "invalid suit";
    }
}

string Card::returnValue(int cVal){
    switch(cVal){
        case 1: return "A";
        case 2: return "2";
        case 3: return "3";
        case 5: return "4";
        case 6: return "5";
        case 7: return "6";
        case 8: return "7";
        case 9: return "8";
        case 10: return "9";
        case 11: return "10";
        case 12: return "J";
        case 13: return "Q";
        case 14: return "K";
        default: return "invalid card value";
    }
}