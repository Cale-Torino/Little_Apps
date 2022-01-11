// Rint.C - Range int implementation
#include "Rint.h"

Rint::Rint(int v, int min, int max) : minv(min), maxv(max) {
	if (v >= minv && v <= maxv)
		value = v;
	else
		throw RintError(v, *this);					// throw exception
}

Rint & Rint::operator=(const Rint & r1) {
	if (r1 >= minv && r1 <= maxv)					// within range?
		value = r1;										// assign new value
	else
		throw RintError(r1, *this);				// throw exception
	return *this;
}

Rint & Rint::operator+=(const Rint & r1) { return *this = value + r1; }
Rint & Rint::operator-=(const Rint & r1) { return *this = value - r1; }
Rint & Rint::operator/=(const Rint & r1) { return *this = value / r1; }
Rint & Rint::operator*=(const Rint & r1) { return *this = value * r1; }
Rint & Rint::operator%=(const Rint & r1) { return *this = value % r1; }
Rint & Rint::operator<<=(const Rint & r1) { return *this = value << r1.value; }
Rint & Rint::operator>>=(const Rint & r1) { return *this = value >> r1.value; }
Rint & Rint::operator&=(const Rint & r1) { return *this = value & r1; }
Rint & Rint::operator|=(const Rint & r1) { return *this = value | r1; }
Rint & Rint::operator^=(const Rint & r1) { return *this = value ^ r1; }

Rint & Rint::operator++() {					// prefix (++a)
	return *this += 1;							// range check, return increment
}

Rint Rint::operator++(int) {					// postfix (a++)
	Rint tmp = *this;								// save old object
	*this += 1;										// range check, increment
	return tmp;										// return old object
}

Rint & Rint::operator--() {					// prefix (--a)
	return *this -= 1;							// range check, return decrement
}

Rint Rint::operator--(int) {					// postfix (a--)
	Rint tmp = *this;								// save old object
	*this -= 1;										// range check, decrement
	return tmp;										// return old object
}

istream & operator>>(istream & is, Rint & r1) {
	int temp;
	is >> temp;										// input integer
	r1 = temp;										// range check
	return is;
}

ostream & operator<<(ostream & os, const Rint & r1) {
	return os << '(' << static_cast<int>(r1) << ", " << r1.min() 
				<< ", " << r1.max() << ')';
}
