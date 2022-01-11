#ifndef ROMANH
#define ROMANH
// Roman3.h - Roman class, integer to Roman conversions
#include <stdio.h>
#include <string.h>

const int Roman_max = 20;

class RomanError {
private:
	char msg[80];
public:
	RomanError(const char *rs) {
		sprintf(msg, "Roman: %s is an illegal Roman string", rs);
	}
	void response() const { cerr << msg << endl; }
};

class Roman {
private:
	int value;											// decimal value
	char s[Roman_max];								// Roman String
	void convert_Roman(); 							// convert to Roman string
	int convert_decimal(const char *);			// convert to decimal integer
public:
// Constructors
	Roman(int n = 1) { value = n; convert_Roman(); }
	Roman(const char *rs) { value = convert_decimal(rs); strcpy(s, rs); }

// Note: no copy constructor required, since memberwise copies will
//			initialize properly.

// Member Functions
	const char *getroman() const { return s; }
	int getnum() const { return value; }
};
#endif
