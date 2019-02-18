#include <iostream>
#include <string>

class Fruit{
  /*A fruit has a name, a color and respective get functions */  
private:
  std::string m_name;
  std::string m_color;

public:

  Fruit(std::string name, std::string color):
    m_name(name), m_color(color) { }
  

  std::string getName() {return m_name;}
  std::string getColor() {return m_color;}
  
};

class Apple: public Fruit {
  /* Apple inehrits fruits name, color and has fiber content, as well a << operator*/

private:
  double m_fiber;
public:

  Apple(std::string name, std::string color, double fiber):
    Fruit(name, color), m_fiber(fiber) { } 
  
  double getFiber() { return m_fiber;}

  friend std::ostream& operator<<(std::ostream &out, Apple a){

    std::cout<< "Apple("<< a.getName() <<", "<< a.getColor() << ", " << a.getFiber() << ")";
    
    return out;
  }
};


class Banana: public Fruit{
  /* Banana inehrits fruits name, color, and has a << operator*/
  
public:

  Banana(std::string name, std::string color):
    Fruit(name, color) {}

  friend std::ostream& operator<<(std::ostream &out, Banana b){

    std::cout<< "Banana("<< b.getName() <<", "<< b.getColor() << ")";

    return out;
  }
};


int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a <<"\n";
 
	const Banana b("Cavendish", "yellow");
	std::cout << b <<"\n";
 
	return 0;
}













  
