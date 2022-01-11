// nest.c - nested try blocks
#include <iostream.h>

class LocalVar {
public:
	LocalVar() { cout << "LocalVar constr" << endl; }
	~LocalVar() { cout << "LocalVar destr" << endl; ; }
};

class LocalArray {
public:
	LocalArray() { cout << "LocalArray constr" << endl; }
	~LocalArray() { cout << "LocalArray destr" << endl; }
};

void throw_msg() { throw "message"; }
void throw_int(int n) { throw n; }

void nest(int n)
{
	try {
		LocalVar v1;
		//throw_int(n);
		try {
			LocalArray v2[2];
			//throw_msg();
			throw_int(n);
			if (n == 1)
				return;
		}
		catch (char *msg) { cerr << "nested: " << msg << endl; }
	}
	catch (int value) { cerr << "outer: " << value << endl; }
	cout << "end of nest" << endl;
}

int main()
{
	nest(1);
	return 0;
}

/**************************************************************

$ nest
LocalVar constr
LocalArray constr
LocalArray constr
LocalArray destr
LocalArray destr
LocalVar destr
outer: 1
end of nest

*/
