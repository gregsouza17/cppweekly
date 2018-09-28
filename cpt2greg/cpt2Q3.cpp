#include <iostream>

double getDouble();
char getSymbol();
void doOperation(double x, double y, char operation);

int main(void){
  //Asks for two doubles using getDouble, than for an operation
  //using getSymbol, finally calls doOperation that does the
  //required operation and prints it.
  
  double firstInput, secondInput;
  firstInput  = getDouble();
  secondInput = getDouble();
  
  char s;
  s = getSymbol();

  doOperation(firstInput , secondInput , s);
}


double getDouble(){
  //Asks the user for a real number, returns it.
  
  std::cout << "Please, enter a real number up to 8 digits: \n";
  double x;
  std::cin >> x;
  
  return x;
}

char getSymbol(){
  //Asks for a operational symbol: +, -, / or *, returns
  // the symbol if it is a expected ones, returns a blanck char
  //otherwise

  std::cout << "Please, enter a mathematical symbol: *,+,-,/: \n";
  char symbol(0);
  std::cin >> symbol;
  
  return symbol;
}


void doOperation(double x, double y, char operation){
  //Receives two doubles x,y a char that should be an
  //allowed mathematical operation (+,*, /, -),
  //If the operation is indeed allowed, it prints x op. y
  //Else, print a blank line
  
  if(operation == '+')
	printf("%f + %f = %f \n", x,y, x+y);
  else if(operation == '-')
	printf("%f - %f = %f \n", x,y, x-y);
  else if(operation == '*')
	printf("%f * %f = %f \n", x,y, x*y);
  else if(operation == '/')
	printf("%f / %f = %f \n", x,y, x/y);
  else
	printf("\n");  
}
