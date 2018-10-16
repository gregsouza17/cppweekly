#include <iostream>


int sumTo(int value);

int main(void){

  std::cout << sumTo(100) << "\n";

  return 0;
}

int sumTo(int value){
  //Returns the sum of all integers up to value
  int finalSum(0);
  for(int i=0; i<value+1; i++){
	finalSum+=i;
  }

  return finalSum;

}
