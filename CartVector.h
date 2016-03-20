//
//  CartVector.h
//  PA3_UnderTheSea
//

#ifndef __CartVector__
#define __CartVector__

#include <iostream>
using namespace std;

class CartVector
{
public:
	double x;
	double y;
    
	CartVector();
	CartVector(double, double);
};

CartVector operator* (CartVector,double);
CartVector operator/ (CartVector, double);
ostream& operator<< (ostream&, const CartVector&);

#endif /* defined(__CartVector__) */
