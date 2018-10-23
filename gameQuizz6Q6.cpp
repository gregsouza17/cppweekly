#include <iostream>
#include "cardsQuizz6Q6.h"
#include <array>
#include <cstdlib>
#include <ctime>

typedef std::array<card, 52> deck;

void fillDeck ( deck &D);
void printDeck( deck &D);
void shuffle  ( deck &D);
int getCardValue( card &c);
void playBlackJack( deck &D);

int main(void){
  deck D;

  fillDeck(D);

  playBlackJack(D);
  


}

void fillDeck( deck &D){
  //Given a Deck (as reference) fills each of the 52
  // cards with a different one
  
  int card = 0;
  
  for(suit s=0; s < suits::MAX_SUITS; s++){
    for(rank r=0; r< ranks::MAX_RANKS; r++){
      
      D[card].r = static_cast<ranks> (r);
      D[card].s = static_cast<suits> (s);
      
      card++;
    } //end rank loop
  } //end suit loop
  
}

void printDeck( deck &D){
  //Given a deck (as reference) prints it
  
  for(card c : D)
     std::cout << c.cardCode() << "   ";
  
}

void shuffle  ( deck &D){

  for(int i = 0; i<52; i++){

    swapCard(D[i], D[std::rand()%(53)]);

  }
    

}

int getCardValue( card &c){

  
  if( c.r < ranks::Ten)
    return static_cast<int> (c.r+2);
  else if (c.r == ranks::Ace)
    return 11;
  else
    return 10;
  
    
}

//Playing part


void playBlackJack( deck  &D){
  
  int playerScore(0), dealerScore(0);
  card *cardPtr=&D[0];



  

}
