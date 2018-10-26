#include <iostream>


void printStuff(int x=2, int y=10);


int main(void){

  printStuff();
  
  return 0;
}

void printStuff(int x, int y){

  std::cout<< x << "\t" << y << std::endl;
  
}
