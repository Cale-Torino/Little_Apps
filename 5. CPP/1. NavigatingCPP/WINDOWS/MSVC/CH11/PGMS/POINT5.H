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
	void up() { y++; }
	void down() { y--; }
	void right() { x++; }
	void left() { x--; }
	double getx() const { return x; }
	double gety() const { return y; }
	void move(double x1, double y1) { x = x1; y = y1; }
	Point (double x1 = originx, double y1 = originy) { move(x1, y1); }
	static double getoriginx() { return originx; }
	static double getoriginy() { return originy; }
	static void setorigin(double ox, double oy) { originx = ox; originy = oy; }
	Point & rmove(motion, int);
};

Point & Point::rmove(motion m, int n) {
	for (int i = 0; i < n; i++)
		(this->*m)();								// call motion routine
	return *this;									// return modified Point object
}
#endif
