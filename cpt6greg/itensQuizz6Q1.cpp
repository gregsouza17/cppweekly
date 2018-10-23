#include <iostream>

enum item{
  HEALTH_POTION,
  TORCHES,
  ARROWS,
  SWORDS,
  MAX_ITEM,
};

int totalItem( int *itens);

int main(void){

  int itemQtd[item::MAX_ITEM] {2,5,20,2};

  std::cout << totalItem(itemQtd) << std::endl;
  
  return 0;
}

int totalItem(int *itens){

  int sum=0;

  for(int i =0; i< item::MAX_ITEM; i++)
    sum+=itens[i];

  return sum;
  
  
}
