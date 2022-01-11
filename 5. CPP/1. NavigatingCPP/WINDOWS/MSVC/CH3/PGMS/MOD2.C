// mod2.C - extern
#include <iostream.h>
#include "global.h"

extern int nitems;
extern double servo[];

double f()
{
	extern something s;
	return 12.34;
}
