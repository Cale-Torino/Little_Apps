// Fraction.h - Fraction class interface
#include <iostream.h>

class FractionError {
private:
	double numerator;
public:
	FractionError(double n) : numerator(n) { }
	double getnumerator() const { return numerator; }
	void response() const {
		cerr << "Zero denominator for numerator " << numerator << endl;
	}
};

class Fraction {
private:
	double numerator;
	double denominator;
public:
	Fraction(double n = 0, double d = 1) { 
		if (d == 0) 
			throw FractionError(n);
		numerator = n; 
		denominator = d;
	}
	double getnumerator() const { return numerator; }
	double getdenominator() const { return denominator; }
};

inline ostream & operator <<(ostream & os, const Fraction & f) {
	return os << f.getnumerator() / f.getdenominator();
}

inline istream & operator >>(istream & is, Fraction & f) {
	double n, d;
	cout << "Input numerator: ";
	is >> n;
	cout << "Input denominator: ";
	is >> d;
	Fraction fnum(n, d);						// check for zero denominator
	f = fnum;									// update Fraction f
	return is;
}
