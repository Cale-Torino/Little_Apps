// Rint.C - Range int implementation
#include "Rint.h"

Rint::operator int () const throw () { return value; }
int Rint::min() const throw () { return minv; }
int Rint::max() const throw () { return maxv; }

RintError::RintError(int mn, int mx, int bd) throw () :
			 minval(mn), maxval(mx), badval(bd)	{ } 
RintError::~RintError()	throw () { }
int RintError::getminval() const throw () { return minval; }
int RintError::getmaxval() const throw () { return maxval; }
int RintError::getbadval() const throw () { return badval; }

InitializerError::InitializerError(int badmin, int badmax) throw () : 
				RintError(badmin, badmax) { }

void InitializerError::response() const throw () {
	cerr << "Range Int initializer error:" << endl;
	cerr << "min value = " << getminval()
			<< ", max value = " << getmaxval() << endl;
}

RangeError::RangeError(const Rint & err, int badvalue) throw () : 
				RintError(err.min(), err.max(), badvalue)  { }

UnderFlow::UnderFlow(const Rint & err, int badvalue) throw () : 
				RangeError(err, badvalue) { }

void UnderFlow::response() const throw () {
	cerr << "Range Int Underflow:" << endl;
	cerr << "bad value = " << getbadval() 
			<< ", Minimum value = " << getminval() << endl;
}

OverFlow::OverFlow(const Rint & err, int badvalue) throw () : 
				RangeError(err, badvalue) { }

void OverFlow::response() const throw () {
	cerr << "Range Int Overflow:" << endl;
	cerr << "bad value = " << getbadval() 
			<< ", Maximum value = " << getmaxval() << endl;
}

Rint::Rint(int v, int min, int max) throw (InitializerError) : 
		minv(min), maxv(max) {
	if (v >= minv && v <= maxv)
		value = v;
	else
		throw InitializerError(min, max);		// throw exception
}

Rint & Rint::operator=(const Rint & r1)  throw (RangeError) {
	if (r1 < minv)										// underflow
		throw UnderFlow(*this, r1);
	else if (r1 > maxv)								// overflow
		throw OverFlow(*this, r1);
	else													// it's within range
		value = r1;										// assign new value
	return *this;
}

Rint & Rint::operator+=(const Rint & r1) throw (RangeError) { 
	return *this = value + r1;
}
Rint & Rint::operator-=(const Rint & r1) throw (RangeError) { 
	return *this = value - r1;
}
Rint & Rint::operator/=(const Rint & r1) throw (RangeError) { 
	return *this = value / r1;
}
Rint & Rint::operator*=(const Rint & r1) throw (RangeError) { 
	return *this = value * r1;
}
Rint & Rint::operator%=(const Rint & r1) throw (RangeError) { 
	return *this = value % r1;
}

Rint & Rint::operator++() throw (RangeError) {		// prefix (++a)
	return *this += 1;							// range check, return increment
}

Rint Rint::operator++(int) throw (RangeError) {		// postfix (a++)
	Rint tmp = *this;								// save old object
	*this += 1;										// range check, increment
	return tmp;										// return old object
}

Rint & Rint::operator--() throw (RangeError) {		// prefix (--a)
	return *this -= 1;							// range check, return decrement
}

Rint Rint::operator--(int) throw (RangeError) {		// postfix (a--)
	Rint tmp = *this;								// save old object
	*this -= 1;										// range check, decrement
	return tmp;										// return old object
}

istream & operator>>(istream & is, Rint & r1)  throw (RangeError) {
	int temp;
	is >> temp;										// input integer
	r1 = temp;										// range check
	return is;
}

ostream & operator<<(ostream & os, const Rint & r1)  throw () {
	return os << '(' << static_cast<int>(r1) << ", " << r1.min() 
				<< ", " << r1.max() << ')';
}
