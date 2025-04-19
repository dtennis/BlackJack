//
// Created by administrator on 4/3/25.
//




#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Hand.h"
#include "iostream"
using namespace std;
class Game {
private:
   Deck m_deck;
   Hand playerHand;
   Hand DealerHand;
public:
   Game();
   Hand getPlayerHand(Deck &deck, Hand &hand);
   Hand getDealerHand(Deck &deck, Hand &hand);
   void displayCards(Hand hand, string name);
   void displayRound();
   void playGame();
};


#endif