#include "Deck.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Card.h"

using namespace std;

// Constructor
Deck::Deck() {
    for (const string& l_suit : suits) {
        for (const string& l_rank : ranks) {
            Card card(l_suit,l_rank);
            cards.push_back(card);
        }
    }
}

// Destructor
Deck::~Deck() {};

// Accessor methods
vector<Card> Deck::getDeck() const {
    return cards;
}

// Mutator methods
void Deck::restack() {
    cards.clear();
    for (const string &l_suit : suits) {
        for (const string &l_rank : ranks) {
            Card card(l_suit,l_rank);
            cards.push_back(card);
        }
    }
}

void Deck::removeFromDeck(const Card& a_card) {
    for (int idx = 0; idx < cards.size(); idx++) {
        if (a_card.getSuit() == cards[idx].getSuit() && a_card.getRank() == cards[idx].getRank()) {
            // Use iterator to erase the element at idx
            cards.erase(cards.begin() + idx);
            break;
        }
    }
}

void Deck::shuffleDeck() {
    // Get current time as a seed
    auto time_seed = chrono::system_clock::now().time_since_epoch().count();
    // Create a random generator with the system time as the seed
    mt19937 g(time_seed);
    // Shuffle the cards using shuffle
    shuffle(cards.begin(), cards.end(), g);
}
