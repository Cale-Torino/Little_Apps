#ifndef SOLIDH
#define SOLIDH
// Solid.h - Base class Solid interface
#include <iostream.h>
#include <math.h>
#include "String.h"
#define PI M_PI

class Solid {													// abstract base
private:
	static int count;											// static data member
public:
	Solid() { count++; }										// constructor
	Solid(const Solid &) { count++; }					// copy constructor
	virtual ~Solid() { count--; }							// virtual destructor
	virtual double surface_area() const = 0;			// pure virtual
	virtual double volume() const = 0;					// pure virtual
	virtual void input(istream &) = 0;					// pure virtual
	virtual void output(ostream &) const = 0;			// pure virtual
	virtual String whatsolid() const = 0;				// pure virtual
	virtual Solid *clone() const = 0;					// pure virtual
	static int num_solids() { return count; }			// static member function
};

inline ostream & operator<<(ostream & os, const Solid & sh) {
	os << sh.whatsolid() << ": ";			// virtual call
	sh.output(os);								// virtual call
	return os;
}

inline istream & operator>>(istream & is, Solid & sh) {
	sh.input(is);								// virtual call
	return is;
}

class Sphere : public Solid {
private:
	double radius;
public:
	explicit Sphere(double r = 1) { radius = r; }
	double get_radius() const { return radius; }
	double surface_area() const { return 4 * PI * radius * radius; }
	double volume() const { return surface_area() * radius / 3; }
	void input(istream & is) { is >> radius; }
	void output(ostream & os) const { os << "radius " << radius; } 
	String whatsolid() const  { return "Sphere"; }
	Solid *clone() const { return new Sphere(*this); }
};

class Cube : public Solid {
private:
	double side;
public:
	explicit Cube(double s = 1) { side = s; }
	double get_side() const { return side; }
	double surface_area() const { return 6 * side * side; }
	double volume() const { return side * side * side; }
	void input(istream & is) { is >> side; }
	void output(ostream & os) const { os << "side " << side; } 
	String whatsolid() const  { return "Cube"; }
	Solid *clone() const { return new Cube(*this); }
};

class Cylinder : public Solid {
private:
	double height;
	double radius;
public:
	explicit Cylinder(double h = 1, double r = 1) { height = h; radius = r; }
	double get_height() const { return height; }
	double get_radius() const { return radius; }
	double surface_area() const { return 2 * PI * radius * (height + radius); }
	double volume() const { return PI * radius * radius * height; } 
	void input(istream & is) { is >> height >> radius; }
	void output(ostream & os) const { os << "height " << height 
					<< ", radius " << radius; } 
	String whatsolid() const  { return "Cylinder"; }
	Solid *clone() const { return new Cylinder(*this); }
};

int Solid::count = 0;
#endif
