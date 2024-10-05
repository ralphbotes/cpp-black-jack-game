#ifndef CARD_H
#define CARD_H
#include <string>
#include <vector>

using namespace std;

class Card {
    public:
        // Constructor
        Card(string a_suit, string a_rank);

        // Destructor
        ~Card();

        // Accessor methods
        string getSuit() const;
        string getRank() const;
        int getValue() const;

        // Mutator methods
        friend ostream& operator<<(ostream& os, const Card& card);

    private:
        string card_suit, card_rank;
        int card_value;

        vector<string> tier_1 = {"A"};
        vector<string> tier_2 = {"Jack","Queen","King"};
        vector<string> tier_3 = {"2","3","4","5","6","7","8","9","10"};
};

#endif // CARD_H
