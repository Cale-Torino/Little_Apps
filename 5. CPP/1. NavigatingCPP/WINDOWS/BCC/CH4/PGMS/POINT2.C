// point2.C - private data members
#include <iostream.h>

class Point {
private:
	double x, y;
public:
	void up() { y++; }
	void down() { y--; }
	void right() { x++; }
	void left() { x--; }
	double getx() const { return x; }
	double gety() const { return y; }
	void move(double x1, double y1) { x = x1; y = y1; }
	Point (double x1 = 0, double y1 = 0) { move(x1, y1); }
};

int main()
{
	Point p(20, 20);
	Point q;														// initialize q to (0,0)

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

$ point2 
p: 20 20
q: 30 30

*/
