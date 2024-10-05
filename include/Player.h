#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>
#include <string>

class Player {
    public:
        // Constructor
        Player(string p_name);

        // Destructor
        ~Player();

        // Accessor methods
        string getName() const;
        int getGamesWon() const;
        int getGamesLost() const;
        int getDeckValue() const;
        void currentHand(bool a_dealer=false);

        // Mutator methods
        void setGamesWon();
        void setGamesLost();
        void addCard(Card card);
        void clearHand();

    private:
        string name;
        int games_won, games_lost;
        vector<Card> cards;
};

#endif // PLAYER_H
