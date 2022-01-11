#ifndef ARRAYH
#define ARRAYH
// Array.h - One dimensional Array object interface with exceptions
#include <iostream.h>

class ArrayError {								// abstract base
private:
	int badvalue;
public:
	ArrayError(int bv) : badvalue(bv) { }
	virtual ~ArrayError() { }
	virtual void response() const = 0;
	int getbadvalue() const { return badvalue; }
};

class SizeError : public ArrayError {
public:
	SizeError(int size) : ArrayError(size) { }
	void response() const { 
		cerr << "Array size error, bad size = " 
				<< getbadvalue() << endl;
	}
};

class NoMemory : public ArrayError {
public:
	NoMemory(int size) : ArrayError(size) { }
	void response() const { 
		cerr << 
			"No memory for operator new, requested mem = " 
				<< getbadvalue() << endl;
	}
};

class RangeError : public ArrayError {				// abstract base
private:
 	int maxindex;
public:
	RangeError(int index, int len) :
		ArrayError(index), maxindex(len-1) { }
	int getmaxindex() const { return maxindex; }
};

class LowerBoundError : public RangeError {
public:
	LowerBoundError(int index, int len) : 
		RangeError(index, len) { }
	void response() const { 
		cerr << "Lower Bound Range Error, Bad Index = "
					<< getbadvalue() << ", Min Index = 0" << endl;
	}
};

class UpperBoundError : public RangeError {
public:
	UpperBoundError(int index, int len) : 
		RangeError(index, len) { }
	void response() const { 
		cerr << "Upper Bound Range Error, Bad Index = "
					<< getbadvalue() << ", Max Index = "
						<< getmaxindex() << endl;
	}
};

template <class TYPE>
class Array {
private:
	TYPE *v;
	int len; 
	void range(int) const;
	void copy(const Array<TYPE> &);
	void free() { delete [] v; }
public:
// Constructors
	explicit Array(int length = 1);
	Array(const Array<TYPE> & a) { copy(a); } 
	~Array() { free(); }
// Modifiers
	Array<TYPE> & operator=(const Array<TYPE> &);
	inline TYPE & operator[](int);
// Selectors
	inline const TYPE & operator[](int) const;
	int length() const { return len; }
};

template <class TYPE>
inline TYPE & Array<TYPE>::operator[](int i) {
#ifndef NORANGE
	range(i);
#endif
	return v[i];
}

template <class TYPE>
inline const TYPE & Array<TYPE>::operator[](int i) const {
#ifndef NORANGE
	range(i);
#endif
	return v[i];
}
#include "Array.C"
#endif
