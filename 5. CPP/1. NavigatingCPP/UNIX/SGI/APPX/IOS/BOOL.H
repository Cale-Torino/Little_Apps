#ifndef BOOLH
#define BOOLH
// bool.h - bool data type

enum { false, true };

class bool {
private:
	enum boolean { false, true };
	boolean b;
public:
// Constructors
	bool(boolean bv = false) : b(bv) { }
	bool(int bv) : b(bv == 0 ? false : true) { }
// Member functions
	operator int() const { return int(b); }
};
#endif
