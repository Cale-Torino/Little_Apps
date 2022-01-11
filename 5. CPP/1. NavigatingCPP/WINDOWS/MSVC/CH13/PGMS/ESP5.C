// esp5.c - exception specifications, violations
#include <iostream.h>
#include <stdlib.h>
#include <excpt.h>
#include <eh.h>
#include "String.h"

void surprise() {
	cerr << "surprise exception" << endl;
	exit(1);
}

void plot(double, double) { 					// no exception specification
	cout << "plot called" << endl;
	throw 12;
	//throw String("ok");
}

void graph(double x, double y) throw (String)	{
	plot(x, y);
	if (x == 0)
		throw String("error");
}

int main()
{
	set_unexpected(surprise);
	try {
		graph(3, 4);
	}
	catch (const String & msg) { 
		cerr << msg << endl;
	}
	return 0;
}

/**********************************************************************

$ esp5 
plot called
abnormal program termination

*/
