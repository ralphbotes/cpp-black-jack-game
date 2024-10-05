#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include "Card.h"

using namespace std;

class Deck
{
    public:
        // Constructor
        Deck();
        
        // Destructor
        ~Deck();

        // Accessor methods
        vector<Card> getDeck() const;

        // Mutator methods
        void restack();
        void removeFromDeck(const Card& a_card);
        void shuffleDeck();

    private:
        vector<Card> cards;
        vector<string> suits = {"Hearts","Spades","Clubs","Diamonds"};
        vector<string> ranks = {"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
};

#endif // DECK_H
