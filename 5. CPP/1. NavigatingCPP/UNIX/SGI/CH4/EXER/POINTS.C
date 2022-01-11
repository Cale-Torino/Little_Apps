// points.C - Point class, upper/lower bounds checking
#include <iostream.h>
#include "Point6.h"

int main()
{
	try {
		 Point::setquad(-20, 20, -20, 20);		// define plane coordinates
		 Point::setorigin(10, 10);					// set defaults
		 Point p(20, 20);
		 Point q;											// initialize q to (10,10)
		 cout << "originx is " << Point::getoriginx() << endl;
		 cout << "originy is " << Point::getoriginy() << endl;
		 cout << "q: " << q.getx() << ' ' << q.gety() << endl;

		 p.rmove(Point::right, 10);					// go right by 10
		 cout << "p: " << p.getx() << ' ' << p.gety() << endl;

		 q.rmove(Point::down, 5);					// go down by 5
		 cout << "q: " << q.getx() << ' ' << q.gety() << endl;
	}
	catch (const PointError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**************************************************************************

$ points
originx is 10
originy is 10
q: 10 10
x (21) exceeds right bound (20)

*/
