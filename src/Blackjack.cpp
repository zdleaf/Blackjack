#include "include/Blackjack/Blackjack.h"

/* DYNAMIC DOWNCAST CODE

        if (auto dp = dynamic_cast<Human*>(p)) { // dynamically downcast from Player to Human (returns nullptr if Player cannot be downcast)
            dp->displayFullHand(); 
            dp->playLoop(deck); // call the polymorphic Human
        } 
        else if (auto dp2 = dynamic_cast<CPU*>(p)) { dp2->displayHiddenHand(); } */

// constructor
Blackjack::Blackjack(){
    deck = new Deck<BlackjackCard>(); // create a deck of cards
    
    // add the players
    addHumanPlayer();
    addHumanPlayer();
    addCPUPlayer(); 
}

// de-constructor
Blackjack::~Blackjack(){
    cout << "Deconstructor called" << endl;
    delete deck; // delete our deck of cards
    for( Player* p: playerVec){ delete p; }; // delete all our players
}

void Blackjack::addHumanPlayer(){
    Human* player = new Human();
    playerVec.push_back((Player*)player); // upcasting
}

void Blackjack::addCPUPlayer(){
    CPU* player = new CPU();
    playerVec.push_back((Player*)player); // upcasting
}

void Blackjack::newGame(){
    deck->shuffle(); // shuffle the deck

    for( Player* p: playerVec){ p->clearHand(); } // clear any previous hands for each player
    // deal two cards to each player in turn
    for( Player* p: playerVec){ p->addCard(deck->deal()); }
    for( Player* p: playerVec){ p->addCard(deck->deal()); }

    gameLoop();
}

void Blackjack::gameLoop(){
    bool gameOver = false;
    cout << "---------------------------------------------------------------" << endl;
    cout << "               Welcome to the Blackjack!" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Type \"quit\" to exit at any time" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << " - Dealer twists until they have a hand higher than the player or busts" << endl;
    cout << " - Over 21 = BUST" << endl;
    cout << " - Maximum 5 cards in a hand" << endl;
    cout << " - In case of draw, the player with more cards in their hand wins" << endl;
    cout << "---------------------------------------------------------------" << endl;
  
    while(!gameOver){ gameOver = playLoop(); } // run playLoop() until the game is won
    if(gameOver){ playAgain(); } // if we've won, display play again dialog
}

bool Blackjack::playLoop(){
    bool livePlayers = false; // keep track of if there are human players with hands that are not bust, as CPU will not need to draw further cards
    for(Player* p: playerVec){
        p->displayFullHand();
        if (auto dp1 = dynamic_cast<Human*>(p)){  // if human player
            livePlayers = p->playLoop(deck); // polymorphic method playLoop() is different for CPU/Human players 
        } 
        else if (auto dp2 = dynamic_cast<CPU*>(p) && livePlayers == true) { p->playLoop(deck); } // if CPU player and there are live players
        else { break; } // otherwise all players have bust - CPU does not need to play
    }
    Player* winner = determineWinner();
    cout << winner->getName() << " WINS!" << endl;
    return true;
}

// loop through the player vector to determine the player with the winning hand
Player* Blackjack::determineWinner(){
    int highestTotal = 0; // store the highest total hand (that's 21 or less)
    Player* winner; // store the player with the highest total
    for(Player* p: playerVec){
        if(p->handTotal() < 21 && p->handTotal() > highestTotal){
            winner = p; highestTotal = p->handTotal();
        }
    }
    return winner;
}

void Blackjack::playAgain(){
    cout << "\nDo you want to play again?" << endl;
    cout << "Press \"y\" for yes, or anything else to quit" << endl;
    string input;
    cin >> input;
    cin.ignore();
    if (input == "y") { newGame(); }
    exit(0);
}