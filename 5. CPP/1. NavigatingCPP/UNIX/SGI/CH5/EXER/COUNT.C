// count.c - Object creation and deletion
#include <iostream.h>

class X {
private:
	static int count;
public:
	X() { cerr << "Constructor called" << endl; count++; }
	X(const X &) { cerr << "Constructor called" << endl; count++; }
	~X() { cerr << "Destructor called" << endl; count--; }
	static int getcount() { return count; }
};

int X::count = 0;

X *sub1() { X *p = new X; delete p; return p; }			// call destructor!
void sub2() { X a; }
void sub3() { sub1(); sub2(); }

int main()
{
	sub3();
	sub3();
	cout << "There are " << X::getcount() <<
						" number(s) left" << endl;
	return 0;
}

/*************************************************************************

$ count
Constructor called
Destructor called
Constructor called
Destructor called
Constructor called
Destructor called
Constructor called
Destructor called
There are 0 number(s) left

*/
