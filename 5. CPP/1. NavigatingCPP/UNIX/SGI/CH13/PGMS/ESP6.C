// esp6.c - exception specifications
#include <iostream.h>
#include <stdlib.h>
#include <exception.h>

void f(int n = 0) throw (char *) {
	if (n == 0)
		throw "error";
}

//void g(int m = 0) throw (int)	{
void g(int m = 0) throw (int, char *)	{
	f();
	if (m == 0)
		throw m;
}

int main()
{
	try {
		g();
	}
	catch (int n) { cout << n << endl; }
	catch (char *msg) { cout << msg << endl; }
	return 0;
}

/**********************************************************************

$ esp6
error

*/
