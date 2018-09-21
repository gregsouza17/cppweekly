#include <iostream>

int readNumber(){
  /*Asks the user for a number input, returns it. */
  
  int number;
  
  //asks user for input
  printf("Please, input a number:\n");
  std::cin >> number;
  
  return number;
}

void writeAnswer(int firstInput, int secondInput){
  /*Print the sum of the two arguments*/
  
  std::cout << firstInput << " + " << secondInput << " = " <<
	           (firstInput + secondInput) << std::endl;

}
