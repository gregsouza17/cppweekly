#include <iostream>
#include <string>


int main(void) {

  std::string theNames[] = {"Alex", "Betty", "Caroline", "Dave",
			    "Emily", "Fred", "Greg", "Holly"};

  std::cout << "Say a name \n";
  std::string aName;
  std::cin >> aName;

  bool found(false);

  for(auto const &ref : theNames){
    
    if(ref == aName){
      std::cout << "The name " << aName << "was found" << std::endl;
      found = true;
      break;
    }
    
  }

  if(!found)
    std::cout << "The name " << aName << "was NOT found \n" ;
  
  
}
