#include <iostream>
#include <array>
#include <random>

class Monster{
public:
  enum MonsterType{

    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,
    MAX_MONSTER_TYPES

  };
  
private:
  MonsterType m_type;
  std::string m_name, m_roar;
  int m_hp;

  std::string getTypeString(){
    switch(m_type){
      
    case MonsterType::Dragon  : return "Dragon";        
    case MonsterType::Goblin  : return "Goblin";
    case MonsterType::Ogre    : return "Ogre";
    case MonsterType::Orc     : return "Orc";
    case MonsterType::Skeleton: return "Skeleton" ;
    case MonsterType::Troll   : return "Troll";
    case MonsterType::Vampire : return "Vampire";
    case MonsterType::Zombie  : return "Zombie";
    default: return "Missigno";
      
      
    }
  }
  
public:
  
  Monster(MonsterType type, std::string name, std::string roar,int hp):
    m_type(type), m_name(name), m_roar(roar), m_hp(hp) {}
  
  void print(){
    
    std::cout << m_name << " the " << getTypeString() << " ( " <<
      m_hp << " HP ) says " << m_roar << std::endl; 
    
  }
};


class MonsterGenerator {
  
private:
  static int getRandomNumber(int min, int max)
  {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }
  
  
public:
  static Monster generateMonster(){
    
    
    static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
    static std::string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
    
    Monster::MonsterType r_type;
    r_type =
      static_cast<Monster::MonsterType> (getRandomNumber(0, Monster::MAX_MONSTER_TYPES-1));
    
    int r_hp(getRandomNumber(0,100));
    
    std::string r_name = s_names[getRandomNumber(0,5)];
    std::string r_roar = s_roars[getRandomNumber(0,5)];
    
    return Monster(r_type, r_name, r_roar, r_hp);
  }
  
};

int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
  rand(); // If using Visual Studio, discard first random value
  
  Monster m = MonsterGenerator::generateMonster();
  m.print();
  
  return 0;
}
