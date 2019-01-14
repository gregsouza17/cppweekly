#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
private:
  std::string m_make;
  std::string m_model;
  
public:
  Car(std::string make, std::string model)
    : m_make(make), m_model(model)   {  }
  
  friend std::ostream& operator<<(std::ostream &out, const Car &acar);
  
  friend bool operator== (const Car &c1, const Car &c2);
  friend bool operator!= (const Car &c1, const Car &c2);

  friend bool operator<(const Car &c1, const Car &c2);
};

bool operator== (const Car &c1, const Car &c2)
{
  return (c1.m_make== c2.m_make &&
	  c1.m_model== c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
  return !(c1== c2);
}


int main()
{
 
  std::vector<Car> v;
  
  v.push_back(Car("Toyota", "Corolla"));
  v.push_back(Car("Honda", "Accord"));
  v.push_back(Car("Toyota", "Camry"));
  v.push_back(Car("Honda", "Civic"));
	
  std::sort(v.begin(), v.end()); // requires an overloaded operator<
	
  for (auto &car : v)
    std::cout << car << '\n'; // requires an overloaded operator<<
	
  return 0;
  
  return 0;
}


std::ostream& operator<<(std::ostream &out, const Car &acar){

  std::cout << acar.m_model << " from " << acar.m_make;
  
  return out;
}

bool operator<(const Car &c1, const Car &c2){
  //The order is alphabetic in the COnstructor name, if they have the same constructor
  //We use the model name.
  
  if(c1.m_make==c2.m_make)
    return c1.m_model<c2.m_model;

  return c1.m_make<c2.m_make;
  
}
