#ifndef STRINGH
#define STRINGH
// String3.h - String class interface, different istream version
#include <iostream.h>
#include <stdio.h>
#include <string.h>

class String {											// class String
	friend class SubString;							// friend class
private:
	char *s;
	int len;
	void copy(const String &);
	void free();
	String(int);										// private constructor
	void range(int) const;							// subscript range check
	void poscount(int, int) const;				// check substring position count
public:
// Constructors
	String(const char * = "");						// char string constructor
	String(const String & a) { copy(a); }		// copy constructor
// Destructor
	~String() { free(); }
// Modifiers
	String & operator=(const String & a) {		// assignment
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
	String & operator+=(const String &);		// concatenation
	String & operator-=(const String &);		// concatenate with ' '
	char & operator[](int);							// non-const subscripts
	SubString operator()(int, int);				// non-const substrings
// Selectors
	const char & operator[](int) const;			// const subscripts
	const String operator()(int, int) const;	// const substrings
	operator const char * () const { return s; }			// conversion
	int length() const { return len; }
};

class SubString {										// Substring class
private:
	String & str;
	int pos;
	int count;
public:
	SubString(String & s, int posn, int countpos) : str(s),
		pos(posn), count(countpos) { }
	String & operator=(const String &);						// lvalue
	String & operator=(const SubString &);					// lvalue
	operator String () const;									// rvalue
};

class StringError {									// String exception object
private:
	char buf[80];
public:
	StringError(int index) {
		sprintf(buf, "String: index %d out of bounds", index);
	}
	StringError(int position, int count, const char *ps) { 
		sprintf(buf, "String: Illegal substring for \"%.20s\": "
			"pos = %d, count = %d", ps, position, count);
	}
	void response() const { cerr << buf << endl; }
};

ostream & operator<<(ostream &, const String &);
istream & operator>>(istream &, String &);

String operator+(const String &, const String &);
String operator+(const char *, const String &);
String operator+(const String &, const char *);
String operator-(const String &, const String &);
String operator-(const char *, const String &);
String operator-(const String &, const char *);

bool operator==(const String & s1, const String & s2);
bool operator==(const char *s1, const String & s2); 
bool operator==(const String & s1, const char *s2);
bool operator!=(const String & s1, const String & s2);
bool operator!=(const char *s1, const String & s2);
bool operator!=(const String & s1, const char *s2);
bool operator>(const String & s1, const String & s2);
bool operator>(const char *s1, const String & s2);
bool operator>(const String & s1, const char *s2);
bool operator>=(const String & s1, const String & s2);
bool operator>=(const char *s1, const String & s2);
bool operator>=(const String & s1, const char *s2);
bool operator<(const String & s1, const String & s2);
bool operator<(const char *s1, const String & s2);
bool operator<(const String & s1, const char *s2);
bool operator<=(const String & s1, const String & s2);
bool operator<=(const char *s1, const String & s2);
bool operator<=(const String & s1, const char *s2);
#endif
