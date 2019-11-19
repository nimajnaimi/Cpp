/**
 * Deck of Cards
 * 52 cards in a Deck
 * Allows you to shuffle them and draw a card
 * shuffle replaces all discarded cards before shuffling
 */

#ifndef ASS7_CARDDECK_H

#define ASS7_CARDDECK_H

#include <vector>
#include "card.h"

class CardDeck {
public:
    // constructor, create 52 cards place them in theDeck
    CardDeck();
    // shuffle cards using random_shuffle from algorithm
    // or another method
    // use srand(time(NULL)); to make sure it is random
    void shuffle();
    // draw a random card
    // since theDeck is a vector get last card
    Card draw();
private:
    // cards in the deck
    vector<Card> theDeck;
    // cards that have been drawn
    // add these back in when shuffle is called
    vector<Card> discarded;
};

#endif //ASS7_CARDDECK_H
