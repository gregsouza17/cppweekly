#include <iostream>


int getInt();
char getOperation();
void operateAndPrint(char operation, int a, int b);


int main(void)
{
  
  // Asks the user for two integers, and an aritimethical
  //operation, calls operateAndPrint to print the result

  int a,b;
  char anOperation;

  a = getInt();
  b = getInt();

  anOperation = getOperation();

  operateAndPrint(anOperation, a, b);


}

int getInt()
{

  std::cout << "Please enter a integer \n";
  int n;
  std::cin>>n;

  return n;
  
}

char getOperation(){

  std::cout << "Please, enter a mathematical symbol \n";
  char aSymbol;
  std::cin >> aSymbol;

  return aSymbol;

}


void operateAndPrint(char operation,int a, int b){
  //Given an operation and two integer, prints the result

  switch (operation)
	{
	case '+':
	  std::cout << a << " + " << b <<" = " << (a+b);
	  printf("\n");
	  break;
	case '*':
	  std::cout << a << " * " << b <<" = " << (a*b);
	  printf("\n");
	  break;
	case '-':
	  std::cout << a << " - " << b <<" = " << (a-b);
	  printf("\n");
	  break;
	case '/':
	  std::cout << a << " / " << b <<" = " << (a/b);
	  printf("\n");
	  break;
	default:
	  std::cout << "Unkown Operation \n";
	  break;
	   
	}
  
}
