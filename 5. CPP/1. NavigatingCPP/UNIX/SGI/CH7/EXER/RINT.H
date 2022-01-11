#ifndef RINTH
#define RINTH
// Rint.h - Range integer class interface
#include <iostream.h>
#include <stdio.h>
#include <limits.h>

class Rint {
private:
	int value;											// data value
	const int minv;									// minimum
	const int maxv;									// maximum
public:
// Constructor
	Rint(int v = 0, int min = INT_MIN, int max = INT_MAX);
// Modifiers
	Rint & operator=(const Rint &);				// assignment
	Rint & operator+=(const Rint &);				// add and update
	Rint & operator-=(const Rint &);				// subtract and update
	Rint & operator/=(const Rint &);				// divide and update
	Rint & operator*=(const Rint &);				// multiply and update
	Rint & operator%=(const Rint &);				// modulus and update
	Rint & operator<<=(const Rint &);			// left shift and update
	Rint & operator>>=(const Rint &);			// right shift and update
	Rint & operator&=(const Rint &);				// bit AND and update
	Rint & operator|=(const Rint &);				// bit OR and update
	Rint & operator^=(const Rint &);				// bit XOR and update
	Rint & operator++();								// prefix (++a)
	Rint operator++(int);							// postfix (a++)
	Rint & operator--();								// prefix (--a)
	Rint operator--(int);							// postfix (a--)
// Selectors
	operator int () const { return value; }	// Rint to int
	int min() const { return minv; }				// get minimum
	int max() const { return maxv; }				// get maximum
};

class RintError {										// Rint exception object
private:
	char buf[80];
public:
	RintError(int bv, const Rint & robj) { sprintf(buf, 
		"Rint: Integer out of range (value = %d, min = %d, max = %d)",
			bv, robj.min(), robj.max());
	}
	void response() const { cerr << buf << endl; }
};

istream & operator>>(istream &, Rint &);
ostream & operator<<(ostream &, const Rint &);
#endif
