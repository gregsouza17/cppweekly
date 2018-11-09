#include <iostream>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include "cardClass.h"

//Casting
bool playBlackjack(const Deck deck);
char getPlayerChoice();
//End casting


int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock

  Deck deck;
  deck.shuffleDeck();
  
  if (playBlackjack(deck))
    std::cout << "You win!\n";
  else
    std::cout << "You lose!\n";
 
  return 0;
}



//Card Functions ---------

void Card::printCard() const
{ //Print a card as the following codes (as in the switchs)
  switch (m_rank)
    {
    case RANK_2:		std::cout << '2'; break;
    case RANK_3:		std::cout << '3'; break;
    case RANK_4:		std::cout << '4'; break;
    case RANK_5:		std::cout << '5'; break;
    case RANK_6:		std::cout << '6'; break;
    case RANK_7:		std::cout << '7'; break;
    case RANK_8:		std::cout << '8'; break;
    case RANK_9:		std::cout << '9'; break;
    case RANK_10:		std::cout << 'T'; break;
    case RANK_JACK:		std::cout << 'J'; break;
    case RANK_QUEEN:	        std::cout << 'Q'; break;
    case RANK_KING:		std::cout << 'K'; break;
    case RANK_ACE:		std::cout << 'A'; break;
    default:                  std::cout << 'E'; break; //Error case
    }
 
  switch (m_suit)
    {
    case SUIT_CLUB:	 std::cout << 'C'; break;
    case SUIT_DIAMOND: std::cout << 'D'; break;
    case SUIT_HEART:	 std::cout << 'H'; break;
    case SUIT_SPADE:	 std::cout << 'S'; break;
    default:           std::cout << 'E'; break; //Error case
    }
}
  
  
int Card::getCardValue() const
{ //Return the BlackJack Value of each card
  switch (m_rank)
    {
    case RANK_2:		return 2;
    case RANK_3:		return 3;
    case RANK_4:		return 4;
    case RANK_5:		return 5;
    case RANK_6:		return 6;
    case RANK_7:		return 7;
    case RANK_8:		return 8;
    case RANK_9:		return 9;
    case RANK_10:		return 10;
    case RANK_JACK:		return 10;
    case RANK_QUEEN:	        return 10;
    case RANK_KING:		return 10;
    case RANK_ACE:		return 11;
    default:                    return -1; //Error case
    }
	
  return 0;
}

//End Card Functions --------------
  
//Deck Functions -----------------

void Deck::printDeck(){
  
  for(const auto &card : m_deck)
    {
      card.printCard();
      std::cout << ' ';
    }
  std::cout << '\n';
}


void Deck::shuffleDeck(){

  for(int index = 0; index < 52; ++index)
    {
      int swapIndex = getRandomNumber(0,51);
      swapCard(m_deck[index], m_deck[swapIndex]);
    }

  //After shuffling, we reset the index
  m_cardIndex = 0;
    
}

const Card& Deck::dealCard()
{
  assert(m_cardIndex < 52) ;
  return m_deck[m_cardIndex++];
}
//End Deck Functions ---------

//Black Jack -----------------
char getPlayerChoice()
{
  std::cout << "(h) to hit, or (s) to stand: ";
  char choice;
  do
    {
      std::cin >> choice;
    } while (choice != 'h' && choice != 's');
	
  return choice;
}

bool playBlackjack(Deck deck){

  int playerTotal = 0;
  int dealerTotal = 0;

  dealerTotal += (deck.dealCard()).getCardValue();
  std::cout << "The dealer is showing: " << dealerTotal << '\n';

  playerTotal += (deck.dealCard()).getCardValue();
  playerTotal += (deck.dealCard()).getCardValue();

  while(true){
    
    std::cout << "You have: " << playerTotal << '\n';
    char choice = getPlayerChoice();
    if (choice == 's')
      break;

    playerTotal +=  (deck.dealCard()).getCardValue();


    if(playerTotal>21)
      return false;
    
  }

  while (dealerTotal < 17)
    {
      dealerTotal +=  (deck.dealCard()).getCardValue();
      std::cout << "The dealer now has: " << dealerTotal << '\n';
    }
  
  if (dealerTotal > 21)
    return true;
  
  return (playerTotal > dealerTotal);
  
}
