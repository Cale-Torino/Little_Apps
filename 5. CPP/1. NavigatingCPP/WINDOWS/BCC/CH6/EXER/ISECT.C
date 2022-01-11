// isect.c - intersection rule
#include <iostream.h>

class Broth {
public:
	Broth() { }
};

class Soup {
public:
	Soup(const Broth &) { }
};

class Gravy {
public:
	Gravy(const Broth &) { }
};

void stove(const Gravy &, const Soup &) { cout << "Gravy, Soup" << endl; }
void stove(const Gravy &, const Gravy &) { cout << "Gravy, Gravy" << endl; }

int main()
{
	Broth b;
   Soup tomato(b);
	Gravy brown(b);
	stove(b, brown);								// intersection rule
	stove(b, tomato);								// intersection rule
	//stove(brown, b);							// ambiguous
	//stove(tomato, brown);						// no match
	stove(brown, tomato);						// exact match
	return 0;
}

/*************************************************************************

$ isect
Gravy, Gravy
Gravy, Soup
Gravy, Soup

NOTES:
1. The call stove(brown, b) is ambiguous for argument b, since 
	there is a standard conversion from Broth to Soup AND from 
	Broth to Gravy. 

2. There is no conversion from Soup to Gravy, hence the call
	stove(tomato, brown) does not match its first argument.

*/
