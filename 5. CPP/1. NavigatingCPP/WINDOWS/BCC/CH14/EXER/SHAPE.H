#ifndef SHAPEH
#define SHAPEH
// Shape.h - Base class Shape interface
#include <iostream.h>
#include <math.h>
#include <typeinfo.h>
#include "String.h"
#define PI M_PI

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
	virtual bool equals(const Shape &) const = 0;	// pure virtual
	virtual Shape *clone() const = 0;					// pure virtual
	String whatshape() const { return typeid(*this).name(); }
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
	bool equals(const Shape &) const;
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
	bool equals(const Shape &) const;
	Square *clone() const { return new Square(*this); }
};

class RTriangle : public Shape {				// right triangle
private:
	double height;
	double base;
public:
	explicit RTriangle(double h = 1, double b = 1) {
		height = h; base = b;
	}
	double get_height() const { return height; }
	double get_base() const { return base; }
	double area() const { return height * base / 2; }
	double perimeter() const 
		{ return height + base + 
				sqrt(height * height + base * base); }
	void input(istream & is) { is >> height >> base; } 
	void output(ostream & os) const { os << "height " << height 
					<< ", base " << base; } 
	bool equals(const Shape &) const;
	RTriangle *clone() const { return new RTriangle(*this); }
};

inline bool operator==(const Shape & s1, const Shape & s2) {
	return s1.equals(s2);							// virtual call
}

inline bool Circle::equals(const Shape & sh) const {
	const Circle *cp = dynamic_cast<const Circle *>(&sh);
	if (cp)
		return radius == cp->radius;
	return false;
}

inline bool Square::equals(const Shape & sh) const {
	const Square *sp = dynamic_cast<const Square *>(&sh);
	if (sp)
		return side == sp->side;
	return false;
}

inline bool RTriangle::equals(const Shape & sh) const {
	const RTriangle *tp = dynamic_cast<const RTriangle *>(&sh);
	if (tp)
		return base == tp->base && height == tp->height;
	return false;
}
#endif
