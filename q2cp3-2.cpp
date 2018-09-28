#include <iostream>

bool isEven(int number);

int main(void)
{
  //Aks for a integer, evaluates if it is even by calling isEven(int),
  // Prints the conclusion
  
  std::cout<<"Feed me a integer number!! \n";
  int number;
  std::cin>>number;

  if(isEven(number))
	printf("%d is an even number!!! \n",number);
  else
	printf("%d is NOT AN EVEN NUMBER!!! \n", number);
}

bool isEven(int number)
{
  //Receives a number, returns true if even, false if not
  
  return (number%2==0);
}
