// Name: Nima Naimi
// Course: CSS 133
// Date: March 04, 2018
// Assignment 7: Simulations and Probabilities
// Description: Creates a deck of cards. Cards can be drawn from the deck,
// ............ and the deck can be shuffled.

#include "carddeck.h"
#include "time.h"
#include <algorithm>

// creates a deck of cards containing ranks of 1-13 and suits of
// Spades, Clubs, Diamonds, and Hearts
CardDeck::CardDeck() {
    for (int i{1}; i < 14; ++i) {
       Card* cSpades = new Card("Spades", i);
       theDeck.push_back(*cSpades);
       Card* cClubs = new Card("Clubs", i);
       theDeck.push_back(*cClubs);
       Card* cDiamonds = new Card("Diamonds", i);
       theDeck.push_back(*cDiamonds);
       Card* cHearts = new Card("Hearts", i);
       theDeck.push_back(*cHearts);
       delete cSpades;
       delete cClubs;
       delete cDiamonds;
       delete cHearts;
    }
}

// randomly shuffles the deck of cards, reinserting previously drawn cards
void CardDeck::shuffle() {
    while (discarded.size() != 0) {
        theDeck.push_back(discarded.back());
        discarded.pop_back();
    }
    srand(time(NULL));
    random_shuffle(theDeck.begin(), theDeck.end());
}

// draws a card from the deck
Card CardDeck::draw() {
    discarded.push_back(theDeck.back());
    theDeck.pop_back();
    return discarded.back();
}
