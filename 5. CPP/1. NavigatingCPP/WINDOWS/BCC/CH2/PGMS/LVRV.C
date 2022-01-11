// lvrv.C - lvalues, rvaules with prefix/postfix
#include <iostream.h>

int main()
{
	int n = 12;
	++n = 100;							// legal, prefix
	cout << n << endl;
	//n++ = 100;							// illegal, postfix
	cout << n << endl;

	char *p = "hello";
	*++p = 'x';							// legal, prefix
	cout << *p << endl;
	++*p = 'x';							// legal, prefix
	cout << *p << endl;
	*p++ = 'x';							// legal, still lvalue
	//(*p)++ = 'x';						// illegal, postfix
	return 0;
}

/**********************************************************************

$ lvrv
100
100
x
x

*/
