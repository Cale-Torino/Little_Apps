// margs2.C - multiple arguments with intersection rule - with casts
#include <iostream.h>

class Solid {
public:
	Solid() { cout << "Solid" << endl; }
};

class Liquid {
public:
	Liquid(const Solid &) { cout << "Liquid" << endl; }	// Solid to Liquid conv
};

class Gas {
public:
	Gas(const Liquid &) { cout << "Gas" << endl; }			// Liquid to Gas conv
};

void plot(const Liquid &, const Gas &) {
	cout << "plot(const Liquid &, const Gas &)" << endl; }
void plot(const Gas &, const Gas &) {
	cout << "plot(const Gas &, const Gas &)" << endl; }

int main() {
	Solid ice;
	Liquid water(ice);
	Gas steam(water);

	plot(ice, water);					// calls plot(const Liquid &, const Gas &)
	plot((Gas)ice, water);			// traditional cast - OK
	plot(Gas(ice), water);			// functional cast - OK
	plot(static_cast<Gas>(static_cast<Liquid>(ice)), water);
	return 0;
}

/**********************************************************************

$ margs2 
Solid
Liquid
Gas
Gas
Liquid
plot(const Liquid &, const Gas &)
Gas
Liquid
Gas
plot(const Gas &, const Gas &)
Gas
Liquid
Gas
plot(const Gas &, const Gas &)
Gas
Liquid
Gas
plot(const Gas &, const Gas &)

*/
