#ifndef CARD
#define CARD


class Card{

  
public:
  enum CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};
 
enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

private:
  CardRank m_rank;
  CardSuit m_suit;


public:
  
  Card(CardRank rank = RANK_2, CardSuit suit = SUIT_CLUB):
    m_rank(rank), m_suit(suit) {}

  void printCard() const;

  int getCardValue() const;

};



#endif

#ifndef DECK
#define DECK

#include <array>
#include <cassert>

class Deck{

private:
  std::array<Card, 52> m_deck;
  int m_cardIndex;

  //Static Functions
  static void swapCard(Card &a, Card &b){
      
    Card temp = a;
    a = b;
    b = temp;
 
  }

  static int getRandomNumber(int min, int max)
  {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this
    //value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }
  
public:

  Deck(): m_cardIndex(0)
  {
    int card = 0;
    for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
      for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
	{
	  m_deck[card] = Card(static_cast<Card::CardRank>(rank),
			      static_cast<Card::CardSuit>(suit));
	  ++card;
	}
  }

  //Add PrintDeck, getRandomNumber, Swap ; Shuffle
 
  void printDeck();

  void shuffleDeck();

  const Card& dealCard();
  
};


#endif
