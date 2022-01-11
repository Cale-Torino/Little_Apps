// abs.C - Abstract Base class
#include <iostream.h>
#include "Shape.h"

int main() 
{
	//Shape s1;								// illegal, abstract base
	//Shape *p = new Shape;				// illegal, abstract base

	//void f(Shape);							// illegal to pass by value
	//Shape g();								// illegal to return by value

	RTriangle t1(2, 3);										// RTriangle Shape
	//Shape s2 = static_cast<Shape>(t1);				// illegal to cast
	//Shape s3 = reinterpret_cast<Shape>(t1);			// illegal to cast

	Shape *ps1 = 0;						// legal, pointer to abstract base
	Shape **ps2 = new Shape *;			// legal, ptr to ptr to abstract base

	void w(const Shape &);				// legal to pass by reference
	Shape & h();							// legal to return by reference

	RTriangle t2(2, 3);					// RTriangle Shape
	Shape *ps3 = &t2;						// legal pointer initialization
	Shape & rs = t2;						// legal reference initialization
	cout << (void *)&rs << ' ' << (void *)ps1 << ' ' << 
				(void *)ps2 << ' ' << (void *)ps3 << endl;
	return 0;
}

/**********************************************************************

$ abs 
0xffd2 0x0df6 0x1bfa 0xffd2

*/
