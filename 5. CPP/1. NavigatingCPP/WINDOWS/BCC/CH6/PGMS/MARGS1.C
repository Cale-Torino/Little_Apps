// margs1.C - multiple arguments with intersection rule
#include <iostream.h>

class Liquid {
public:
	Liquid() { }
};

class Gas {
public:
	Gas(const Liquid &) { }						// convert Liquid to Gas
};

void plot(const Liquid &, const Gas &) {
	cout << "plot(const Liquid &, const Gas &)" << endl; }
void plot(const Gas &, const Gas &) {
	cout << "plot(const Gas &, const Gas &)" << endl; }

int main() {
	Liquid water;
	Gas steam(water);

	plot(water, steam);					// calls plot(const Liquid &, const Gas &)
	plot(steam, steam);					// calls plot(const Gas &, const Gas &)
	plot(steam, water);					// calls plot(const Gas &, const Gas &)
	plot(water, water);					// calls plot(const Liquid &, const Gas &)
	return 0;
}

/**********************************************************************

$ margs1 
plot(const Liquid &, const Gas &)
plot(const Gas &, const Gas &)
plot(const Gas &, const Gas &)
plot(const Liquid &, const Gas &)

*/
