#include <iostream>

int gcd(int a, int b) {
    return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
}

class Fraction{
private:
  int m_numerator, m_denominator; 

  void reduce(){
    int divisor;
    divisor=gcd(m_numerator, m_denominator);
    
    m_numerator=m_numerator/divisor;
    m_denominator=m_denominator/divisor;
  }
public:
  Fraction() {}
	      
  Fraction(int numerator, int denominator):
    m_numerator(numerator), m_denominator(denominator) { reduce(); }

  friend std::ostream& operator<<(std::ostream &out, const Fraction &f1);
  friend std::istream& operator>>(std:: istream &in, Fraction &f1);
  
  friend Fraction operator*(Fraction f1, Fraction f2);
  friend Fraction operator*(Fraction f1, int k);
  friend Fraction operator*(int k, Fraction f1);
  
};


//MAIN========================================
int main()
{
 
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
 
	return 0;
}
//MAIN=========================================


Fraction operator*(Fraction f1, Fraction f2){

  return Fraction(f1.m_numerator*f2.m_numerator, f1.m_denominator*f2.m_denominator);
}

Fraction operator*(Fraction f1, int k){

  return (f1*Fraction(k,1));
}

Fraction operator*(int k, Fraction f1){

  return f1*k;
}

std::ostream& operator<<(std::ostream &out, const Fraction &f1){
  std::cout<< f1.m_numerator << "/" << f1.m_denominator<<std::endl;
  return out;
}

std::istream& operator>>(std:: istream &in, Fraction &f1){
  //expected input "a/b"
  char trash;

  in >> f1.m_numerator;
  in>>trash;
  in >> f1.m_denominator;
  
}







