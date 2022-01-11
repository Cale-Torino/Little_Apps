// point2.C - overloaded vs. default args
#include <iostream.h>

class Point;
typedef void (Point::*motion)();

class Point {
private:
	double xc, yc;
public:
	void up() { yc++; }
	void down() { yc--; }
	void right() { xc++; }
	void left() { xc--; }
	double getx() const { return xc; }
	double gety() const { return yc; }
	Point (double x1 = 0, double y1 = 0) { xc = x1; yc = y1; }
	void move(double x1, double y1, motion pm = 0) { 
		if (pm)
			{ xc += x1; yc += y1; }						// relative move 
		else
			{ xc = x1; yc = y1; }						// absolute move 
	}
};

int main()
{
	Point p(20, 20);
	Point q(20, 20);

	p.move(30, 30);											// absolute move
	cout << "p: " << p.getx() << ' ' << p.gety() << endl;

	q.move(5, 0, Point::right);							// relative move
	cout << "q: " << q.getx() << ' ' << q.gety() << endl;
	return 0;
}

/**********************************************************************

$ point2 
p: 30 30
q: 25 20

*/
