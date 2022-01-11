#ifndef ROMANH
#define ROMANH
// Roman2.h - Roman class

const int Roman_max = 20;

class Roman {
private:
	int value;										// decimal value
	mutable char s[Roman_max];					// Roman String
	void convert_Roman() const; 				// convert to Roman string
public:
// Constructors
	Roman(int n = 1) { value = n; }

// Member Functions
	const char *getroman() const { convert_Roman(); return s; }
	int getnum() const { return value; }
};
#endif
