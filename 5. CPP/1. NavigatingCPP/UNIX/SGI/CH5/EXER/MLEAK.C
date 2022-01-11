// mleak.C - memory leaks
#include <iostream.h>

class B {
private:
	double *q;
	int n;
public:
	B(int i = 1) {
		q = new double[n = i];
		cerr << "B constr" << endl;
	}
	~B() { cerr << "B destr" << endl; delete [] q; }
};

class C {
private:
    B *p; 
    int len;
public:
    C(int size = 1) {
		p = new B[len = size];
		cerr << "C constr" << endl;
	}
	~C() { cerr << "C destr" << endl; delete [] p; }
};

int main()
{
	C *pc = new C[3];
	//delete pc;							// incorrect
	delete [] pc;							// correct
	return 0;
}

/*************************************************************************

$ mleak
B constr
C constr
B constr
C constr
B constr
C constr
C destr
B destr
C destr
B destr
C destr
B destr

NOTES:

1.  Each call must be the delete [] syntax, since new [] was used.

*/
