#ifndef STRINGH
#define STRINGH
// String.h - String class interface, reference counts
#include <iostream.h>
#include <stdio.h>
#include <string.h>

class String_ref {								// String reference node
	friend class String;							// friend class
	friend class SubString;						// friend class
	friend class SubScript;						// friend class
private:
	char *s;											// pointer to data
	int len;											// length of String
	int refcount;									// reference count
// Constructors
	String_ref(int);								// length constructor
	String_ref(const char * = "");			// char string constructor
	String_ref(const String_ref &, const String_ref &);
	String_ref(const String_ref &, const String_ref &, char);
// Destructor
	~String_ref() { delete [] s; }
};

class String {											// class String
	friend class SubString;							// friend class
	friend class SubScript;							// friend class
private:
	String_ref *pref;									// pointer to reference node
	void copy(const String &);
	void newcopy();									// make a new String copy
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
	SubString operator()(int, int);				// non-const substrings
	SubScript operator[](int);						// non-const subscripts
// Selectors
	const char & operator[](int) const;			// const subscripts
	const String operator()(int, int) const;	// const substrings
	operator const char * () const { return pref->s; }			// conversion
	int length() const { return pref->len; }
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

class SubScript {										// Subcript class
private:
	String & str;
	int index;
public:
	SubScript(String & s, int i) : str(s), index(i) { }
	char & operator=(char);									// lvalue
	char & operator=(const SubScript &);				// lvalue
	operator char () const;									// rvalue
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
