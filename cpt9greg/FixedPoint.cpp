#include <iostream>
#include <cassert>
#include <cmath>

class FixedPoint2{
private:
  int16_t m_integer;
  int8_t m_fraction;

public:

  FixedPoint2(int integer, int fraction): m_integer(integer){

    assert(fraction>-100 && fraction<100 && "Fractionary Part out of Range");

    m_fraction=fraction;

    /* if either part is negative, we'll threat our number as negative,
       also if the number is negative, we'll store both variables a negative for
       reasons */
    if(m_integer < 0. || m_fraction < 0.){

      if(m_integer>0.)
	m_integer=-m_integer;
      if(m_fraction>0.)
	m_fraction=0.;
    }
  }

  FixedPoint2(double numb){

    m_integer = static_cast<int16_t> (numb);

    m_fraction = static_cast<int8_t>(round((numb - m_integer)*100));

    
  }
  
   
    operator double() const{
      //To Double Conversion
      return m_integer + static_cast<double>(m_fraction)/100 ;    
    }
  
};

std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fxd){

  std::cout << static_cast<double>(fxd);

  return out;
}

int main()
{
  	FixedPoint2 a(0.01);
	std::cout << a << '\n';
 
	FixedPoint2 b(-0.01);
	std::cout << b << '\n';
 
	FixedPoint2 c(5.01);
	// stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';
 
	FixedPoint2 d(-5.01);
	// stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';
	
	return 0;
}
