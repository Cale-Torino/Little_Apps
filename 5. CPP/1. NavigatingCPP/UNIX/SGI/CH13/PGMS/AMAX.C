// amax.c - array max() template function, exception specifications
#include <iostream.h>
#include <exception.h>
#include <stdlib.h>
#include "Array.h"

void surprise() {
	cerr << "surprise exception" << endl;
	exit(1);
}

void uncaught() {
	cerr << "uncaught exception" << endl;
	exit(1);
}

class Num {
private:
	int num;
public:
	Num(int n = 0) : num(n) { }
	Num & operator=(const Num & rhs) {
		if (rhs.num == 0)						// force exception in Num assignment
			throw "Num: zero value";		
		num = rhs.num;
		return *this;
	}
	operator int () const { return num; }
};

template <class TYPE>
void fill(Array<TYPE> & a, int length, const TYPE *val) {
	int idx = 0;
	for (int i = 0; i < length; i++)
			a[i] = val[idx++];
}

template <class TYPE>
TYPE max(Array<TYPE> & a) throw () {
	a[0] = 0;										// force exception
	TYPE maxv = a[0];
	for (int i = 1; i < a.length(); i++)
		if (a[i] > maxv)
			maxv = a[i];							// could throw exception
	return maxv;
}

int main()
{
	set_unexpected(surprise);
	set_terminate(uncaught);
	Array<Num> a(10);
	Num vals[] = { 4, 33, -12, 9, 101, 66, 88, 34, 61, 11 };
	fill(a, 10, vals);
	cout << max(a) << endl;
	return 0;
}

/***************************************************************

$ amax
surprise exception

*/
