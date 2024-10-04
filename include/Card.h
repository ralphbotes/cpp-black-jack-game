#ifndef CARD_H
#define CARD_H
#include <string>
#include <algorithm>  // For find
#include <list>

using namespace std;

class Card
{
    public:
        Card(string a_suit, string a_rank) : card_suit(a_suit), card_rank(a_rank) {
            if (find(tier_1.begin(), tier_1.end(), a_rank) != tier_1.end()) {
                card_value = 11;  // Ace is worth 11 points
            } else if (find(tier_2.begin(), tier_2.end(), a_rank) != tier_2.end()) {
                card_value = 10;  // Jack, Queen, King are worth 10 points
            } else if (find(tier_3.begin(), tier_3.end(), a_rank) != tier_3.end()) {
                card_value = stoi(a_rank);  // Convert rank to integer for number cards
            }
        }

        string getSuit() const {
            return card_suit;
        }
        string getRank() const{
            return card_rank;
        }
        int getValue() const{
            return card_value;
        }

        friend ostream& operator<<(ostream& os, const Card& card) {
            os << card.getRank() << " of " << card.getSuit() << endl;
        }

    private:
        string card_suit, card_rank;
        int card_value;

        list<string> tier_1 = {"A"};
        list<string> tier_2 = {"Jack","Queen","King"};
        list<string> tier_3 = {"2","3","4","5","6","7","8","9","10"};
};

#endif // CARD_H
