#include <iostream>
#include "io.hpp"

int main(void)
{

  //Asks the user for two numbers,
  //using the function readNumber, and then
  // Writes out the sum of the numbers by calling writeAnswer
  
  int firstInput, secondInput;

  //Asking for inputs and reading them
  firstInput = readNumber();
  secondInput = readNumber();

  //Adding the inputs and printing them
  writeAnswer(firstInput,secondInput);

  return 0;
}
