// exports.C  - export keyword
#include "defs.h"

int main()
{
	static int a[5] = { 22, 33, 44, 55, 66 };
	static double b[6] = { 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };

	print(a, 5);					// call template function
	print(b, 6);					// call template function
	return 0;
}

/*******************************************************************

$ exports
22 33 44 55 66 
2.2 3.3 4.4 5.5 6.6 7.7 

*/
