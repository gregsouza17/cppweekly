#include <iostream>

namespace animals{
  enum animals
    {
      chicken, // 0
      dog, // 1
      cat, // 2
      elephant, // 3
      duck, //4
      snake, //5
      MAX_ANIMALS, //6
    };
}


int main(void){

  int hottestTemperatures[365] = {};
  
  int animalNum[animals::MAX_ANIMALS]={2,4,4,4,2,0};

  for(int i =0; i< animals::MAX_ANIMALS ; i++){
    std::cout << "THe number of legs for animal " << i <<
      " is " << animalNum[i]<< std::endl;
  }
  
}
