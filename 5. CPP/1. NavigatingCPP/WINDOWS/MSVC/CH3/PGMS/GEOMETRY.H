#ifndef GEOMETRYH
#define GEOMETRYH
// geometry.h - geometry definitions

namespace Geometry {					// namespace definition
	struct Point {
		double x, y;
	};
	double slope(Point, Point);
}
#endif
