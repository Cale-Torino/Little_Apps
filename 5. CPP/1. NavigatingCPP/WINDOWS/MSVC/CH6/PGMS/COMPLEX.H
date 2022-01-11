#ifndef COMPLEXH
#define COMPLEXH
// Complex.h - Complex class interface 
#include <iostream.h>

class Complex {
private:
	double realp;											// real part 
	double imagp;											// imaginary part
public:
	Complex(double r = 0, double i = 0) : realp(r), imagp(i) { }
	Complex operator-() const;							// unary negation
	Complex & operator-=(const Complex &);			// subtraction update
	double real() const { return realp; }
	double imag() const { return imagp; }
	void print() const;									// display Complex
};

inline Complex operator-(const Complex & c1, const Complex & c2) {
	return Complex(c1.real() - c2.real(), c1.imag() - c2.imag());
}

inline Complex Complex::operator-() const {			// unary negation
	return Complex(-realp, -imagp);						// return Complex object 
}

inline Complex & Complex::operator-=(const Complex & c1) {
	return *this = *this - c1;
}

inline void Complex::print() const {
	cout << '(' << real() << ", " << imag() << ')' << endl;
}
#endif
