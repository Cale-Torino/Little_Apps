#ifndef PSHAPEH
#define PSHAPEH
// PShape.h - Persistent Shapes with multiple inheritance
#include <iostream.h>
#include "Persist.h"
#include "Shape.h"

class Persist_Circle : public Circle, public Persist {
public:
	explicit Persist_Circle(double r = 1) : Circle(r) { }
	Persist_Circle(ifstream & ifs) { ifs >> *this; ifs.get(); }
	static Persist *new_circle(ifstream & ifs) 
		{ return new Persist_Circle(ifs); }
	void save(ofstream & ofs) const {
		ofs << typeid(*this).name() << '\n' << get_radius();
	}
};

class Persist_Square : public Square, public Persist {
public:
	explicit Persist_Square(double s = 1) : Square(s) { }
	Persist_Square(ifstream & ifs) { ifs >> *this; ifs.get(); }
	static Persist *new_square(ifstream & ifs) 
		{ return new Persist_Square(ifs); }
	void save(ofstream & ofs) const {
		ofs << typeid(*this).name() << '\n' << get_side();
	}
};

class Persist_RTriangle : public RTriangle, public Persist {
public:
	explicit Persist_RTriangle(double h = 1, double b = 1) : RTriangle(h, b) { }
	Persist_RTriangle(ifstream & ifs) { ifs >> *this; ifs.get(); }
	static Persist *new_triangle(ifstream & ifs) 
		{ return new Persist_RTriangle(ifs); }
	void save(ofstream & ofs) const {
		ofs << typeid(*this).name() << '\n' << get_height() 
			 << ' ' << get_base();
	}
};
#endif
