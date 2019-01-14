#include <iostream>

class Average{
private:
  int32_t m_sum;
  int8_t m_many;

public:
  Average() { m_sum=0; m_many = 0;}

  Average& operator+=(const int &n){
    //Linkable, adds n to sum and update number of numbers summed, returns
    //a pointer to this avarage.
    
    m_sum+=n;
    m_many++;

    return *this;
  }

  friend std::ostream& operator<<(std::ostream &out, Average avg){

    std::cout << static_cast<double> (avg.m_sum)/avg.m_many;
    
    return out;
  } 

  
};


int main()
{
	Average avg;
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6
 
	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12
 
	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5
 
	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7
 
	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}
