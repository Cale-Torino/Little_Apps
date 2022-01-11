#ifndef POINTH
#define POINTH
// Point6.h - Point class
#include <iostream.h>
#include <stdio.h>
#include <string.h>

class Point;											// forward reference

typedef void (Point::*motion)(); 				// pointer to class member function

class PointError {
private:
	char buf[80];
public:
	PointError(const char *axis, double badxy, const char *where, double bound) {
			sprintf(buf, "%s (%g) exceeds %s bound (%g)", 
				axis, badxy, where, bound);
		}
	void response() const { cerr << buf << endl; }
};

class Point {
private:
	double x, y;
	static double originx, originy;
	static double leftx, lowery, rightx, uppery;
public:
	void up() { 
		if (y > uppery) 
			throw PointError("y",y,"upper",uppery);
		y++;
	}
	void down() {
		if (y < lowery) 
			throw PointError("y",y,"lower",lowery);
		y--;
	}
	void right() {
		if (x > rightx) 
			throw PointError("x",x,"right",rightx);
		x++;
	} 
	void left() {
		if (x < leftx) 
			throw PointError("x",x,"left",leftx);
		x--;
	} 
	double getx() const { return x; }
	double gety() const { return y; }
	void move(double x1, double y1) { x = x1; y = y1; }
	Point (double x1 = originx, double y1 = originy) { move(x1, y1); }
	static double getoriginx() { return originx; }
	static double getoriginy() { return originy; }
	static void setorigin(double ox, double oy) { originx = ox; originy = oy; }
	static void setquad(double lx, double rx, double ly, double uy) { 
		leftx = lx; rightx = rx; lowery = ly; uppery = uy; }
	Point & rmove(motion, int);
};
#endif
