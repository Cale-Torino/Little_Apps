// ex4.C - dangling else
#include <iostream.h>

int main()
{
	int a = 5, b = 6, c = 7;

	if (a > b) //{
		if (b < c)
			c = a;
	//}
	else
		c = b;
	cout << "c = " << c << endl;
	return 0;
}

/************************************************************************

$ ex4 (with braces)
c = 6

$ ex4 (without braces)
c = 7

Without braces, the else belongs to the second if (nearest one).
This means c never changes.

With braces, the else belongs to the first if. Since the first if is
false, we modify c with the else statement.

*/
