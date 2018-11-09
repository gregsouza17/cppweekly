#include <iostream>

class IntPair{
public:
  int m_one;
  int m_two;

  void set(int a, int b){
    m_one = a;
    m_two = b;
  }

  void print(){
    printf("Pair(%d,%d) \n", m_one, m_two);
  }
  
};

int main(void){
  
  IntPair p1;
  p1.set(1, 1); // set p1 values to (1, 1)
  
  IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)
  
  p1.print();
  p2.print();
	
	
  return 0;
  }
