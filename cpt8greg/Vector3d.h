//header file  for Vector 3d
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h"

class Vector3d	
{ //Models a 3D vector
private:
  double M_X, M_Y, M_Z;
	 
public:
  
  Vector3d(double x=0, double y=0, double z=0)
    : m_x(x), m_y(y), m_z(z) { }
  
  void print();

  friend void Point3d::moveByVector(const Vector3d &v);
};

#endif
