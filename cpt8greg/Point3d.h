//Header file foir Point3d
//The classes in this file expect the existence of Vector3D
class Vector3d;

#ifndef POINT3D_H
#define POINT3D_H
class Point3d //Models a 3D point
{
private:
  double m_x, m_y, m_z;
 
public:
  //Constructor, default at origin
  Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
    : m_x(x), m_y(y), m_z(z) {}
 
  void print(); 
  void moveByVector(const Vector3d &v);
};


#endif
