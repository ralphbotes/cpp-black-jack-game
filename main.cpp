#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Deck.h"
#include "Card.h"
#include "Player.h"

using namespace std;

void typeOutText(const string& text);

void startNewGame();

void fakeSleep(string start_text, string end_text);

void initiateGame(Deck deck);

int main()
{
    // Start screen
    startNewGame();

    // Create a deck
    Deck my_deck;
    string player_name;

    /* View Deck
        vector<Card> cards = my_deck.getDeck();
        for (const Card& card : cards) {
            cout << card;
        }
    */

    // Create a dealer
    Player dealer("Dealer Dave");
    // Create a player
    cout << "What do we call you? ";
    cin >> player_name;
    Player player(player_name);
    cout << endl << "Please to meet you " << player_name << endl << endl;

    // TODO : GAME PLAY
    bool GAME_ON = 1;
    bool SUB_GAME = 1;
    int PLAYER_SCORE = 0;
    int DEALER_SCORE = 0;
    vector<Card> cards;
    string ACTION, quit;

    do {
        // TODO : Suffle the deck
        fakeSleep("Suffle deck", "Deck suffled!");
        my_deck.shuffleDeck();

        cout << "\n" << endl;

        do {
            system("CLS");
            cards = my_deck.getDeck();

            if (player.getDeckValue() != 0) {
                cout << "Current hand value: " << PLAYER_SCORE << endl;
                cout << "Player hand:" << endl;
                player.currentHand();

                cout << "\nDealer hand:" << endl;
                dealer.currentHand(true);
                cout << "\n" << endl;

                // Check if Player bust
                if (PLAYER_SCORE == 21) {
                    cout << "Player WON!" << endl;
                    cout << "Congratulations " << player.getName() << "!" << endl;
                    player.setGamesWon();
                    SUB_GAME = 0;
                } else if (PLAYER_SCORE > 21) {
                    cout << "Player BUSTED!" << endl;
                    cout << "Better luck next time " << player.getName() << endl;
                    player.setGamesLost();
                    SUB_GAME = 0;
                } else if (ACTION == "s" || ACTION == "S") {
                    cout << "Player STANDING. Waiting for dealer..." << endl;
                    DEALER_SCORE = dealer.getDeckValue();
                    cout << "Dealer hand:" << endl;
                    cout << "Dealer hand value: " << DEALER_SCORE << endl;
                    if (DEALER_SCORE < 17) {
                        Card new_card = cards[0];
                        cout << "Card: " << new_card;
                        dealer.addCard(new_card);
                        my_deck.removeFromDeck(new_card);
                    } else if (DEALER_SCORE >= 17 && DEALER_SCORE <= 21) {
                        if (DEALER_SCORE < PLAYER_SCORE) {
                            cout << "Player WON!" << endl;
                            cout << "Congratulations " << player.getName() << "!" << endl;
                            player.setGamesWon();
                            SUB_GAME = 0;
                        } else {
                            cout << "Dealer WON!" << endl;
                            cout << "Better luck next time " << player.getName() << endl;
                            player.setGamesLost();
                            SUB_GAME = 0;
                        }
                    } else {
                        cout << "Dealer BUSTED!" << endl;
                        cout << "Congratulations " << player.getName() << "!" << endl;
                        player.setGamesWon();
                        SUB_GAME = 0;
                    }
                } else {
                    cout << "H: to hit" << endl;
                    cout << "S: to stay" << endl;
                    cout << "Q: to quit" << endl;
                    cin >> ACTION;

                    if (ACTION == "h" || ACTION == "H") {
                        Card new_card = cards[0];
                        cout << "Card: " << new_card;
                        player.addCard(new_card);
                        my_deck.removeFromDeck(new_card);
                        PLAYER_SCORE = player.getDeckValue();
                    } else if (ACTION == "q" || ACTION == "Q") {
                        SUB_GAME = 0;
                    }
                }
                this_thread::sleep_for(chrono::seconds(2));
            } else {
                player.addCard(cards[0]);
                player.addCard(cards[1]);
                my_deck.removeFromDeck(cards[0]);
                my_deck.removeFromDeck(cards[1]);
                PLAYER_SCORE = player.getDeckValue();

                dealer.addCard(cards[2]);
                dealer.addCard(cards[3]);
                my_deck.removeFromDeck(cards[2]);
                my_deck.removeFromDeck(cards[3]);
            }
        } while (SUB_GAME);

        // Allow quit to end game
        cout << "\n" << "Games WON: " << player.getGamesWon() << endl;
        cout << "Games LOST: " << player.getGamesLost() << endl;
        cout << "A to play again or Q to Exit main game: ";
        cin >> quit;
        if (quit == "q" || quit == "Q") {
            GAME_ON = 0;
        } else if (quit == "a" || quit == "A") {
            cout << "\n" << endl;
            fakeSleep("Clear Player and Dealer hands", "Cleared!");
            player.clearHand();
            dealer.clearHand();

            fakeSleep("Restack deck", "Deck restacked!");
            my_deck.restack();

            fakeSleep("Reset game", "Reset completed!");
            SUB_GAME = 1;
            ACTION = "";
            system("CLS");
        }
    } while (GAME_ON);

    return 0;
}

void typeOutText(const string& text) {
    for (char c : text) {
        if (c == '%') {
            // Print a newline for '%'
            cout << endl;
        } else {
            cout << c;
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(5));
        }
    }
}

void startNewGame() {
    string game_text = "============ NEW GAME ===============%Welcome to Black Jack%Let's start a new game!%Follow the prompts to play%If you want to quit, enter q or Q and enter at any time%Good Luck!%=====================================%%";
    typeOutText(game_text);
}

void fakeSleep(string start_text, string end_text) {
    cout << start_text;
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << end_text << endl;
}
