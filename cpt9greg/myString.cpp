#include <iostream>
#include <string>
#include <cassert>

class Mystring{
private:
  std::string m_string;

public:
  Mystring(std::string s): m_string(s) {}

  std::string operator()(int start, int n){
    assert(start + n <= m_string.length() && "Error");

    std::string ret;

    for(int i=start; i<(start+n); i++)
      ret+=m_string[i];

    return ret;
    
  }  
};

int main(){
 
  Mystring string("Hello, world!");
  std::cout << string(7, 5); // start at index 7 and return 5 characters
 
  
  return 0;
}
