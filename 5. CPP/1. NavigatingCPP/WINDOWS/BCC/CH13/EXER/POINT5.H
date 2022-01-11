#ifndef POINTH
#define POINTH
// Point5.h - pointer to class members

class Point;									// forward reference

// pointer to class member function
typedef void (Point::*motion)();

class Point {
private:
	double x, y;
	static double originx, originy;
public:
	void up() throw() { y++; }
	void down() throw() { y--; }
	void right() throw() { x++; }
	void left() throw() { x--; }
	double getx() const throw() { return x; }
	double gety() const throw() { return y; }
	void move(double x1, double y1) throw() { x = x1; y = y1; }
	Point (double x1 = originx, double y1 = originy) throw() { move(x1, y1); }
	static double getoriginx() throw() { return originx; }
	static double getoriginy() throw() { return originy; }
	static void setorigin(double ox, double oy) throw()
			{ originx = ox; originy = oy; }
	Point & rmove(motion, int) throw();
};

Point & Point::rmove(motion m, int n) throw() {
	for (int i = 0; i < n; i++)
		(this->*m)();								// call motion routine
	return *this;									// return modified Point object
}
#endif
