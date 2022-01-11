#ifndef SHAPEH
#define SHAPEH
// Shape.h - Base class Shape interface
#include <iostream.h>
#include <math.h>
#include <string>
#define PI M_PI

using namespace std;

class Shape {													// abstract base
private:
	static int count;											// static data member
public:
	Shape() { count++; }										// constructor
	Shape(const Shape &) { count++; }					// copy constructor
	virtual ~Shape() { count--; }							// virtual destructor
	virtual double area() const = 0;						// pure virtual
	virtual double perimeter() const = 0;				// pure virtual
	virtual void input(istream &) = 0;					// pure virtual
	virtual void output(ostream &) const = 0;			// pure virtual
	virtual string whatshape() const = 0;				// pure virtual
	virtual Shape *clone() const = 0;					// pure virtual
	static int num_shapes() { return count; }			// static member function
};

inline ostream & operator<<(ostream & os, const Shape & sh) {
	os << sh.whatshape() << ": ";			// virtual call
	sh.output(os);								// virtual call
	return os;
}

inline istream & operator>>(istream & is, Shape & sh) {
	sh.input(is);								// virtual call
	return is;
}

class Circle : public Shape {
private:
	double radius;
public:
	explicit Circle(double r = 1) { radius = r; }
	double get_radius() const { return radius; }
	double area() const { return PI * radius * radius; }
	double perimeter() const { return 2 * PI * radius; }
	void input(istream & is) { is >> radius; } 
	void output(ostream & os) const { os << "radius " << radius; } 
	string whatshape() const { return "Circle"; }
	Circle *clone() const { return new Circle(*this); }
};

class Square : public Shape {
private:
	double side;
public:
	explicit Square(double s = 1) { side = s; }
	double get_side() const { return side; }
	double area() const { return side * side; }
	double perimeter() const { return 4 * side; }
	void input(istream & is) { is >> side; } 
	void output(ostream & os) const { os << "side " << side; } 
	string whatshape() const { return "Square"; }
	Square *clone() const { return new Square(*this); }
};

class RTriangle : public Shape {						// right triangle
private:
	double height;
	double base;
public:
	explicit RTriangle(double h = 1, double b = 1) { height = h; base = b; }
	double get_height() const { return height; }
	double get_base() const { return base; }
	double area() const { return height * base / 2; }
	double perimeter() const 
		{ return height + base + 
		 sqrt(height * height + base * base); }
	void input(istream & is) { is >> height >> base; } 
	void output(ostream & os) const { os << "height " << height 
					<< ", base " << base; } 
	string whatshape() const { return "RTriangle"; }
	RTriangle *clone() const { return new RTriangle(*this); }
};

int Shape::count = 0;
#endif
