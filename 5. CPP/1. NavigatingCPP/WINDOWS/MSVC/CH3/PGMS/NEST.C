// nest.C - nested namespaces
#include <iostream.h>

namespace Outer {								// namespace definition
	int i, j;
	namespace Inner {							// nested namespace
		const int Max = 20;
		char ch;
		char buffer[Max];
		void print();
	}
}

void Outer::Inner::print() {
	for (int i = 0; i < Max; i++)			// i is local to for loop
		cout << buffer[i] << ' ';
	cout << endl;
}

void sub() {
	Outer::i = 10;
	Outer::Inner::ch = 'a';
	for (int i = 0; i < Outer::Inner::Max; i++)		// i is local
		Outer::Inner::buffer[i] = Outer::Inner::ch + i;
	Outer::Inner::print();
	cout << "Max = " << Outer::Inner::Max << endl;
}

int main()
{
	sub();
	return 0;
}

/************************************************************************

$ nest
a b c d e f g h i j k l m n o p q r s t 
Max = 20

*/
