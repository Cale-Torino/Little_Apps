#ifndef DOUBLEH
#define DOUBLEH
// Double.h - Double class with exception objects
#include <iostream.h>
#include <stdio.h>

class DivideByZero {						// Divide exception object
private:
	char buf[80];
public:
	DivideByZero(double numerator) {						// Divide numerator
		sprintf(buf, "Double: divide by zero with numerator %g", numerator);
	}
	void response() const { cerr << buf << endl; }
};

class Double {
private:
	double d;
	void divide(double & num) const {
		if (d == 0)
			throw DivideByZero(num);
		num /= d;
	}
public:
	Double(double v = 0) : d(v) { }
	operator double () const { return d; }
	Double & operator+=(const Double & d1) { return *this = d + d1; }
	Double & operator-=(const Double & d1) { return *this = d - d1; }
	Double & operator*=(const Double & d1) { return *this = d * d1; }
	Double & operator/=(const Double & denom) 
		{ denom.divide(d); return *this; }
	friend double & operator/=(double & num, const Double & denom) 
		{ denom.divide(num); return num; }
};

inline Double operator/(const Double & d1, const Double & denom) {
  Double result = d1;
  return result /= denom;
}

inline Double operator/(const Double & d1, double denom) {
	return d1 / static_cast<Double>(denom);
}

inline Double operator/(double d1, const Double & denom) {
	return static_cast<Double>(d1) / denom;
}
#endif
