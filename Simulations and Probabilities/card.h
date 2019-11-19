/**
 * Card represents a playing card
 * suit can be Spades, Clubs, Hearts, Diamonds
 * rank can be 1-13
 */

#ifndef ASS7_CARD_H
#define ASS7_CARD_H

#include <iostream>

using namespace std;

class Card {
    // printable form - 2 of Clubs
    friend ostream& operator<<(ostream& out, const Card& card);
public:
    // constructor
    Card(const string& suit, int rank);
    // return suit
    string getSuit() const;
    // return rank
    int getRank() const;
    // return true if suit is Diamonds or Hearts
    bool isRed() const;
    // return true if suit is Clubs or Spades
    bool isBlack() const;
private:
    // suit can be Spades, Clubs, Hearts, Diamonds
    string suit;
    // rank is 1-13
    int rank;
};

#endif
