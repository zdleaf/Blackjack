#ifndef DECK_H
#define DECK_H

#include <iterator>
#include <random>   // std::default_random_engine
#include <algorithm>// std::shuffle
#include <chrono>   // std::chrono::system_clock
#include <memory>   // std::shared_ptr

#include "Cards.h"

//using namespace std;

// template class to enable having decks of different Card types

// implement a stack using std::vector
// we can shuffle using std::shuffle
// use shared ptrs for the cards

template <typename T>
class Deck {
    private: 
        std::vector<std::shared_ptr<T>> deck; // internal representation of the card deck is a stack implemented using vector - once created this never changes
        typename std::vector<std::shared_ptr<T>>::iterator topCard; // iterator to the top card in our deck

    public:
        // constructor - generate a 52 card deck of all cards
        Deck(){ 
            deck.reserve(52); // reserve at least space for 52 cards
            for(int i = 1; i <= 4; i++){ // loop through all suits (1-4)
                for(int j = 1; j <= 13; j++){ // loop through all potential cards (1-13)
                    std::shared_ptr<T> card(new T(i, j)); // create a shared_ptr to each card
                    deck.push_back(card); // push onto our stack
                } 
            }
            topCard = deck.begin(); // iterator to the first card in the deck
        }
        
        // deconstructor
        ~Deck(){
            // using shared_ptr so manual memory management/deletion of cards not required
        }

        void shuffle(){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
            topCard = deck.begin(); // set the iterator back to the beginning
        }
        
        // DEAL - return topCard and increment topCard iterator to the next card
        std::shared_ptr<T> deal() { 
            std::shared_ptr<T> card = *topCard;
            if(topCard == deck.end()){ return nullptr; } // if we are at the end of the deck, return nullptr
            else{ ++topCard; } // otherwise increment our iterator to point to the next card
            return card;
        }

        // determine whether Stack is empty
        bool isEmpty() const { return deck.empty(); }
        
        // return size of the deck
        size_t size() const { return deck.size(); }
};


#endif