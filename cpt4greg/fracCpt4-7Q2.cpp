#include <iostream>

struct Rational{

  //Represents a Rational numbers with sum, product and decimal
  // representation methods included
  
  int numerator;
  int denominator;

  Rational(int a, int b) : numerator(a), denominator(b) {}

  Rational operator+(const Rational q){
	
	return Rational( numerator*q.denominator +
					 denominator*q.numerator,
					 denominator*q.denominator);
  }

  Rational operator*(const Rational q){
	return Rational(numerator*q.numerator,
					denominator*q.denominator);
  }

  double decimalRepresentation(void) {
	return ((double) numerator/denominator);
  }
  
};


int main(void){

  Rational half(3,2);

  std::cout << (half*half).decimalRepresentation() << "\n"; 
  return 0;
}
