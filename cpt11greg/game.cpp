#include "classesGame.cpp"

#include <iostream>
#include <string>


int main()
{
  Monster m(Monster::ORC);
  std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
  
  return 0;
}
