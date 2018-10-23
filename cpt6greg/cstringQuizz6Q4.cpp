#include <iostream>


void my_print(char *array);

int main(void){

  char array[] = "Hello, World!";

  my_print(array);
  
}

void my_print(char *array){

  int i = 0;
  bool keepGoing(true);
  char s;
  while(keepGoing){
    
    s = *(array+i);
    if(s == '\0')
      keepGoing = false;
    else
      std::cout << s;

    i++;
  }
  
}
