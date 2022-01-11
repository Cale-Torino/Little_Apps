#ifndef RINTH
#define RINTH
// Range.h - Template Range number interface, member templates
#include <iostream.h>
#include <limits.h>
#include <stdio.h>

template <class TYPE>
class Range {
private:
	TYPE value;											// data value
	const TYPE minv;									// minimum
	const TYPE maxv;									// maximum
public:
// Constructors
	Range(int v) : minv(INT_MIN), maxv(INT_MAX), value(v) { }
	Range(float v) : minv(FLT_MIN), maxv(FLT_MAX), value(v) { }
	Range(double v) : minv(DBL_MIN), maxv(DBL_MAX), value(v) { }
	Range(const TYPE & v, const TYPE & min, const TYPE & max);
	template <class OLDTYPE>							// member template prototype
	Range(const Range<OLDTYPE> & r1);					// convert Range<OLDTYPE> to Range<TYPE>
// Modifiers
	Range<TYPE> & operator=(const Range<TYPE> &);		// assignment
// Selectors
	operator TYPE () const { return value; }			// convert Range<TYPE> to TYPE
	TYPE min() const { return minv; }					// get minimum
	TYPE max() const { return maxv; }					// get maximum
};

template <class TYPE> 									// member template definition
template <class OLDTYPE> 
inline Range<TYPE>::Range(const Range<OLDTYPE> & r1) :	// convert Range<OLDTYPE> to Range<TYPE>
	value(r1), minv(r1.min()), maxv(r1.max()) { }

template <class TYPE>
class RangeError {										// Range exception object
private:
	char buf[80];
public:
	RangeError(TYPE bv, const Range<TYPE> & robj) { sprintf(buf, 
		"Range: out of range (value = %g, min = %g, max = %g)",
			bv, robj.min(), robj.max());
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
istream & operator>>(istream &, Range<TYPE> &);

template <class TYPE>
ostream & operator<<(ostream &, const Range<TYPE> &);
#endif
