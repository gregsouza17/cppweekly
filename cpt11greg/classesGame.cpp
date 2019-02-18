#ifndef CREATURES
#define CREATURES

#include <iostream>
#include <string>

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
    m_health-=value;
  }

  bool isDead(){
    return m_health<=0;
  }

  void addGold(int gold){
    m_gold+=gold;
  }

};

class Player: public Creature{
private:
  int m_level;
public:
  Player(std::string name): Creature(name,'@',10, 1, 0), m_level(1) {}

  int getLevel() {return m_level;}
  
  void levelUp(){
    m_damage+=1;
    m_level+=1;
  }

  bool hasWon(){
    return m_level>19;
  }
  
};

class Monster: public Creature{
public:
  enum Type{
    DRAGON,
    ORC,
    SLIME,
    MAX_TYPE
  };

  struct MonsterData{
    std::string name;
    char symbol;
    int health, damage, gold;
  };

  static MonsterData monsterData[MAX_TYPE];

  Monster(Type type): Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health,
			       monsterData[type].damage, monsterData[type].gold)
  {
    
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
