#include <iostream>
#include <string>

enum class Race{
  //Possible Monster Race will be enumereted here

  OGRE,
  DRAGON,
  ORC,
  GIANT_SPIDER,
  SLIME,
  TEST,
  
};


std::string raceName(Race r);

struct Monster{
  //Here we'll store monster Race, Name and HP

  Race Type;
  std::string Name;
  int HP;

  //Intrinsic method for printing the monster type
  std::string typeString() { return raceName(Type); }
};



int main(void){

  Monster ettin{Race::OGRE, "John and Mikael", 143};
  
  return 0;
}

std::string raceName(Race r){
  //Returns the string of the Race name.
  switch (r) {
  case Race::OGRE : return "Ogre";
  case Race::DRAGON : return "Dragon" ;
  case Race::ORC : return "Orc";
  case Race::GIANT_SPIDER : return "Giant Spider";
  case Race::SLIME : return "Slime";
  default: return "Missigno";
		
  }
}
