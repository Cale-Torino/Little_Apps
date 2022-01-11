// geometry.C - geometry implementations
#include "geometry.h"

namespace Geometry {						// namespace extension
	Point origin = { 0, 0 };
}

double Geometry::slope(Point a1, Point a2) {
	double dy = a2.y - a1.y;
	double dx = a2.x - a1.x;
	if (dx == 0) 
		throw "slope(): undefined slope";
	return dy / dx;
}
