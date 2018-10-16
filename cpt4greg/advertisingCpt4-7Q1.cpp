#include <iostream>

struct Advertising
{
  //It keep tracks of how many adds are shown,
  // what percentage of adds are clicked on
  // and avarage earning per click
  
  int addsShown;
  double clickRate;
  double avarageEarning;
};

double moneyMade(struct Advertising);

int main(void){
  //This will be used to create and fill the strucure, and
  //also to print and teste the moneyMade Function

  struct Advertising adv;

  adv.addsShown = 7;
  adv.clickRate = 10000.0;
  adv.avarageEarning = 0.02;

  std::cout << moneyMade(adv) << "\n";
  
}


double moneyMade(struct Advertising adv)
{
  //Given the advertising strucuture, returns the total money made
  //That is Number of Clicks * avarage earning

  return (adv.addsShown*adv.clickRate*
		   adv.avarageEarning);
}

