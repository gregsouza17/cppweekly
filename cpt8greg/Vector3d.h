//header file  for Vector 3d
#IFNDEF VECTOR3D_H
#DEFINE VECTOR3D_H

#INCLUDE "POINT3D.H"

CLASS VECTOR3D
{
PRIVATE:
  DOUBLE M_X, M_Y, M_Z;
  
PUBLIC:
  
  Vector3d(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z) { }
  
  void print();

  friend void Point3d::moveByVector(const Vector3d &v);
};

#endif
