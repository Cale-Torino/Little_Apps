#ifndef LINEH
#define LINEH
// Line.h - Line Class with Point objects
#include <iostream.h>
#include <stdio.h>
#include "String.h"
#include "Point5.h"
#include "exception.h"

class LineError : public exception { 
private:
	char buf[80];
public:
	LineError(double x1, double x2) throw() : exception("Line: undefined slope")  { 
		sprintf(buf, " for xcoords (%g, %g)", x1, x2);
	}
	const char *what() const throw() { return String(exception::what()) + buf; }
};

class Line {
private:
	Point p1, p2;
public:
	Line(const Point & a, const Point & b) throw() : p1(a), p2(b) { }
	double slope() throw (exception);
};

double Line::slope() throw (exception) {
	double dy = p2.gety() - p1.gety();
	double dx = p2.getx() - p1.getx();
	if (dx == 0)
		throw LineError(p2.getx(), p1.getx());
	return dy / dx;
}
#endif
