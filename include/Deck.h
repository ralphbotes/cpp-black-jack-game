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
        Deck() {
            for (const string& l_suit : suits) {
                for (const string& l_rank : ranks) {
                    Card card(l_suit,l_rank);
                    cards.push_back(card);
                }
            }
        }

        vector<Card> getDeck() const {
            return cards;
        }

        void restack() {
            cards.clear();
            for (const string &l_suit : suits) {
                for (const string &l_rank : ranks) {
                    Card card(l_suit,l_rank);
                    cards.push_back(card);
                }
            }
        }

        void removeFromDeck(const Card& a_card) {
            for (int idx = 0; idx < cards.size(); idx++) {
                if (a_card.getSuit() == cards[idx].getSuit() && a_card.getRank() == cards[idx].getRank()) {
                    // Use iterator to erase the element at idx
                    cards.erase(cards.begin() + idx);
                    break;
                }
            }
        }

        void shuffleDeck() {
            // Get current time as a seed
            auto time_seed = chrono::system_clock::now().time_since_epoch().count();
            // Create a random generator with the system time as the seed
            mt19937 g(time_seed);
            // Shuffle the cards using shuffle
            shuffle(cards.begin(), cards.end(), g);
        }

    private:
        vector<Card> cards;
        vector<string> suits = {"Hearts","Spades","Clubs","Diamonds"};
        vector<string> ranks = {"A","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
};

#endif // DECK_H
