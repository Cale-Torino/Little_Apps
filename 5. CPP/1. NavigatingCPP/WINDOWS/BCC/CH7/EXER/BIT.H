#ifndef BITH
#define BITH
// Bit.h - Bit class interface, lvalue/rvalue for bitslices
#include <iostream.h>
#include <stdio.h>

class Bit {												// class Bit
	friend class BitSlice;							// friend class
private:
	bool *b;
	int len;
	void copy(const Bit &);
	void free();
	void range(int) const;							// subscript range check
	void poscount(int, int) const;				// check Bitslice position count
public:
// Constructors
	Bit(int = sizeof(int)*8, unsigned int = 0);	// Bit constructor
	Bit(const Bit & a) { copy(a); }				// copy constructor
// Destructor
	~Bit() { free(); }
// Modifiers
	Bit & operator=(const Bit & a) {				// assignment
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
	bool & operator[](int);							// non-const subscripts
	BitSlice operator()(int, int);				// non-const Bitslice
// Selectors
	const bool & operator[](int) const;			// const subscripts
	const Bit operator()(int, int) const;		// const Bitslice
	int length() const { return len; }
};

class BitSlice {										// BitSlice class
private:
	Bit & bs;
	int pos;
	int count;
public:
	BitSlice(Bit & b, int posn, int countpos) : bs(b),
		pos(posn), count(countpos) { }
	Bit & operator=(const Bit &);							// lvalue
	Bit & operator=(const BitSlice &);					// lvalue
	operator Bit () const;									// rvalue
};

class BitError {									// Bit exception object
private:
	char buf[80];
public:
	BitError(int index) {
		sprintf(buf, "Bit: index %d out of bounds", index);
	}
	BitError(int position, int count) { 
		sprintf(buf, "Bit: Illegal bit slice for pos = %d, count = %d",  
						position, count);
	}
	void response() const { cerr << buf << endl; }
};

ostream & operator<<(ostream &, const Bit &);
#endif
