#ifndef ROMANH
#define ROMANH
// Roman.h - Roman interface

const int Roman_max = 20;

class Roman {
private:
	int value;										// integer value
	char s[Roman_max];							// Roman String
	void convert_Roman(); 						// converts integer to Roman string
public:
// Constructors
	Roman(int n = 1) { value = n; convert_Roman(); }
// Member Functions
	Roman & operator+=(const Roman &);		// updates
	const char *getroman() const { return s; }
	int getnum() const { return value; }
};

inline Roman operator+(const Roman & r1, const Roman & r2) {
	return Roman(r1.getnum() + r2.getnum());
}

inline Roman & Roman::operator+=(const Roman & r1) { 
	return *this = *this + r1; 
}
#endif

/***********************************************************************

NOTES:
1. Here is the original code.

	Roman & Roman::operator+=(const Roman & r1) { 				// member
		value += r1.value; 
		convert_Roman();
		return *this; 
	}

	Roman operator+(const Roman & r1, const Roman & r2) {		// friend
		Roman result;
		result.value = r1.value + r2.value;
		result.convert_Roman();
		return result;
	}

2. Operator+() is inefficient because it calls convert_Roman() 
	TWICE (first when result is declared and again before we return
	the result).  This is unnecessary, since we should be able to build a new
	result with a single constructor and make one call to convert_Roman().
	operator+() does NOT have to be a friend either, since
	member function getnum() accesses the data that we need to
	compute a new result.

3. In this version, we use objects as return values to call a constructor
	with a computed result. The function convert_Roman() is only called ONCE.
	Note that operator+() is not a friend in this design.

*/
