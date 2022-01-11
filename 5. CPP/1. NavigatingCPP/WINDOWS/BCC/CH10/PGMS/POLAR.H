#ifndef POLARH
#define POLARH
// Complex.h - Complex class interface 
#include <iostream.h>
#include <math.h>
#include "Complex.h"

class Polar {
private:
	double radius;											// real part 
	double costheta;
	double sintheta;
public:
	Polar(double r = 0) { radius = r; }
	Polar(const Complex & c) {
		radius = sqrt(c.real()*c.real() + c.imag()*c.imag());
		costheta = c.real()/radius;
		sintheta = c.imag()/radius;
  	}
	double cos() const { return costheta; }
	double sin() const { return sintheta; }
	double getradius() const { return radius; }
};

inline ostream & operator<<(ostream & os, const Polar & p) {
	return os << "radius = " << p.getradius() << " cos(theta) = " << p.cos() 
				<< " sin(theta) = " << p.sin();
}
#endif
