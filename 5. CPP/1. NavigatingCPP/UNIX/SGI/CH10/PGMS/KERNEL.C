// kernel.c - template containment
#include <iostream.h>
#include "Array.h"
#include "Stack.h"
#include "String.h"

template <class TYPE>
class Kernel {
private:
	Stack<TYPE> tasks;						// generic template member
	Array<String> symbol_table;			// specific template member
	String name;								// non-template member
public:
	Kernel(const String & n, int len) :
		tasks(len), symbol_table(500), name(n) { }
	String getname() const { return name; }
	int gettasks() const { return tasks.length(); }
};

int main()
{
	Kernel<String> k("Process Table", 20);
	cout << k.getname() << " has " << k.gettasks() << " tasks" << endl;
	return 0;
}

/**********************************************************************

$ kernel 
Process Table has 20 tasks

*/
