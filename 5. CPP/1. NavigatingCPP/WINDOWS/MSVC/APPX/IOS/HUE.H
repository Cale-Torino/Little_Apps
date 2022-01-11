#ifndef HUEH
#define HUEH
// Hue.h - Hue data type
#include <iostream.h>
#include <iomanip.h>

struct Hue {
	char name[10];
	int shade;
	float scale;
}; 

inline istream & operator>>(istream & is, Hue & h) {
	is >> h.name;
	is >> h.shade;
	is >> h.scale;
	return is;
}

inline ostream & operator<<(ostream & os, const Hue & h) {
	os << setw(8) << h.name << ' ';
	os << setw(6) << h.shade << ' ';
	os << setiosflags(ios::fixed | ios::showpoint);
	os << setprecision(1);					// one place to right of decimal
	os << setw(9) << h.scale;
	return os;
}
#endif
