// Fraction.h - Fraction class interface with exception specifications
#include <iostream.h>

class FractionError {
private:
	double numerator;
public:
	FractionError(double n) throw() : numerator(n) { }
	double getnumerator() const throw () { return numerator; }
	void response() const throw () {
		cerr << "Zero denominator for numerator " << numerator << endl;
	}
};

class Fraction {
private:
	double numerator;
	double denominator;
public:
	Fraction(double n = 0, double d = 1) throw (FractionError) { 
		if (d == 0) 
			throw FractionError(n);
		numerator = n; 
		denominator = d;
	}
	double getnumerator() const throw() { return numerator; }
	double getdenominator() const throw() { return denominator; }
};

inline 
ostream & 
operator <<(ostream & os, const Fraction & f) throw () {
	return os << f.getnumerator() / f.getdenominator();
}

inline 
istream & 
operator >>(istream & is, Fraction & f) throw (FractionError)  {
	double n, d;
	cout << "Input numerator: ";
	is >> n;
	cout << "Input denominator: ";
	is >> d;
	Fraction fnum(n, d);						// check for zero denominator
	f = fnum;									// update Fraction f
	return is;
}
