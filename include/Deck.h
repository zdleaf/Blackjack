#ifndef DECK_H
#define DECK_H

#include <iterator>
#include <random>   // std::default_random_engine
#include <algorithm>// std::shuffle
#include <chrono>   // std::chrono::system_clock
#include <memory>   // std::shared_ptr

#include "Cards.h"

template <typename T> // template class to enable decks of multiple different card types
class Deck {
    private: 
        std::vector<std::shared_ptr<T>> deck; // internal representation of the card deck is a vector of shared_ptr's - once created this never changes
        typename std::vector<std::shared_ptr<T>>::iterator topCard; // iterator to the top card in our deck

    public:
        // constructor - generate a 52 card deck of all cards
        Deck(){ 
            deck.reserve(52); // reserve at least space for 52 cards
            for(int i = 1; i <= 4; i++){ // loop through all suits (1-4)
                for(int j = 1; j <= 13; j++){ // loop through all potential cards (1-13)
                    std::shared_ptr<T> card(new T(i, j)); // create a shared_ptr to each card
                    deck.push_back(card); // push card onto our deck
                } 
            }
            topCard = deck.begin(); // start with iterator to the first card in the deck
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
        
        // deal() - return shared_ptr to topCard and increment topCard iterator to the next card
        std::shared_ptr<T> deal() { 
            std::shared_ptr<T> card;
            if(!isEmpty()){ // check if the deck is empty i.e. no more cards in deck to deal
                card = *topCard; 
                ++topCard; // increment the topCard iterator to the next in deck
            } 
            else { return shared_ptr<T>(nullptr); } // if we are at the end of the deck, return a nullptr
            return card;
        }

        // determine whether deck is empty i.e. topCard iterator points off end
        bool isEmpty() const { if (deck.end()-topCard == 0){ return true; } return false; }
        
        // return the amount of cards still left in the deck
        int size() const { return (deck.end()-topCard)+1; }
};


#endif