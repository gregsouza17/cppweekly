#include <iostream>
#include "cardsQuizz6Q6.h"
#include <array>
#include <cstdlib>
#include <ctime>

typedef std::array<card, 52> deck;

//Deck and Card FUnctions
void fillDeck ( deck &D);
void printDeck( deck &D);
void shuffle  ( deck &D);
int getCardValue( card &c);

//Playing BlackJack Function
char getPlayerChoice();
bool playBlackJack( deck &D);

int main(void){
  deck D;

  fillDeck(D);
  shuffle(D);
  bool b;
  
  b = playBlackJack(D);

  if(b){
    std::cout<<"Congrats you won \n";
  }
  else
    std::cout << "You loossst \n";
  
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

char getPlayerChoice(){

  char s;
  std::cout << "Enter s to stand, h to hit : ";
  std::cin >> s;
  while(std::cin.fail() || (s!='h' && s!='s') ){
    std::cout << "\n s or h :";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> s;
  }

  return s;
  
}

bool playBlackJack( deck  &D){
  
  int playerScore(0), dealerScore(0);
  card *cardPtr=&D[0];

  std::cout << "The dealer deal himself the first card: " <<
    (*cardPtr).cardCode() << std::endl;

  dealerScore += getCardValue(*cardPtr++);
  
  //Add the card value to the dealer score, and incremets
  //the deck pointer, going to the next card.

  std::cout <<"You are dealt two cards " << (*cardPtr).cardCode() <<
    std::endl;
   playerScore += getCardValue(*cardPtr++);
   std::cout << "And " << (*cardPtr).cardCode() << std::endl;
   playerScore += getCardValue(*cardPtr++);


   //Create gameloop acoordingto ruleszz
   char pChoice;
   while(true){
     std::cout<< "Your score is: " << playerScore <<
       "\n The Dealer Score is: " << dealerScore << std::endl;

     if(playerScore > 21){
       std::cout <<" You Busted!" << std::endl;
       return false;
     }
    
     pChoice = getPlayerChoice();
     
     if(pChoice == 's')
       break;

     std::cout << "You are being dealt a " <<(*cardPtr).cardCode() <<
       std::endl;

     playerScore+= getCardValue(*cardPtr++);
     
   }
   
   while(dealerScore < 17){
     std::cout << "The dealer deal himself a " << (*cardPtr).cardCode()
	       << " he now has ";
     dealerScore+= getCardValue(*cardPtr++);
     std::cout << dealerScore << " points" << std::endl;
   }

   if(dealerScore > 21){
     std::cout<< "You busted " << std::endl;
     return true;
   }

   
   return (playerScore > dealerScore); 
   
}
