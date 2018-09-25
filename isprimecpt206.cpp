#include <iostream>


bool isprime(int n);

int main(void){
  //Asks for single digit input from user,
  //prints if the digit is or isn't a prime number.

  
  std::cout << "Input a single digit number" << std::endl;
  int input;
  std::cin >> input;

  
  if(isprime(input))
	printf("The number %d is a prime!\n", input);
  else
	printf("The Number %d is NOT a prime!\n", input);

  
  return 0;
}


bool isprime(int n){
  //Evaluates if a singe digit number n is a prime or not
  // It does that trought direct comparison with one digit primes
  
  if(n == 2) return 1;
  if(n == 3) return 1;
  if(n == 5) return 1;
  if(n == 7) return 1;

  return 0;
}
