#include <iostream>
#include "Vector3d.h"

void Point3d::print()
{
  std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3d::moveByVector(const Vector3d &v) 
{
  //Translates a a point by a given vector
  m_x += v.m_x;
  m_y += v.m_y;
  m_z += v.m_z;
}
