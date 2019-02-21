#include "classesGame.cpp"

#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
 
// Generate  random number between min and max (inclusive)
// Assumes srand() has already been called

void attackMonster(Monster &m, Player &p);
void attackPlayer(Monster &m, Player &p);

void fightMonster(Player &p);

int main(){

  srand(static_cast<unsigned int>(time(0)));
  // set initial seed value to system clock
  rand(); // get rid of first result

  std::cout<<"Enter Your Name: ";
  std::string name;
  std::cin>>name;

  
  Player p(name);
  std::cout << "Welcome" << p.getName() << "\n";

  while(!p.isDead() && !p.hasWon())
    fightMonster(p);

  if (p.isDead())
    {
      std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
      std::cout << "Too bad you can't take it with you!\n";
    }
  else
    {
      std::cout << "You won the game with " << p.getGold() << " gold!\n";
    }
  
  return 0;
  
}


void attackMonster(Monster &m, Player &p){

  if(p.isDead()){
    std::cout << "You Cant Attack, You are Dead! \n";
    return;
  }

  m.reduceHealth(p.getDamage());
  std::cout << "Player " << p.getName() << " attacks creature " << m.getName()<<
    " for " << p.getDamage() << " damage \n";

  return;
}
  
void attackPlayer(Monster &m, Player &p){
  if(m.isDead()){
    std::cout << "The Monster Can't Attack, it is dead";
    return;
  }

  p.reduceHealth(m.getDamage());
  std::cout << "The " << m.getName() << " hit you for " <<
    m.getDamage() << " damage \n";

  return;
}



void fightMonster(Player &p){
  Monster m = Monster::getRandomMonster();
  std::cout<<"You encounter monster " << m.getName() << "\n";
  while(!p.isDead() && !m.isDead()){

    std::cout << "Do you want to (R)un or (F)ight? " << "\n";
    char c;
    std::cin >> c;

    if(c=='R' || c=='r'){

      if(getRandomNumber(0,1)==1){
	std::cout<< "You Flee Sucessfully" << "\n";
	return;
      }
      else{
	std::cout<< "You Fail to Flee Sucessfully" << "\n";
	attackPlayer(m,p);
	continue;
      }
    }
    if(c=='F' || c=='f'){
      attackMonster(m, p);
      attackPlayer(m, p);   
    }
  }
}
