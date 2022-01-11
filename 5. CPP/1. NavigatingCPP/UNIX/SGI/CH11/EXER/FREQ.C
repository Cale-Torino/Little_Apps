// freq.c - Frequency counts
#include <iostream.h>
#include "BArray.h"
#include "String.h"

void display(const BArray<int> & a) {
	for (char ch = 'a'; ch <= 'z'; ch++)
		if (a[ch])
			cout << ch << ' ';
	cout << endl;

	for (int i = a.lb(); i <= a.ub(); i++)
		if (a[i])
			cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	try {
		 BArray<int> count('a', 'z');
		 static String words = "thisisabunchoflowercaseletters";

		 for (int i = 0; i < words.length(); i++)
			 count[words[i]]++;						// frequency count
		 display(count);
	}
	catch (const ArrayError & e) {
		e.response();									// virtual call
		return 1;
	}
	return 0;
}

/******************************************************************

$ freq
a b c e f h i l n o r s t u w 
2 1 2 4 1 2 2 2 1 2 2 4 3 1 1 

*/
