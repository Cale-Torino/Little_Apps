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
		cText t1(10);									// Text object holds 10 sentences
		int i;
		for (i = 0; i < 4; i++)						// write 4 sentences
			t1.write(a[i]);

		t1.write("another sentence", 1);			// write after sentence 1
		t1.write("one more sentence");			// write after last sentence
		cout << "t1 has " << t1.nitems() << " sentences." << endl;

		for (i = 1; i <= t1.nitems(); i++)		// read sentences
			cout << t1.read(i) << endl;;
	}
	catch (const TextError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/***********************************************************************

$ ctext
t1 has 6 sentences.
This is the first sentence.
another sentence
Here is sentence number two.
This group of words is sentence three.
This sentence is the last one.
one more sentence

NOTES:
	1. In Text.h, we introduce a private insert() funciton that manipulates
		the array of sentence pointers.  This function is called from 
		cText::write() with a sentence number.

	2. In Text::write() and cText::write(), we use an sn argument to
		default sentence numbers. If sn == 0, we put the setence at the end;
		otherwise, we put the sentence after sentence sn.

	3. If sentence number sn is less than zero or greater than count, we 
		throw a TextError exception.

*/
