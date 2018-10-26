#include <iostream>

unsigned long long int factorial(int n);

int main(void){

  for(int i=0; i<16; i++){
    std::cout << i <<"! = " << factorial(i) << std::endl;
  }

  
  return 0;
}

unsigned long long int factorial(int n){

  if(n<2)
    return 1;

  return n*factorial(n-1);
}
