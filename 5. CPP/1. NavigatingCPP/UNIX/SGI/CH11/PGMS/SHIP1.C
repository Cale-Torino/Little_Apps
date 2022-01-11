// ship1.c - procdure-oriented approach
#include <iostream.h>
#include "String.h"

enum Ptype { Box, Letter };

struct Package {
	Ptype type;									// Box or Letter
	String src;									// origin
	String dest;								// destination
	int npages;									// number of pages for a Letter
	float weight;								// weight for a Box
};

void create(Package &, Ptype, const String &, const String &, float);
float ship(const Package &);

int main()
{
	Package b;
	create(b, Box, "Yuma", "Denver", 25.5);				// 25.5 pound box
	cout << ship(b) << endl;

	Package m;
	create(m, Letter, "Atlanta", "Boise", 100);			// 100 page letter
	cout << ship(m) << endl;
	return 0;
}

void create(Package & p, Ptype t, const String & s, const String & d, float v) {
	p.type = t;												// store type
	p.src = s;												// store origin
	p.dest = d;												// store destination
	if (t == Box)											// Box?
		p.weight = v;										// store weight
	if (t == Letter)										// Letter?
		p.npages = v;										// store no. of pages
}

float ship(const Package & p) {
	float cost;
	if (p.type == Box)									// Box?
		cost = (p.weight > 100) ? .75 * p.weight : .5 * p.weight;
	else if (p.type == Letter)							// Letter?
		cost = (p.npages > 100) ? .10 * p.npages : .05 * p.npages;
	return cost;
}

/**********************************************************************

$ ship1
12.75
5

*/
