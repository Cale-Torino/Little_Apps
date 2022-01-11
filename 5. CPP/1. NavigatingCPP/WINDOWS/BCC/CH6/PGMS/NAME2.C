// name2.C - overloading and namespaces, ambiguites
#include <iostream.h>

namespace Red {
	int triple(int i) {
		cout << "Red::triple(int)" << endl;
		return i*3;
	}
}

namespace Blue {
	int triple(int i) {
		cout << "Blue::triple(int)" << endl;
		return i*3;
	}
}

void sub2() {
	using namespace Red;						// using directive
	using namespace Blue;					// using directive
	//double mint = triple(5.5);			// error, ambiguous
	double mint = Red::triple(5.5);		// specify which one
	cout << mint << endl;
}

int main()
{
	sub2();
	return 0;
}

/************************************************************************

$ name2
Red::triple(int)
15

*/
