#include <iostream>


int asksValue();

int main(void){

  int array[] = {4,6,7,3,8,2,1,9,5};
  int arraySize;

  arraySize = sizeof(array)/sizeof(array[0]);

  int i;
  
  i = asksValue();
  
  std::cout << array[i] << std::endl;
 
  
  
  return 0;
}

int asksValue(){
  //Gets the user to input a number between 1 and 9

  int heyhou;

  while(true){
    std::cout << "Please enter a number between 1 and 9 \n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> heyhou;

    if(!(std::cin.fail()) && heyhou > 0 && heyhou <10)
      return heyhou;
  }
    
} 
