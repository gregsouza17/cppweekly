#ifndef CREATURES
#define CREATURES

#include <iostream>
#include <string>



int getRandomNumber(int min, int max)
{
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  // sttatic used for efficiency, so we only calculate this value once
  // evenly distribute the random number across our range
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature {

//  The Creature class will consist of: (string) Name,
// (Char) Symbol, (ints) health, damage Dealt and gold.

// It'll have a full class of getters for each variable and:
// void reduceHealth, bool is Dead, void addGold 

protected:
  std::string m_name;
  char m_symbol;
  int m_health, m_damage, m_gold;

public:
  
  Creature(std::string name, char symbol, int health, int damage, int gold):
    m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
  {
  }

  //Getters
  std::string getName() {return m_name;}
  char getSymbol() {return m_symbol;}
  int getHealth() {return m_health;}
  int getDamage() {return m_damage;}
  int getGold() {return m_gold;}

  void reduceHealth(int value){
    //Reduce a Creature Health by Value
    m_health-=value;
  }

  bool isDead(){
    //Returns true if heal is lower than 0
    return m_health<=0;
  }

  void addGold(int gold){
    m_gold+=gold;
  }

};

class Player: public Creature{
  /* The Player class inehirits from Creature, it has an addiotinal level
member, with a getter, and a levelUp method, and a hasWon method
*/
private:
  int m_level;
public:
  Player(std::string name): Creature(name,'@',10, 1, 0), m_level(1) {}

  int getLevel() {return m_level;}
  
  void levelUp(){
    //When the player level up, he gets +1 Damage and Level
    m_damage+=1;
    m_level+=1;
  }

  bool hasWon(){
    return m_level==19;
  }
  
};

class Monster: public Creature{
  /*The monster class will have associeted with it an Enum with
all possible monster types, a static member with the data about the monster.*/
public:
  enum Type{
    DRAGON, // 0
    ORC, // 1 
    SLIME, // 2
    MAX_TYPE // 3
  };

  struct MonsterData{
    std::string name;
    char symbol;
    int health, damage, gold;
  };

  static MonsterData monsterData[MAX_TYPE];


  //The monster constructor gets the creature Type, and uses the static monsterData to get
  //the Monster damage, name, symbol...
  Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol,
			       monsterData[type].health, monsterData[type].damage,
			       monsterData[type].gold)
  {
  }


  static Monster getRandomMonster(){
    //Returns a random monster
    
    int r = getRandomNumber(0, MAX_TYPE-1);

    Monster m( static_cast<Type>(r));
    
    return m;
  }

};


//Lookup table

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPE]
{
  { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
      { "slime", 's', 1, 1, 10 }
};




#endif
