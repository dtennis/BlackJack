//
// Created by administrator on 4/3/25.
//

#include "Game.h"
using namespace std;


Game::Game() {


}


Hand Game::getPlayerHand(Deck &deck, Hand &hand) {
   hand += deck.dealCard();
   hand += deck.dealCard();
   return hand;
}


Hand Game::getDealerHand(Deck &deck, Hand &hand) {
   hand += deck.dealCard();
   hand += deck.dealCard();
   return hand;
}


void Game::displayCards(Hand hand, string name) {
   if (name== "Dealer") {
       cout << "Dealers's Cards: "<<endl;
   }
   else {cout << name << "'s Cards: "<<endl;}
   for (int i = 0; i < hand.cardCount(); i++) {
       cout << hand.displayCard(i).getCard() << endl;
   }
   cout << endl;
}


void Game::displayRound() {
   cout << "Dealer's Show Card: "<<endl;
   cout << DealerHand.displayCard(0).getCard() << endl<<endl;
   displayCards(playerHand, "Player");
}


void Game::playGame() {
   cout << "###########################"<<endl;
   cout << "#  The Game of Blackjack  #"<<endl;
   cout << "###########################"<<endl<<endl;


   char playAgain = 'y';


   while (playAgain == 'y' || playAgain == 'Y') {
       m_deck = Deck();
       playerHand.clear_hand();
       DealerHand.clear_hand();


       playerHand = getPlayerHand(m_deck, playerHand);
       DealerHand = getDealerHand(m_deck, DealerHand);


       displayRound();




       char choice;
       do {
           cout << "hit or stand? (h/s): ";
           cin >> choice;
           if (choice == 'h' || choice == 'H') {
               playerHand += m_deck.dealCard();
               cout << endl<<"Your Cards: "<<endl;
               for (int i = 0; i < playerHand.cardCount(); i++) {
                   cout << playerHand.displayCard(i).getCard() << endl;
               }
               cout << endl;
           }
           //test
           //cout << playerHand.getPoints();
       } while ((choice == 'h' || choice == 'H') && playerHand.getPoints() < 21);




       if (playerHand.getPoints() <= 21) {
           while (DealerHand.getPoints() < 17) {
               DealerHand += m_deck.dealCard();
           }
       }




       cout << "Dealer's Cards: "<<endl;
       for (int i = 0; i < DealerHand.cardCount(); i++) {
           cout << DealerHand.displayCard(i).getCard() << endl;
       }
       cout << endl;


       cout << "Your Points:     " << playerHand.getPoints() << endl;
       cout << "Dealer's Points: " << DealerHand.getPoints() << endl;


       int playerPoints = playerHand.getPoints();
       int dealerPoints = DealerHand.getPoints();


       if (playerPoints > 21) {
           cout << "Sorry. You busted. You lose."<<endl;
       }else if (playerPoints < dealerPoints && dealerPoints ==21 ) {
           cout <<"Dealer has Blackjack. You lose."<<endl;
       }else if (playerPoints > dealerPoints && playerPoints ==21 ) {
           cout <<"Blackjack! You win!"<<endl;
       }else if (playerPoints == dealerPoints && playerPoints ==21 ) {
           cout <<"Dang, dealer has blackjack too. You push."<<endl;
       }else if (dealerPoints > 21) {
           cout << "Yay! The dealer busted. You win!"<<endl;
       } else if (playerPoints > dealerPoints) {
           cout << "Hooray! You win!"<<endl;
       } else if (playerPoints < dealerPoints) {
           cout << "Sorry. You lose."<<endl;
       }
       else if(playerPoints == dealerPoints) {
           cout << "It's a tie!, you push"<<endl;
       }else {
           cout<< "I'm not sure what happened."<<endl;
       }


       cout << endl<<"play another round? (y/n): ";
       cin >> playAgain;
       cout << endl;
   }


   cout << "Thanks for playing!"<<endl;
}
