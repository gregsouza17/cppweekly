#include <iostream>
#include <cmath>

class Point2d{
  //Models a 2D point
private:
  int m_x, m_y;

public:
  Point2d(double x=0.0, double y = 0.0): m_x(x),m_y(y) {}

  void print(){
    std::cout << "( " << m_x << " , " << m_y << " )" << std::endl;
  }

  // double distanceTo(Point2d p){

  //   return std::sqrt((m_x-p.m_x)*(m_x-p.m_x) + (m_y-p.m_y)*(m_y-p.m_y));
  // }

  friend double distanceTo(Point2d p, Point2d q);
};

int main(void){

  Point2d first;
  Point2d second(3.0, 4.0);
  first.print();
  second.print();
  std::cout << "Distance between two points: " <<
    distanceTo(first, second) << '\n';
  

  return 0;
}


double distanceTo(Point2d p, Point2d q){
  //Calculate de euclidian distance between two points
  return std::sqrt((q.m_x-p.m_x)*(q.m_x-p.m_x) +
		   (q.m_y-p.m_y)*(q.m_y-p.m_y));
}
