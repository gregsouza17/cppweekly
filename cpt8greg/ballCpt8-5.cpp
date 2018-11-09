#include <iostream>
#include <string>

class Ball{
private:
  
  std::string m_color;
  double m_radius;

public:
  //Constructors
  Ball(const std::string &color = "black", double radius = 10.0){
    m_color = color;
    m_radius = radius;
  }
  Ball(double radius){
    m_color = "Black";
    m_radius = radius;
  }

  void print(){
    std::cout << "color: " << m_color << ", radius: " << m_radius <<
      std::endl;
  }
};

int main(void){

  Ball def;
  def.print();
 
  Ball blue("blue");
  blue.print();
	
  Ball twenty(20.0);
  twenty.print();
	
  Ball blueTwenty("blue", 20.0);
  blueTwenty.print();
 

  return 0;
}
