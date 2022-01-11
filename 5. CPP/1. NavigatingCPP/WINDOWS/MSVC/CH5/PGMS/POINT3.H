#ifndef POINTH
#define POINTH
// Point3.h - pointers to static members

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
	static double originx, originy;
	Point (double x1 = originx, double y1 = originy) { move(x1, y1); }
	static double getoriginx() { return originx; }
	static double getoriginy() { return originy; }
};
#endif
