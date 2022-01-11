// int.c - Integer class
#include <iostream.h>
#include <math.h>

class Int {
private:
	int num;
public:
	Int(int n = 0) : num(n) { }
	operator int () const { return num; }
};

int main()
{
	Int n;
	cout << n << endl;
	Int m = 36;
	cout << m << endl;
	Int k = m;
	cout << k << endl;
	cout << m + 10 << endl;
	cout << sqrt(m) << endl;
	return 0;
}

/**********************************************************************

$ int 
0
36
36
46
6

*/
