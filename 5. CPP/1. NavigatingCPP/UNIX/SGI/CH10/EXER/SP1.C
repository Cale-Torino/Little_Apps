// sp1.C - smart pointers, member templates
#include <iostream.h>
#include "Ptr.h"
#include "String.h"

void display(const Ptr<String> & p) {
	for (int i = 0; i < p.length(); i++)
		cout << p[i] << ' ';							// forward with pointer []
	cout << endl;
}

class Special_String : public String {
public:
	Special_String(const char *p = "") : String(p) { }
};

int main()
{
	try {
		const int max = 5;
		static Special_String tab[max] = { "twelve", "ten", "twenty", "thirty", "fifty" };

		int i;
		Ptr<Special_String> p(tab, max);			// like Special_String *p = tab;

		for (i = 0; i < max; i++)
			cout << *p++ << ' ';						// forward with pointer *
		cout << endl;

		for (i = 0; i < max; i++)
			cout << *--p << ' ';						// backward with pointer *
		cout << endl;

		display(p);
		cout << *--p << endl;						// out of bounds
	}
	catch (const PtrError & e) {					// Ptr errors
		e.response();
		return 1;
	}
	return 0;
}

/******************************************************************************

$ sp1
twelve ten twenty thirty fifty 
fifty thirty twenty ten twelve 
twelve ten twenty thirty fifty 
Ptr: Ptr out of bounds

*/
