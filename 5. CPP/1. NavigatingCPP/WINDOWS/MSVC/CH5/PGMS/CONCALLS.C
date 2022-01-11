// concalls.c - constructor calls
#include <iostream.h>

class A {
private:
	int num;
public:
	A(int n = 0) { num = n; cout << "A constr" << endl; }
	~A() { cout << "A destr" << endl; }
};

int main()
{
	A (*ps) = new A[0];					// no A constructor call
	delete [] ps;							// no A destructor call

	A (*pt)[1] = new A[0][1];			// no A constructor call
	delete [] pt	;						// no A destructor call

	A (*pu)[1] = new A[1][1];			// A constructor call
	delete [] pu	;						// A destructor call

	//A (*pv)[0] = new A[1][0];			// illegal
	return 0;
}

/********************************************************************

$ concalls
A constr
A destr

*/
