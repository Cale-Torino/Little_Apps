// mod1.C - extern
#include <iostream.h>
#include "global.h"

int nitems;
double servo[100];
something s;
extern double f();

int main()
{
	servo[5] = f();
	cout << servo[5] << endl;
	return 0;
}

/*******************************************************************

$ mod1
12.34

*/
