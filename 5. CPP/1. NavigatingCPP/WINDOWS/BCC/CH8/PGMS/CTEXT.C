// ctext.c - reference counted text objects
#include <iostream.h>
#include "cText.h"
#include "String.h"

int main()
{
	try {
		 static String a[] = {
			 "This is the first sentence.",
			 "Here is sentence number two.",
			 "This group of words is sentence three.",
			 "This sentence is the last one."
		 };
		 cText t1;										// Text object holds 1 sentence
		 cText t2(10);									// Text object holds 10 sentences
		 for (int i = 0; i < 4; i++)				// write four sentences
			 t2.write(a[i]);
		 cText t3 = t2;								// copy initialization
		 t1 = t3;										// assignment
		 t1.write("another sentence");			// copy on write
		 cout << "t1 has " << t1.nitems() << " sentences." << endl;
		 cout << "t2 has " << t2.nitems() << " sentences." << endl;
		 cout << "t3 has " << t3.nitems() << " sentences." << endl;
		 cout << t1.read(4) << endl;				// last sentence
		 cout << t1.read(1) << endl;				// first sentence
	}
	catch (const TextError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/***********************************************************************

$ ctext
t1 has 5 sentences.
t2 has 4 sentences.
t3 has 4 sentences.
This sentence is the last one.
This is the first sentence.

*/
