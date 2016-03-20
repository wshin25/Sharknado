//
//  CartPoint.cpp
//  PA3_UnderTheSea
//
#include <cmath>
#include "CartPoint.h"
using namespace std;

// Default constructor
CartPoint::CartPoint()
{
  this->x = 0.0;
  this->y = 0.0;
}

// Constructor
CartPoint::CartPoint(double inputx, double inputy)
{
	this->x = inputx;
	this->y = inputy;
}

//Nonmember function
double cart_distance(CartPoint p1, CartPoint p2)
{
  double xdist = p1.x - p2.x;
  double ydist = p1.y - p2.y;
  double dist = sqrt(xdist*xdist + ydist*ydist);
  return dist;
}

ostream& operator<< (ostream& out, const CartPoint& p)
{
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}


CartPoint operator+ (CartPoint p1, CartVector v1)
{
  p1.x += v1.x;
  p1.y += v1.y;
  return p1;
}

CartVector operator- (CartPoint p1, CartPoint p2)
{
  CartVector v;
  v.x = p1.x - p2.x;
  v.y = p1.y - p2.y;
  return v;
}
