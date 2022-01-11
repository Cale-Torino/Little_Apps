// ex5.C - Basic Rule
#include <iostream.h>
#include <iomanip.h>

double vision[2][4] = {
  { 1, 2, 3, 4 },
  { 5, 6, 7, 8 }
};

int main()
{
	cout << vision[1][2] << *(vision[1] + 2) << (*(vision + 1))[2] << endl;
	cout << vision[1][0] << *(vision[1]) << **(vision + 1) << endl;
	return 0;
}

/************************************************************************

$ ex5
777
555

In each line, the output is the same because of the basic rule.
The following expressions are all equivalent in the first cout stmt:

		vision[1][2] 		*(vision[1] + 2)		(*(vision +1))[2]

The following expressions are all equivalent in the second cout stmt:

		vision[1][0]	is equiv to		*(vision[1] + 0) or *(vision[1])

		*(vision[1])	is equiv to *(*vision +1) or **(vision +1)

*/
