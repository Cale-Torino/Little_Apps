// point3.C - pointers to static members
#include <iostream.h>
#include "Point3.h"

double Point::originx = 10;						// default for originx
double Point::originy = 10;						// default for originy

int main()
{
	Point p(20, 20);
	Point q;												// initialize q to default
	double *px = &Point::originx;					// ptr to static data member

	// ptr to static member function
	double (*py)() = Point::getoriginy;			

	cout << "originx is " << *px << endl;
	cout << "originy is " << py() << endl;
	cout << "q: " << q.getx() << ' ' << q.gety() << endl;

	p.right();													// go right
	p.left();													// go left
	p.up();														// go up
	p.down();													// go down
	cout << "p: " << p.getx() << ' ' << p.gety() << endl;

	q.move(30, 30);											// move q
	cout << "q: " << q.getx() << ' ' << q.gety() << endl;
	return 0;
}

/**********************************************************************

$ point3 
originx is 10
originy is 10
q: 10 10
p: 20 20
q: 30 30

*/
