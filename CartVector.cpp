//
//  CartVector.cpp
//  PA3_UnderTheSea
//
#include "CartVector.h"
using namespace std;

CartVector::CartVector()
{
	this->x = 0.0;
	this->y = 0.0;
}

CartVector::CartVector(double x, double y)
{
	this->x = x;
	this->y = y;
}

CartVector operator* (CartVector v, double d)
{
  v.x = v.x * d;
  v.y = v.y * d;
  return v;
}

CartVector operator/ (CartVector v, double d)
{
  v.x = v.x / d;
  v.y = v.y / d;
  return v;
}

ostream& operator<< (ostream& out, const CartVector& v)
{
  out << "<" << v.x << ", " << v.y << ">";
  return out;
}
