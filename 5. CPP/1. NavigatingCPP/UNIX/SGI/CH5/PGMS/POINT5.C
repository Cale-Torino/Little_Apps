// point5.C - pointers to class members
#include <iostream.h>
#include "Point5.h"

double Point::originx = 0;						// initialize originx
double Point::originy = 0;						// initialize originy

int main()
{
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
	return 0;
}

/**********************************************************************

$ point5 
originx is 10
originy is 10
q: 10 10
p: 30 20
q: 10 5

*/
