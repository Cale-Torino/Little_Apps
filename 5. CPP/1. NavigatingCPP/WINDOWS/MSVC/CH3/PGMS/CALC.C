// calc.C - dispatch table for math functions
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NELEMS(A) (sizeof(A) / sizeof A[0])

struct math {
	char *name;										// name of math function
	double (*pmf)(double);						// ptr to math function
};
math mtab[] = {									// dispatch table
	"sin", sin,
	"cos", cos,
	"exp", exp,
	"tan", tan,
	"sqrt", sqrt
};

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " math_func double" << endl;
		return 1;
	}

	int mf;
	for (mf = 0; mf < NELEMS(mtab); mf++)			// look up table
		if (strcmp(argv[1], mtab[mf].name) == 0)
			break;

	if (mf == NELEMS(mtab)) {								// found it?
		cerr << "math_func " << argv[1] << " not found" << endl;
		return 1;
	}

	double arg = atof(argv[2]);					// convert the argument
	cout << mtab[mf].pmf(arg) << endl;			// call the function
	return 0;
}

/*******************************************************************

$ calc sqrt 81
9

$ calc exp 3
20.0855

*/
