// wchart.c - wide character and string literals
#include <iostream.h>
#include <ctype.h>

int main()
{
	wchar_t c = L'ab';						// wide character literal
	cout << c << endl;
	cout << sizeof(c) <<endl;

	wchar_t *pc = L"abc";					// wide string literal
	while (*pc)
		cout << *pc++ << ' ';
	cout << endl;
	return 0;
}

/**********************************************************************

$ wchart
25185
2
97 98 99 

*/
