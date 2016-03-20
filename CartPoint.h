//
//  CartPoint.h
//  PA3_UnderTheSea
//

#ifndef __CartPoint__
#define __CartPoint__
#include "CartVector.h"
#include <iostream>
using namespace std;

class CartPoint
{
public:
	double x;
	double y;

	CartPoint();
	CartPoint(double inputx, double inputy);
};

double cart_distance(CartPoint p1, CartPoint p2);
CartPoint operator+ (CartPoint p1, CartVector v1);
CartVector operator- (CartPoint p1, CartPoint p2);
ostream& operator<< (ostream&, const CartPoint&);

#endif /* defined(__CartPoint__) */
