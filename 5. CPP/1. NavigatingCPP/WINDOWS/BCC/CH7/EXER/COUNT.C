// count.c - Static data members and boilerplate
#include <iostream.h>

class X {
private:
	static int count;
	void copy(const X &) { count++; }
	void free() { count--; }
public:
	X() { cerr << "Constructor called" << endl; count++; }
	X(const X & a) { cerr << "Constructor called" << endl; copy(a); }
	~X() { cerr << "Destructor called" << endl; free(); }
	static int getcount() { return count; }
};

int X::count = 0;

int main()
{
	X a, c;
	X b = a;									// copy initialization
	c = b;									// assignment
	cout << "There are " << X::getcount() << " object(s)" << endl;
	return 0;
}

/******************************************************************

$ count
Constructor called
Constructor called
Constructor called
There are 3 object(s)
Destructor called
Destructor called
Destructor called

NOTES:  
1. Here's the output from the original program.

	$ count
	Constructor called
	Constructor called
	There are 2 object(s)
	Destructor called
	Destructor called
	Destructor called

2. Without an explicit copy constructor that increments count, we only
	track 2 objects, not 3.  When you create new objects with copy
	initialization, it's important to include a copy constructor that
	increments static data members like count.

3. Overloaded assignment is not necessary here, because all X objects 
	share the same count and you are not creating a new X object, 
	only updating an existing one.

4. Only copy() and free() are needed to manage the static data 
	member count correctly.

*/
