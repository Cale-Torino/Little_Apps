// cast2.C - multiple overloaded casts
#include <iostream.h>

class Gas {
public:
	Gas() { }
};

class Solid {
public:
	Solid() { }
};

class Liquid {
public:
	Liquid() { }
	Liquid(const Gas &) { }							// convert Gas to Liquid
	Liquid(const Solid &) { }						// convert Solid to Liquid
	operator Gas () { Gas g; return g; }		// convert Liquid to Gas
	operator Solid () { Solid s; return s; }	// convert Liquid to Solid
};

void plot(const Gas &) {
	cout << "plot(const Gas &)" << endl; }
void plot(const Solid &) {
	cout << "plot(const Solid &)" << endl; }

int main() {
	Liquid water;
	//plot(water);					// ambiguous - Liquid to Gas or Liquid to Solid?

	plot (static_cast<Gas>(water));					// calls plot(const Gas &);
	plot (static_cast<Solid>(water));					// calls plot(const Solid &);
	return 0;
}

/**********************************************************************

$ cast2 
plot(const Gas &)
plot(const Solid &)

*/
