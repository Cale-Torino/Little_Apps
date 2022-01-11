// typ1.c - typepid(), non-polymorphic types
#include <iostream.h>
#include <typeinfo.h>
#include "String.h"
#include "Complex.h"
#include "Array.h"

int main()
{
	int i = 12;													// integer
	double d = 3.4;											// double
	String s = "abc";											// String object
	Complex c(2.1, 3.4);										// Complex object
	Array<int> a(10);											// Array of integers
	
	cout << (typeid(i) == typeid(int)) << endl;		// true
	cout << (typeid(d) != typeid(i)) << endl;			// true
	cout << typeid(s).name() << endl;					// displays "String"
	cout << typeid(c).before(typeid(s)) << endl;		// true
	cout << typeid(c).before(typeid(a)) << endl;		// false
	cout << i << ' ' << d << ' ' << c << endl;
	return 0;
}

/**********************************************************************

$ typ1 
1
1
class String
1
0
12 3.4 (2.1, 3.4)

*/
