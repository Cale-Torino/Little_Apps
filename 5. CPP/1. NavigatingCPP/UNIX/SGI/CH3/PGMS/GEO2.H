#ifndef GEOMETRYH
#define GEOMETRYH
// geo2.h - library namespace definitions
#include <iostream.h>

namespace math_lib {								// Math Library
	struct Point {
		double x, y;
	};
	Point origin = { 0, 0 };
	double slope(Point, Point);
	double max(double a, double b) {
		cout << "max(double, double)" << endl;
		return a > b ? a: b;
	}
	int max(int a, int b) {
		cout << "max(int, int)" << endl;
		return a > b ? a: b;
	}
}

double math_lib::slope(Point a1, Point a2) {
  double dy = a2.y - a1.y;
  double dx = a2.x - a1.x;
  if (dx == 0) 
	  throw "slope(): undefined slope";
  return dy / dx;
}

namespace geo_lib {								// Geometry Library
	struct Point {
		double x, y;
	};
	struct Line { };
	struct Angle { };
	Point origin = { 10, 10 };
}
#endif
