// cassign.C - cText and Text copy semantics
#include <iostream.h>
#include "cText.h"
#include "String.h"

int main()
{
	int i;
	Text t1(100);							// holds 100 Text objects
	t1.write("some text");				// write sentence
	t1.write("more text");				// write sentence

	cText t3 = t1;							// cText copy initialization
	for (i = 1; i <= t3.nitems(); i++)
		cout << t3.read(i) << endl;

	cText t4(100);							// holds 100 Text objects
	t4 = t1;									// cText and Text assignment
	for (i = 1; i <= t4.nitems(); i++)
		cout << t4.read(i) << endl;
	return 0;
}

/**********************************************************************

$ cassign 
some text
more text
some text
more text

NOTES:
	1. The changes are really minor to make this work.

	2. All that is needed in Text.h is a friend class cText declaration, 
		which allows cText to call Text::copy().

	3. In cText.h we introduce the following:

			cText::cText(const Text & b) { 				// conversion
				pref = new Text_ref(b.length());
				pref->ptext->copy(b);						// copy Text object 
			}

		This constructor builds a cText object from a Text object. After we
		create a Text_ref object for the reference counting, we call Text::copy()
		to do all the work.

*/
