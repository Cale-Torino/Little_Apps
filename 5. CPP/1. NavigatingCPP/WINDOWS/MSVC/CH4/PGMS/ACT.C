// act.C - const, reference members, member initialization
#include <iostream.h>
#include "Roman.h"
#include "Fifo5.h"

class Act {
private:
	const Roman r;										// contains const Roman object
	Fifo & g;											// reference to Fifo object
public:
	Act(int, Fifo &);
	const char *getact() const { return r.getroman(); }
	void write(char c) { g.write(c); }
	char read() const { return g.read(); }
	bool empty() const { return g.empty(); }
};

Act::Act(int num, Fifo & f) : r(num), g(f) { 	// Act constructor
	for (const char *p = "Act "; *p;) 
		g.write(*p++);
	for (const char *q = r.getroman(); *q;) 
		g.write(*q++);
	g.write('\n');
}

int main()
{
	try {
		Fifo quote("Hamlet - "); 
		Act play(3, quote);

		for (const char *q = "To be, or not to be, that is the question.\n"; *q;) 
			play.write(*q++);

		while (!play.empty())
			cout << play.read();
	}
	catch (const FifoError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ act 
Hamlet - Act III
To be, or not to be, that is the question.

*/
