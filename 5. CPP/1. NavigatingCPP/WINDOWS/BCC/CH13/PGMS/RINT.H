#ifndef RINTH
#define RINTH
// Rint.h - Range integer class interface
#include <iostream.h>
#include <stdio.h>
#include <limits.h>

class RintError {
private:
	int minval;
	int maxval;
	int badval;
public:
	RintError(int mn, int mx, int bd = 0)				throw ();
	virtual ~RintError() 									throw ();
	virtual void response() const 						throw () = 0;
	int getminval() const 									throw ();
	int getmaxval() const 									throw ();
	int getbadval() const 									throw ();
};

class InitializerError : public RintError {
public:
	InitializerError(int badmin, int badmax) 			throw ();
	void response() const									throw ();
};

class Rint;

class RangeError: public RintError {					// abstract base
public:
	RangeError(const Rint &, int)							throw ();
};

class UnderFlow : public RangeError {
public:
	UnderFlow(const Rint & err, int badvalue)			throw ();
	void response() const 									throw ();
};

class OverFlow : public RangeError {
public:
	OverFlow(const Rint & err, int badvalue)			throw ();
	void response() const									throw ();
};

class Rint {
private:
	int value;											// data value
	const int minv;									// minimum
	const int maxv;									// maximum
public:
// Constructor
	Rint(int v = 0, int min = INT_MIN, 
		int max = INT_MAX)							throw (InitializerError);
// Modifiers
	Rint & operator=(const Rint &) 				throw (RangeError);
	Rint & operator+=(const Rint &) 				throw (RangeError);
	Rint & operator-=(const Rint &) 				throw (RangeError);
	Rint & operator/=(const Rint &) 				throw (RangeError);
	Rint & operator*=(const Rint &) 				throw (RangeError);
	Rint & operator%=(const Rint &) 				throw (RangeError);
	Rint & operator++() 								throw (RangeError);
	Rint operator++(int) 							throw (RangeError);
	Rint & operator--() 								throw (RangeError);
	Rint operator--(int) 							throw (RangeError);
// Selectors
	operator int () const 							throw ();
	int min() const 									throw ();
	int max() const 									throw ();
};

istream & operator>>(istream &, Rint &)		throw (RangeError);
ostream & operator<<(ostream &, const Rint &) throw ();
#endif
