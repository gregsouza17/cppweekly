#include <iostream>

//Bookeeping
typedef int(*arithmeticFcn)(int,int) ;

struct arithmeticStruct{
  //It holds and arrithmetic operation, with a symbol as a char and a
  //pointer for an operation
  
  char symbol;
  arithmeticFcn operation;
  
};

//get functions
char getOperation();
arithmeticFcn getArithmeticFunction(char s);
int getInt();

//ArithmeticFunctions
int add(int a, int b) {return (a+b);}
int multiply(int a, int b) {return a*b;}
int subtract(int a,int b) {return (a - b);}
int divide(int a, int b) {return (a/b) ;}

static const arithmeticStruct arithmeticArray[]{
  {'+', add}, {'*', multiply}, {'-', subtract}, {'/', divide} 
}; //This are all the operations that are important in this problem

int main(void){

  int a,b;
  a = getInt();
  b = getInt();
  
  char s;
  s= getOperation();

  arithmeticFcn foo;
  foo = getArithmeticFunction(s);

  std::cout << foo(a,b);
  
  return 0;
}

char getOperation() {

  char s;

  std::cout << "Insert an arithmatic operation +,-,*,/ \n";
  std::cin >> s;

  while(std::cin.fail() || (s!='+' && s!='-' && s!='*' && s!='/')){
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> s;
  }

  return s;
}

arithmeticFcn getArithmeticFunction(char s){
  //Loop over all arithmetic structures in the array
  // If finds a matching symbol, returns the pointer to
  //the associeted operation
  
  for(arithmeticStruct a : arithmeticArray){
    if(s==a.symbol)
      return a.operation;
  }

  return 0;
}


int getInt() {

  int s;

  std::cout << "Type and int";
  std::cin >> s;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> s;
  }
  return s;
}
