#include <iostream>


void printLetter(int a);

int main(void)
{
  int startingPoint(0);

  printLetter(startingPoint);

  int index = 0;
  while(index < (255-startingPoint)){
	printLetter(startingPoint+index);
	index++;
  }
  
}


void printLetter(int a)
{


  char theLetter;

  theLetter = static_cast<char>(a);

  std::cout << "Number " << a << " is letter "<< theLetter << "\n";
  
  
}
