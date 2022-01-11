// cast1.C - overloaded casts collide with constructors
#include <iostream.h>

class Liquid;

class Gas {
public:
	Gas(const Liquid &) { }									// convert Liquid to Gas
};

class Liquid {
public:
	Liquid() { }
	operator Gas () { Gas g(*this); return g; }		// convert Liquid to Gas
};

void plot(const Gas &) {
	cout << "plot(const Gas &)" << endl; }

int main() {
	Liquid water;
	//plot(water);					// ambiguous - 2 ways to make a Gas from a Liquid
	return 0;
}
