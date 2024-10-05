#include "Player.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructor
Player::Player(string p_name) : name(p_name), games_lost(0), games_won(0) {}

// Destructor
Player::~Player() {};

// Accessor methods
string Player::getName() const {
    return name;
}

int Player::getGamesWon() const {
    return games_won;
}

int Player::getGamesLost() const {
    return games_lost;
}

int Player::getDeckValue() const {
    int value = 0;
    int aces = 0;

    for(Card card : cards) {
        if (card.getRank() == "A") {
            aces++;
        } else {
            value += card.getValue();
        }
    }

    if (aces > 0 && value < 22) {
        // TODO : For now only add a 1 for each ACE
        int curr_value = value + aces;
        if (curr_value == 21) {
            value = curr_value;
        } else if (curr_value < 21 && curr_value > 11) { // Up to this point, all aces valued at 1 has been added
            // Start working through aces, adding 10 for each one then checking value to determine bust or valid
            for (int i = aces; aces > 0; aces--) {
                // 1 already added for each ace, so add 10 for each loop to make up 11, then check validity
                curr_value += 10;
                if (curr_value > 21) {
                    // Remove the 10 added and return the value
                    value = curr_value - 10;
                    break;
                } else if (curr_value == 21) {
                    // BLACK JACK
                    value = 21;
                    break;
                } else if (curr_value > 11 && curr_value < 21) {
                    // BUST or can stay
                    value = curr_value;
                    break;
                }
            }
        } else {
            value += aces;
        }
    }

    return value;
}

void Player::currentHand(bool a_dealer) {
    for (int idx = 0; idx < cards.size(); idx++) {
        if (a_dealer && idx == 0) {
            cout << "Hidden card" << endl;
            continue;
        }
        cout << cards[idx];
    }
}

// Mutator methods
void Player::setGamesWon() {
    games_won++;
}

void Player::setGamesLost() {
    games_lost++;
}

void Player::addCard(Card card) {
    cards.push_back(card);
}

void Player::clearHand() {
    cards.clear();
}
