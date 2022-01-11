// refcount.c - reference counts with class String
#include <iostream.h>
#include <ctype.h>
#include "String.h"

int nupper(const String & s) {					// number of uppercase chars
	int count = 0;
	for (int i = 0; i < s.length(); i++)
		if (isupper(s[i]))							// rvalue
			count++;
	return count;
}

void allupper(String & s) {						// convert to uppercase chars
	for (int i = 0; i < s.length(); i++)
		s[i] = toupper(s[i]);						// lvalue
}

int main()
{
	try {
		String a = "My Karma just ran over your Dogma.";
		String b = a;										// copy initialization
		cout << "no. of uppercase chars = " << nupper(b) << endl;
		allupper(b);
		cout << b << endl;								// changed
		cout << a << endl;								// unchanged
	}
	catch (const StringError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*******************************************************************

$ refcount
no. of uppercase chars = 3
MY KARMA JUST RAN OVER YOUR DOGMA.
My Karma just ran over your Dogma.

*/
