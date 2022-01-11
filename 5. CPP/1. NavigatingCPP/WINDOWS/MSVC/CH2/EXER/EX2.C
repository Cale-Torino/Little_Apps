// ex2.C -  generate sequence
#include <iostream.h>
#include <iomanip.h>

int main()
{
	for (int num = 2; num <= 60; num += ((num + 10) % 20 == 0) ? 10 : 2)
		cout << setw(3) << num;
	cout << endl;
	return 0;
}

/************************************************************************

$ ex2
  2  4  6  8 10 20 22 24 26 28 30 40 42 44 46 48 50 60

*/
