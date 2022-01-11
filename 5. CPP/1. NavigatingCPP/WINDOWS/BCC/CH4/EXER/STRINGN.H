#ifndef STRINGN
#define STRINGN
// StringN.h - StringN class description
#include <iostream.h>
#include <stdio.h>
#include <memory.h>

class StringNError {									// StringN exception object
private:
	char buf[80];
public:
	StringNError(int sizerr) {					// StringN length error
		sprintf(buf, "StringN: %d is an illegal length", sizerr);
	}
	void response() const { cerr << buf << endl; }
};

class StringN {										// StringN holds NULL bytes
private:
	char *s;												// points to character data
	int len;												// length
public:
// Constructors
	StringN() { s = 0; len = 0; }					// default constructor
	StringN(int n, const char *p) {				// for Strings with NULLS 
		if (n <= 0)
			throw StringNError(n);					// illegal length
		s = new char[len = n];
		memcpy(s, p, len);							// copy (including NULL bytes)
	}
	StringN(const StringN &);						// copy constructor

// Destructor
	~StringN() { delete [] s; }

// Member functions
	void print() const;
	int length() const { return len; }
};
#endif
