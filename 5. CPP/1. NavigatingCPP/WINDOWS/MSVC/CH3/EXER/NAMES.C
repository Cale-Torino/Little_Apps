// names.C - namespaces
#include <iostream.h>

namespace Black {									// define namespace Black
	void print(int k) { 
		cout << "Black::print(" << k << ')' << endl;
	}
}

namespace White {									// define namespace White
	void print(int k) { 
		cout << "White::print(" << k << ')' << endl;
	}
}

//using Black::print;							// global using declaration

void sub1() {
	using White::print;							// local using declaration
	print(5);										// legal, White::print()
}

void print(int k) { 
	cout << "global print(" << k << ')' << endl;
	if (k > 0)
		print(k-1);									// recursive call
}

int main()
{
	sub1();
	print(3);
	return 0;
}

/************************************************************************

$ names
White::print(5)
global print(3)
global print(2)
global print(1)
global print(0)

NOTES:

1. The global namespace declaration for Black::print() is illegal because
	a print() function already exists in global scope.

2. Inside the global print(), calls to print() are recursive.
	Inside sub1(), a local using declaration brints White::print() into 
	local scope.

*/
