#include <iostream>

int readNumber();
void writeAnswer(int firstInput, int secondInput);

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

