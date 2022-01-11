// nalias.C - namespace aliases
#include <iostream.h>

namespace A_Very_Long_Library_Name {
	struct Point { double x, y; };
	Point origin = { 10, 10 };
}

namespace ALN = A_Very_Long_Library_Name;		// alias

void sub() {
	using ALN::Point;									// using declaration
	Point first = ALN::origin;						// namespace member 
	cout << "sub: " << first.x << endl;
}

int main()
{
	sub();
	return 0;
}

/************************************************************************

$ nalias
sub: 10

*/
