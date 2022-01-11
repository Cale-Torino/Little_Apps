// cast3.C - proper design
#include <iostream.h>

class Liquid;

class Gas {
public:
	Gas() { }
	Gas(const Liquid &) { }							// convert Liquid to Gas
};

class Solid {
public:
	Solid() { }
	//Solid(const Liquid &) { }						// convert Liquid to Solid
};

class Liquid {
public:
	Liquid() { }
	Liquid(const Gas &) { }							// convert Gas to Liquid
	Liquid(const Solid &) { }						// convert Solid to Liquid
	operator Solid () { Solid s; return s; }
};

void plot(const Gas &) {
	cout << "f(const Gas &)" << endl; }
void plot(const Solid &) {
	cout << "f(const Solid &)" << endl; }

int main() {
	Liquid water;
	//plot(water);					// ambiguous - Liquid to Gas or Liquid to Solid?
	return 0;
}
