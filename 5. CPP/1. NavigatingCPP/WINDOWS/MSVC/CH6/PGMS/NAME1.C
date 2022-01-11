// name1.C - overloading and namespaces
#include <iostream.h>

namespace Red {
	void print(const char *) { cout << "Red::print(const char *)" << endl; }
	void print(double) { cout << "Red::print(double)" << endl; }
	double triple(double d) { 
		cout << "Red::triple(double)" << endl;
		return d*3;
	}
}

namespace Blue {
	void print(int) { cout << "Blue::print(int)" << endl; }
	int triple(int i) {
		cout << "Blue::triple(int)" << endl;
		return i*3;
	}
	double quad(double d) { 
		cout << "Blue::quad(double)" << endl;
		return d*4;
	}
}

void sub1() {
	using Red::print;						// using declaration
	print("Hello, world");				// Red::print(const char *);
	print(5.5);								// Red::print(double);
}

void sub2() {
	using namespace Red;					// using directive
	using namespace Blue;				// using directive
	print(5);								// Blue::print(int);
	double mint = triple(5.5);			// Red::triple(double);
	print(triple(5));						// Blue::print(Blue::triple(int));
	double vision = quad(5);			// Blue::quad(double), conversion
	cout << mint << ' ' << vision << endl;
}

int main()
{
	sub1();
	sub2();
	return 0;
}

/************************************************************************

$ name1
Red::print(const char *)
Red::print(double)
Blue::print(int)
Red::triple(double)
Blue::triple(int)
Blue::print(int)
Blue::quad(double)
16.5 20

*/
