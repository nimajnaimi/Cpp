// Name: Nima Naimi
// Course: CSS 133
// Date: March 04, 2018
// Assignment 7: Simulations and Probabilities
// Description: Creates a card with a suit and rank

#include "card.h"

// Creates a card of the given rank and suit
Card::Card(const string& suit, int rank) : suit{suit}, rank{rank} {
}

// Outputs the rank and suit of the card
ostream& operator<<(ostream& out, const Card& card) {
    if (card.rank < 11) {
        out << card.rank << " of " << card.suit;
    } else if (card.rank == 11) {
        out << "Jack of " << card.suit;
    } else if (card.rank == 12) {
        out << "Queen of " << card.suit;
    } else {
        out << "King of " << card.suit;
    }
    return out;
}

// Returns the suit of the card
string Card::getSuit() const {
    return suit;
}

// Returns the rank of the card
int Card::getRank() const {
    return rank;
}

// Returns true if the card's suit is red, false if not
bool Card::isRed() const {
    return suit == "Hearts" || suit == "Diamonds";
}

// Returns true if the card's suit is black, false if not
bool Card::isBlack() const {
    return suit == "Clubs" || suit == "Spades";
}
