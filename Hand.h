//
// Created by administrator on 4/3/25.
//

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"
using namespace std;

class Hand {
private:
    vector<Card> m_hand;

public:
    Hand();
    void clear_hand();
    void operator+=(Card);
    Card displayCard(int);
    int getPoints();
    int cardCount();
};

#endif //HAND_H