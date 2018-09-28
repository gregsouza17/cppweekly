#include <iostream>
#include <cmath>

int printAndDiscountBit(int aNumber, int powOfTwo);

int main(void)
{
  printf("Inser a integer between 0 and 255:\n ");
  int x;
  std::cin>>x;

  x = printAndDiscountBit(x, 128);
  x = printAndDiscountBit(x, 64);
  x = printAndDiscountBit(x, 32);
  x = printAndDiscountBit(x, 16);

  printf("\t");
	
  x = printAndDiscountBit(x, 8);
  x = printAndDiscountBit(x, 4);
  x = printAndDiscountBit(x, 2);
  x = printAndDiscountBit(x, 1);

  printf("\n");

  return 0;
}

int printAndDiscountBit(int aNumber, int powOfTwo)
{
  //Given a power of two, returns the value of the
  //binary digit at aPower and decrements aNumber by
  //that value
  if(aNumber>=powOfTwo){
	std::cout << "1";
	return aNumber - powOfTwo;
	}
  else {
	std::cout << "0";
	return aNumber;
  }

}
