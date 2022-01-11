#ifndef PTRH
#define PTRH
// Ptr.h - Smart pointer (template)
#include <iostream.h>
#include <stdio.h>

class PtrError {							// Ptr exception object
private:
	char buf[80];
public:
	PtrError(const char *msg) { sprintf(buf, "Ptr: %s", msg); }
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
class Ptr {
private:
	TYPE *const a;											// const array address
	TYPE *p;													// ptr to array element
	int len;													// length of array
public:
// Constructors
	Ptr(TYPE *pt, int size) : a(pt) { 
		if (pt == 0)
			throw PtrError("Ptr has zero value");
		p = pt; len = size; 
	}
	template <class NEWTYPE>							// member template
	Ptr(const Ptr<NEWTYPE> & pn) : a(pn) {			// copy constructor
		if (pn == 0)
			throw PtrError("Ptr has zero value");
		p = pn; len = pn.length(); 
	}
// Modifiers
	TYPE * operator++() { 								// prefix
		if (p+1 < a || p+1 >= a+len)
			throw PtrError("Ptr out of bounds");
		return ++p;
	}
	TYPE * operator++(int) { 							// postfix
		if (p < a || p >= a+len)
			throw PtrError("Ptr out of bounds");
		return p++;
	}
	TYPE * operator--() { 								// prefix
		if (p-1 < a || p-1 >= a+len) 
			throw PtrError("Ptr out of bounds");
		return --p;
	}
	TYPE * operator--(int) { 							// postfix
		if (p < a || p >= a+len) 
			throw PtrError("Ptr out of bounds");
		return p--;
	}
	TYPE & operator[](int i) { 						// subscript
		if (p+i < a || p+i >= a+len) 
			throw PtrError("Ptr out of bounds");
		return p[i];
	}
// Selectors
	const TYPE & operator[](int i) const {			// const subscript 
		if (p+i < a || p+i >= a+len) 
			throw PtrError("Ptr out of bounds");
		return p[i];
	}
	template <class NEWTYPE>							// member template
	operator Ptr<NEWTYPE> () const 					// conversion
		{ return Ptr<NEWTYPE>(p); }

	operator TYPE * () const { return p; }			// conversion
	TYPE & operator * () const {						// dereference 
		if (p == 0)
			throw PtrError("Ptr has zero value");
		return *p;
	}
	int length() const { return len; }
};
#endif
