// func.C - function prototypes and definitions
#include <iostream.h>
#include <stdlib.h>

float f(float);									// outside function prototype

int main(int argc, const char *argv[])
{
	void g(float *);								// inside function prototype

	if (argc != 2) {
		cerr << "Usage: " <<  argv[0] << " number" << endl;
		return 1;
	}
	float m = atof(argv[1]);					// convert commandl line number

	m = f(m);										// call by value
	cout << m << endl;

	g(&m);											// call by address
	cout << m << endl;
	return 0;
}

float f(float val)								// pass value
{
	return val + 2;								// return value
}

void g(float *pf)									// pass address
{
	*pf += 2;										// modify argument
}

/*******************************************************************

$ func 6.5
8.5
10.5

*/
