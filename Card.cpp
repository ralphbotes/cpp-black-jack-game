#include "Card.h"
#include <string>
#include <algorithm>  // For find
#include <iostream>

using namespace std;

// Constructor
Card::Card(string a_suit, string a_rank) : card_suit(a_suit), card_rank(a_rank) {
    if (find(tier_1.begin(), tier_1.end(), a_rank) != tier_1.end()) {
        card_value = 11;  // Ace is worth 11 points
    } else if (find(tier_2.begin(), tier_2.end(), a_rank) != tier_2.end()) {
        card_value = 10;  // Jack, Queen, King are worth 10 points
    } else if (find(tier_3.begin(), tier_3.end(), a_rank) != tier_3.end()) {
        card_value = stoi(a_rank);  // Convert rank to integer for number cards
    }
}

// Destructor
Card::~Card() {};

// Accessor methods
string Card::getSuit() const {
    return card_suit;
}

string Card::getRank() const {
    return card_rank;
}

int Card::getValue() const {
    return card_value;
}

// Mutator methods
ostream& operator<<(ostream& os, const Card& card) {
    os << card.getRank() << " of " << card.getSuit() << endl;
}
