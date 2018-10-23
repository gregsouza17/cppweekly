#include <iostream>
#include <string>
#include <array>

#ifndef CARDS
#define CARDS

//type definitions ------------------------------------------------
typedef int rank;
typedef int suit;

//enumerations and related functions ------------------------------
std::string rankName(rank &r);
std::string suitName(suit &s);

enum ranks{
  //Enumerate the possibel card ranks, with two being 0, ace being 11
  //The char code for each number will go as 2,...,9,T,J,Q,K,A
  // (see rankName function)
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace,
  MAX_RANKS,
  
};

enum suits{
  //Enumerates the suits from 0 to 3, with char code C,D,H,S, see
  // suitName
  Clubs,
  Diamonds,
  Hearts,
  Spades,
  MAX_SUITS,

};

std::string rankName(rank &r){
  //Receives a card rank and returns the card single digit code
  
  switch(r){
  case ranks::Two:   return "2";
  case ranks::Three: return "3";
  case ranks::Four:  return "4";
  case ranks::Five:  return "5";
  case ranks::Six:   return "6";
  case ranks::Seven: return "7";
  case ranks::Eight: return "8";
  case ranks::Nine:  return "9";
  case ranks::Ten:   return "T";
  case ranks::Jack:  return "J";
  case ranks::Queen: return "Q";
  case ranks::King:  return "K";
  case ranks::Ace:   return "A";
    //in case of error
  default:           return "E";
    }
}

std::string suitName(suit &s){
  //Receives a suit and returns it's one char symbol
  switch(s){
  case suits::Clubs: return "C";
  case suits::Diamonds: return "D";
  case suits::Hearts: return "H";
  case suits::Spades: return "S";
  default: return "E";
  }
}

//Structures and related functions -------------------------------

struct card{
  //Stores the card rank as r, the card suit as s, generates
  //it's string code by calling rankName, Suitname and stores int in
  //cardCode
  
  rank r;
  suit s;

  //  card(rank a, suit b): r(a), s(b){}

  std::string cardCode() 
  {    
    return (rankName(r)+suitName(s)); 
  }

};

  
void printCard(card c){
  std::cout << c.cardCode();
}

void swapCard(card &a, card &b){
  //Swap two cards arround
  
  card temp;

  temp = a;
  a = b;
  b = temp;
  
}
  
#endif


