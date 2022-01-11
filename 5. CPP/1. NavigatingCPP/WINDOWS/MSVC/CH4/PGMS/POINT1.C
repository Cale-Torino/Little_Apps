// point1.C - public data members
#include <iostream.h>

class Point {
public:
	double x, y;
	Point (double x1 = 0, double y1 = 0) { x = x1; y = y1; }
};

int main()
{
	Point p(20, 20);
	Point q;												// initialize q to (0,0)

	p.x++;												// go right
	p.x--;												// go left
	p.y++;												// go up
	p.y--;												// go down
	cout << "p: " << p.x << ' ' << p.y << endl;

	q.x = 30;   q.y = 30;							// move q
	cout << "q: " << q.x << ' ' << q.y << endl;
	return 0;
}

/**********************************************************************

$ point1 
p: 20 20
q: 30 30

*/
