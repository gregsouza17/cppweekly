#include <iostream>

class Stack{

  int m_stack[10];
  int m_lenght;

public:
  
  void reset(){
    m_lenght = 0;
    
    for(int i=0; i<10; i++)
      m_stack[i] = 0;
    
  }

  void push(int a){
    m_stack[m_lenght] = a;
    m_lenght++;
  }

  int pop(){

    m_lenght--;
    return m_stack[m_lenght+1];

  }

  void print(){

    for(int i=0; i<m_lenght; i++)
      std::cout << m_stack[i] << "   ";

    std::cout << "\n";
    
  }
};

int main(void){

  Stack stack;
  stack.reset();
 
  stack.print();
 
  stack.push(5);
  stack.push(3);
  stack.push(8);
  stack.print();
	
  stack.pop();
  stack.print();
	
  stack.pop();
  stack.pop();
	
  stack.print();
	
  return 0;
}
