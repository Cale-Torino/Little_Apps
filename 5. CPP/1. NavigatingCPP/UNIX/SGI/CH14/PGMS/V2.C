// v2.C - multiple inheritance with virtual functions
#include "v2.h"

int main()
{
	C c;
	B *bp = &c;
	C *cp = &c;
	*bp = *cp;
	cout << endl;
	return 0;
}
