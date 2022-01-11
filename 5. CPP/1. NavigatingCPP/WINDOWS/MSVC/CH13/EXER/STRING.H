#ifndef STRINGH
#define STRINGH
// String.h - String class interface, exception specifications
#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include "except.h"

class StringError : public exception {			// String exception object
private:
	char buf[80];
public:
	StringError(int index) throw() {
		sprintf(buf, "String: index %d out of bounds", index);
	}
	StringError(int position, int count, const char *ps) throw() { 
		sprintf(buf, "String: Illegal substring for \"%.20s\": "
			"pos = %d, count = %d", ps, position, count);
	}
	const char *what() const throw() { return buf; }
	void response() const throw() { cerr << buf << endl; }
};

class String {											// class String
	friend class SubString;							// friend class
private:
	char *s;
	int len;
	void copy(const String &) throw (bad_alloc);
	void free() throw ();
	String::String(int) throw (bad_alloc);				// private constructor
	void range(int) const throw (StringError);// subscript range check
	void poscount(int, int) const throw (StringError);	// check substr pos,count
public:
// Constructors
	String::String(const char * = "") throw (bad_alloc);	// char string constr
	String(const String & a) throw (bad_alloc){ 
		copy(a); 											// copy constructor
	}
// Destructor
	~String() throw() { free(); }
// Modifiers
	String & operator=(const String & a) throw (bad_alloc) {
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
	String & operator+=(const String &) throw (bad_alloc);	// concatenation
	String & operator-=(const String &) throw (bad_alloc);	// concatenate ' '
	char & operator[](int) throw (StringError);			// non-const subscripts
	SubString operator()(int, int) throw();				// non-const substrings
// Selectors
	const char & operator[](int) const throw (StringError);	// const subscripts
	const String operator()(int, int) const throw (bad_alloc);	// const substrs
	operator const char * () const throw() { return s; }			// conversion
	int length() const throw() { return len; }
};

class SubString {										// Substring class
private:
	String & str;
	int pos;
	int count;
public:
	SubString(String & s, int posn, int countpos) throw() : str(s),
		pos(posn), count(countpos) { }
	String & operator=(const String &) throw();						// lvalue
	String & operator=(const SubString &) throw();					// lvalue
	operator String () const throw (bad_alloc);						// rvalue
};

ostream & operator<<(ostream &, const String &) throw();
istream & operator>>(istream &, String &) throw (bad_alloc);

String operator+(const String &, const String &) throw (bad_alloc);
String operator+(const char *, const String &) throw (bad_alloc);
String operator+(const String &, const char *) throw (bad_alloc);
String operator-(const String &, const String &) throw (bad_alloc);
String operator-(const char *, const String &) throw (bad_alloc);
String operator-(const String &, const char *) throw (bad_alloc);

bool operator==(const String & s1, const String & s2) throw();
bool operator==(const char *s1, const String & s2) throw(); 
bool operator==(const String & s1, const char *s2) throw();
bool operator!=(const String & s1, const String & s2) throw();
bool operator!=(const char *s1, const String & s2) throw();
bool operator!=(const String & s1, const char *s2) throw();
bool operator>(const String & s1, const String & s2) throw();
bool operator>(const char *s1, const String & s2) throw();
bool operator>(const String & s1, const char *s2) throw();
bool operator>=(const String & s1, const String & s2) throw();
bool operator>=(const char *s1, const String & s2) throw();
bool operator>=(const String & s1, const char *s2) throw();
bool operator<(const String & s1, const String & s2) throw();
bool operator<(const char *s1, const String & s2) throw();
bool operator<(const String & s1, const char *s2) throw();
bool operator<=(const String & s1, const String & s2) throw();
bool operator<=(const char *s1, const String & s2) throw();
bool operator<=(const String & s1, const char *s2) throw();
#endif
