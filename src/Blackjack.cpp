#include "include/Blackjack/Blackjack.h"

// constructor
Blackjack::Blackjack(){
    deck = new Deck<BlackjackCard>(); // create a deck of cards
    
    addPlayersUI(); // prompt for the number of human players
    addCPUPlayer(); // add the dealer/CPU player
    initialiseScores();
}

// de-constructor
Blackjack::~Blackjack(){
    delete deck; // delete our deck of cards
    for( Player* p: playerVec){ delete p; }; // delete all our players
}

void Blackjack::addHumanPlayer(){
    Human* player = new Human();
    playerVec.push_back((Player*)player); // upcasting
}

void Blackjack::addPlayersUI(){
    int humanPlayers;
    while(true){
        string input; 
        cout << "Enter the number of human players (1-10): ";
        cin >> input;
        cin.ignore();
        stringstream ss(input); // use stringstream to validate our input
        ss >> humanPlayers;
        if (ss.fail()) { cout << "Invalid input. Please enter a number 1-9" << endl; } // if to int fails for any reason e.g. non-number entered
        else if (humanPlayers > 9 || humanPlayers < 1){ cout << "Invalid input. Please enter a number 1-9" << endl; }
        else { break; }
    }
    for(int i=0;i<humanPlayers;i++){ addHumanPlayer(); }  
}

void Blackjack::addCPUPlayer(){
    CPU* player = new CPU(this);
    dealer = player; // save reference to CPU player/dealer
    playerVec.push_back((Player*)player); // upcasting
}

void Blackjack::initialiseScores(){
   for ( Player* p: playerVec){
       scoreMap.insert({p, 0}); // initialise the scores for all players to 0
   };
};

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
    cout << "               Welcome to Blackjack!" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << " - Over 21 = BUST" << endl;
    cout << " - Dealer twists until they have a hand higher than the player" << endl;
    cout << "   or busts" << endl;
    cout << " - Maximum 5 cards in a hand" << endl;
    cout << "---------------------------------------------------------------" << endl;
  
    while(!gameOver){ currentRound++; gameOver = playLoop(); } // run playLoop() until the game is won
    if(gameOver){ playAgain(); } // if we've won, display play again dialog
}

bool Blackjack::playLoop(){
    cout << "                     ROUND " << currentRound << endl;
    cout << "---------------------------------------------------------------" << endl;
    bool livePlayers = false; // keep track of if there are human players with hands that are not bust, as CPU will not need to draw further cards
    for(Player* p: playerVec){
        p->displayFullHand();
        if (p != dealer){  // if human player
            // polymorphic method playLoop() is different for CPU/Human players - returns false if bust, true if not bust
            if(p->playLoop(deck)){ livePlayers = true; } // if any of the player hands is not bust, set livePlayers to true
        } 
        else if (p == dealer && livePlayers == true) { p->playLoop(deck); } // if CPU player and there are live players
        else { break; } // otherwise all players have bust - CPU does not need to play
    }
    determineWinner();
    return true;
}

// loop through the player vector to determine the player with the winning hand
void Blackjack::determineWinner(){
    roundWinners.push_back(""); // insert a new element in roundWinners vector to store winner names
    cout << endl;
    for(Player* p: playerVec){
        if(p != dealer){ // for all human players
            if(!p->bust() && !dealer->bust()){ // where player and dealer have not bust
                if(p->handTotal() > dealer->handTotal()){ cout << p->getName() << " WINS!" << endl; incrementStats(p); } // player has more points than dealer
                else{ cout << p->getName() << " loses!" << endl; incrementStats(dealer); } 
            } else if(!p->bust() && dealer->bust()){ cout << p->getName() << " WINS!" << endl; incrementStats(p); } // player has not bust, but dealer has
            else if (p->bust()) { cout << p->getName() << " loses!" << endl; incrementStats(dealer); } // otherwise player has bust
        }
    }
}

void Blackjack::incrementStats(Player* p){
    scoreMap[p]++; roundWinners[currentRound-1] += p->getName() + " ";
}

void Blackjack::displayStats(){
    cout << "\nStatistics: " << endl;
    cout << "---------------------" << endl;
    for(const auto &scorePair : scoreMap){
        cout << scorePair.first->getName() << ": " << scorePair.second << endl;
    }
    cout << "---------------------" << endl;
    for(int i = 0; i < currentRound; i++){
        cout << "Round " << i+1 << ": " << roundWinners[i] << endl;
    }
    cout << "---------------------" << endl;
}

int Blackjack::highestScore(){ // get the highest score out of all players
    int highestScore = 0;
    for(Player* p: playerVec){
        if(p != dealer && p->handTotal() > highestScore && p->handTotal() <= 21){ // for all human players
            highestScore = p->handTotal();
        }
    }
    return highestScore;
}

void Blackjack::playAgain(){
    cout << "\nDo you want to play again?" << endl;
    cout << "Press \"y\" for yes, or anything else to quit" << endl;
    string input;
    cin >> input;
    cin.ignore();
    if (input == "y") { newGame(); }
    else { displayStats(); exit(0); }
    
}