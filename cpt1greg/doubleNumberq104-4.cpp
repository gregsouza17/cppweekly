#include <iostream>

int doubleNumber(int number);


int main(void){

  // Asks the user for a number, and doubles it
  //by calling the doubleNumber
  //function

  int k;

  //Asking for a input
  printf("Type a number to be doubled \n") ;
  std::cin >> k ;

  //Printing the result
  printf("The double of %d is: \n", k ) ;
  std::cout << doubleNumber(k) << std::endl ;

  return 0;

}


int doubleNumber(int number){
  
  return 2*number;
  
}
