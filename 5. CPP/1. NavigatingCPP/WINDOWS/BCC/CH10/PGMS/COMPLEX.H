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
// Modifiers
	Complex & operator+=(const Complex &);			// addition update
	Complex & operator-=(const Complex &);			// subtraction update
	Complex & operator*=(const Complex &);			// multiply update
	void real(double r) { realp = r; }
	void imag(double i) { imagp = i; }
// Selectors
	Complex operator-() const;							// unary negation
	Complex operator+() const;							// unary +
	double real() const { return realp; }
	double imag() const { return imagp; }
};

inline int operator==(const Complex & c1, const Complex & c2) { 
	return (c1.real() == c2.real() && c1.imag() == c2.imag());
}

inline int operator!=(const Complex & c1, const Complex & c2) { 
	return (c1.real() != c2.real() || c1.imag() != c2.imag());
}

inline Complex Complex::operator+() const {				// unary +
	return Complex(realp, imagp); 
}

inline Complex Complex::operator-() const {				// unary -
	return Complex(-realp, -imagp); 
}

inline Complex operator+(const Complex & c1, const Complex & c2) {
	return Complex(c1.real() + c2.real(), c1.imag() + c2.imag());
}

inline Complex operator-(const Complex & c1, const Complex & c2) {
	return Complex(c1.real() - c2.real(), c1.imag() - c2.imag());
}

inline Complex operator*(const Complex & c1, const Complex & c2) {
	return Complex(c1.real() * c2.real() - c1.imag() * c2.imag(),
						c1.real() * c2.imag() + c1.imag() * c2.real());
}

inline Complex & Complex::operator+=(const Complex & c) {
	return *this = *this + c;
}

inline Complex & Complex::operator-=(const Complex & c) {
	return *this = *this - c;
}

inline Complex & Complex::operator*=(const Complex & c) {
	return *this = *this * c;
}

inline ostream & operator<<(ostream & s, const Complex & z) {
	return s << '(' << z.real() << ", " << z.imag() << ')';
}
#endif

/****************************************************************

	1.  Here is a non-member version of unary -.

		  class Complex {
		  private:
			  . . .
		  public:
			  . . .
			  friend Complex operator-(const Complex &);				// unary -
		  };

		  inline Complex operator-(const Complex & c1) {			// unary -
			  Complex result;
			  result.realp = -c1.realp;
			  result.imagp = -c1.imagp;
			  return result;
		  }

	2.  This approach is not as efficient, since we call the void Complex
		 constructor first for result, then change its realp and imagp
		 before we return the result.

	3.  Note that operator-() must be a friend with this approach.

*/
