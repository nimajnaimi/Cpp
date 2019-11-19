// Name: Nima Naimi
// Course: CSS 133
// Date: March 04, 2018
// Assignment 7: Simulations and Probabilities
// Description: Simulates drawing cards from the deck and displays
// ............ the analytical probability of drawing the particular
// ............ set of cards

#include <iostream>
#include "card.h"
#include "carddeck.h"

using namespace std;

// Chances of drawing two of a kind
// 1st card is what it is, second card has to match it
// Chances of drawing the same rank 3/51
void simulation2OfAKind() {
    CardDeck deck;
    int runs{1000};
    int success{0};
    double analyticalResult{(3.0f / 51)};

    for (int i{0}; i < runs; ++i) {
        deck.shuffle();
        Card c1 = deck.draw();
        Card c2 = deck.draw();
        cout << "Got: " << c1 << ", " << c2 << endl;
        if (c1.getRank() == c2.getRank())
            ++success;
    }
    double experimentalResult{static_cast<double>(success) / static_cast<double>(runs)};
    double difference{analyticalResult - experimentalResult};
    cout << "simulation2OfAKind: " << success << "/" << runs << " = ";
    cout << (experimentalResult * 100) << "%" << endl;
    cout << "Difference to analytical result is " << difference << endl;
}

// Chances of drawing 1 red card is 26/52
// Chances of drawing a second red card is 25/51
// Combined is 26/52 * 25/51 = 650/2652 = 0.245098
void simulation2Red() {
    CardDeck deck;
    int runs{1000};
    int success{0};
    double analyticalResult{(26.0f * 25) / (52 * 51)};

    for (int i{0}; i < runs; ++i) {
        deck.shuffle();
        Card c1 = deck.draw();
        Card c2 = deck.draw();
        cout << "Got: " << c1 << ", " << c2 << endl;
        if (c1.isRed() && c2.isRed())
            ++success;
    }
    double experimentalResult{static_cast<double>(success) / static_cast<double>(runs)};
    double difference{analyticalResult - experimentalResult};
    cout << "simulation2Red: " << success << "/" << runs << " = ";
    cout << (experimentalResult * 100) << "%" << endl;
    cout << "Difference to analytical result is " << difference << endl;
}

// chances of drawing 2 cards that follow each other (e.g. 3 of Hearts and 2 of Hearts)
// cards may be drawn at any order
void simulation2InSeries() {
    CardDeck deck;
    int runs{1000};
    int success{0};
    double analyticalResult{0};

    for (int i{0}; i < runs; ++i) {
        deck.shuffle();
        Card c1 = deck.draw();
        Card c2 = deck.draw();
        cout << "Got: " << c1 << ", " << c2 << endl;
        if ((c1.getRank() - c2.getRank() == -1) ||
            (c1.getRank() - c2.getRank() == 1) ||
            (c1.getRank() - c2.getRank() == 12) ||
            (c1.getRank() - c2.getRank() == -12))
            ++success;
    }
    double experimentalResult{static_cast<double>(success) / static_cast<double>(runs)};
    double difference{analyticalResult - experimentalResult};
    cout << "simulation2InSeries: " << success << "/" << runs << " = ";
    cout << (experimentalResult * 100) << "%" << endl;
    cout << "Difference to analytical result is " << difference << endl;
}

// chances of drawing 2 cards of the same rank when you draw 3 cards from the deck
void simulation2OfAKindOutOf3() {
    CardDeck deck;
    int runs{1000};
    int success{0};
    double analyticalResult{0};

    for (int i{0}; i < runs; ++i) {
        deck.shuffle();
        Card c1 = deck.draw();
        Card c2 = deck.draw();
        Card c3 = deck.draw();
        cout << "Got: " << c1 << ", " << c2 << ", " << c3 << endl;
        if ((c1.getRank() == c2.getRank()) ||
            (c1.getRank() == c3.getRank()) ||
            (c2.getRank() == c3.getRank()))
            ++success;
    }
    double experimentalResult{static_cast<double>(success) / static_cast<double>(runs)};
    double difference{analyticalResult - experimentalResult};
    cout << "simulation2OfAKindOutOf3: " << success << "/" << runs << " = ";
    cout << (experimentalResult * 100) << "%" << endl;
    cout << "Difference to analytical result is " << difference << endl;
}

int main() {
    simulation2Red();
    simulation2OfAKind();
    //simulation2InSeries();
    //simulation2OfAKindOutOf3();
    return 0;
}
