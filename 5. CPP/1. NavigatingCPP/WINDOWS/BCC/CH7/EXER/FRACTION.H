#ifndef FRACTIONH
#define FRACTIONH
// Fraction.h - Fraction interface
#include <iostream.h>
#include <stdio.h>

class FractionError {						// Fraction exception object
private:
	char buf[80];
public:
	FractionError(const char *msg) { sprintf(buf, "Fraction: %s", msg); }
	void response() const { cerr << buf << endl; }
};

class Fraction {
private:
	double numerator;
	double denominator;
public:
	Fraction(double n = 0, double d = 1) { 
		if (d == 0)
			throw FractionError("denominator can't be zero");
		numerator = n; 
		denominator = d;
	}
	double getnumerator() const { return numerator; }
	double getdenomerator() const { return denominator; }
};

inline ostream & operator <<(ostream & os, const Fraction & f) {
	return os << f.getnumerator() / f.getdenomerator();
}

inline istream & operator >>(istream & is, Fraction & f) {
	double num, denom;
	cout << "Input numerator: ";
	is >> num;
	cout << "Input denominator: ";
	is >> denom;
	Fraction fnum(num, denom);			// check for zero denominator
	f = fnum;								// update Fraction f
	return is;
}

inline Fraction operator+(const Fraction & f1, const Fraction & f2) {
	return Fraction(f1.getnumerator()*f2.getdenomerator() + 
		f2.getnumerator()*f1.getdenomerator(),
				f1.getdenomerator()*f2.getdenomerator());
}

inline Fraction operator*(const Fraction & f1, const Fraction & f2) {
	return Fraction(f1.getnumerator()*f2.getnumerator(), 
		f1.getdenomerator()*f2.getdenomerator());
}
#endif
