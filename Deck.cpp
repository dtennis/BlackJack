//
// Created by administrator on 4/3/25.
//

#include "Deck.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <random>
#include <algorithm>


Deck::Deck() {
    //vector<Card> m_cardDeck;
    vector<string> suits {"Hearts", "Diamonds", "Spades", "Clubs"};
    vector<string> ranks {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"  };
    vector<int> values {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            m_cardDeck.push_back(Card (suits[i], ranks[j], values[j]));
        }
    }
    shuffleDeck();
    //Testing the deck object
    for (auto i : m_cardDeck) {
        cout << i.getCard() << endl;
    }

    cout << endl << m_cardDeck.size() << endl;
}

void Deck::shuffleDeck() {
    random_device rd;
    mt19937 gen(rd());
    gen.seed(0); // testing of game
    shuffle(m_cardDeck.begin(), m_cardDeck.end(), gen); //rd = set, gen = random
}

Card Deck::dealCard() {
    Card temp;

    temp = m_cardDeck.back();
    m_cardDeck.pop_back();

    return temp;
}

int Deck::getCount() {
    return m_cardDeck.size();
}

