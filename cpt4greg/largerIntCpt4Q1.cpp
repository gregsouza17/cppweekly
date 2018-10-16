#include <iostream>

int main(void){
  //Asks for two integers, the second being bigger, prints
  //the bigger integer swapping if needed
  
  printf("Enter an integer: \n");
  int firstInt;
  std::cin >> firstInt;

  printf("Enter a larger integer\n");
  int secondInt;
  std::cin >> secondInt;

  if(firstInt > secondInt){

	int temp(firstInt);
	firstInt = secondInt;
	secondInt = temp;
	
	printf("Swappiiinnnngggg \n");
	
  }

	printf("The smaller value is %d\n", firstInt);
	printf("The larger value is %d\n", secondInt);

}
