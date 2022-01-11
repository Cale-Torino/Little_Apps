#ifndef FIGURE
#define FIGURE
// Figure.h - abstract base class with RTTI
#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <typeinfo.h>
#include "String.h"
#define PI M_PI

class Figure {
private:
	static int count;
public:
// Constructor
	Figure()  { count++; }
	Figure(const Figure &) { count++; }			// copy constructor
// Destructor
	virtual ~Figure()  { count--; }
// Pure Virtual Member Functions
	virtual Figure & operator+=(const Figure &) = 0;
	virtual double area() const = 0;
	String whatshape() const { return typeid(*this).name(); }
};

class Circle: public Figure {
private:
	double radius;
public:
// Constructors
	explicit Circle(double r = 1) { radius = r; }
// Member functions
	Figure & operator+=(const Figure &);
	double area() const { return PI * radius * radius; }
}; 

class Square: public Figure {
private:
	double side;
public:
// Constructors
	explicit Square(double s = 1) { side = s; }
// Member functions
	Figure & operator+=(const Figure &);
	double area() const { return side * side; }
};

inline ostream & operator<<(ostream & os, const Figure & fig) {
	return os << fig.area() << " for a " << fig.whatshape();
}

Figure & Circle::operator+=(const Figure & fig) {
	try {
		const Circle & pc = dynamic_cast<const Circle &>(fig);
		radius += pc.radius;
	}
	catch (bad_cast) {
		cerr << "Circle: right operand should be a Circle" << endl;
	}
	return *this;
}

Figure & Square::operator+=(const Figure & fig) {
	try {
		const Square & ps = dynamic_cast<const Square &>(fig);
		side += ps.side;
	}
	catch (bad_cast) {
		cerr << "Square: right operand should be a Square" << endl;
	}
	return *this;
}

int Figure::count = 0;                   // initialize static
#endif
