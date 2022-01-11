// geo1.C - geometry implementations
#include "geo1.h"

Point origin = { 0, 0 };

double slope(Point a1, Point a2) {
  double dy = a2.y - a1.y;
  double dx = a2.x - a1.x;
  if (dx == 0) 
	  throw ("slope(): undefined slope");
  return dy / dx;
}
