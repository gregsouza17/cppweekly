#include <iostream>

void printBinary(int a);

int main(void){

  printBinary(247);
  
  return 0;
}

void printBinary(int a){

  if(a>1)
    printBinary(a/2);

  std::cout << a%2;
}
