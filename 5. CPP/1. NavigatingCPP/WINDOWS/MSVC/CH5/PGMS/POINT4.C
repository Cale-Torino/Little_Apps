// point4.C - pointers to class members
#include <iostream.h>

class Point {
public:
	double x, y;
	Point (double x1 = 0, double y1 = 0) { x = x1; y = y1; }
};

int main()
{
	Point p(20, 20);										// stack
	Point *q = new Point(10, 10);						// free store
	double Point::*px = &Point::x;					// pointer to data member
	double Point::*py = &Point::y;					// pointer to data member

	// object dereference
   cout << "p: " << p.*px << ' ' << p.*py << endl;

	// pointer dereference
   cout << "q: " << q->*px << ' ' << q->*py << endl;
	delete q;
	return 0;
}

/**********************************************************************

$ point4 
p: 20 20
q: 10 10

*/
