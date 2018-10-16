#include <iostream>
#include <string>

main(){

  std::cout << "Please, insert your name with the keyboard\n";
  std::string name;
  std::getline(std::cin, name);

  std::cout << "Now, insert your age\n";
  int age;
  std::cin >> age;
  std::cin.ignore((255*255), '\n');


  int charsInName(name.length());
  double yearsByChar;

  yearsByChar = (double) age/charsInName;

  std::cout << "Hello, " << name << "\n You have " << charsInName <<
	" characthers in your name. \n" << "You alse are " << age <<
	" years old. \n You lived " << yearsByChar <<
	" years per character in your name, bye !\n";
   
  
}
