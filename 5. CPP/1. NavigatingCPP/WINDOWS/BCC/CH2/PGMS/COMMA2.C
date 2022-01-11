// comma2.c - comma operator, if statement
#include <iostream.h>

int main()
{
	static int a[] = { 1, 2, 3, 4, 5 };
	int i = 3, tmp;
	bool swap = true;
	if (swap)
		tmp = a[i], a[i] = a[i+1], a[i+1] = tmp;

	for (i = 0; i < 5; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}

/**********************************************************************

$ comma2
1 2 3 5 4 

*/
