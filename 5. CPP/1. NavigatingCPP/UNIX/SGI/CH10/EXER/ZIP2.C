// zip2.C - associative arrays with more lvalue/rvalue separation
#include <iostream.h>
#include "Assoc2.h"
#include "String.h"

void f(int z) { cout << "z = " << z << endl; }

int main()
{
	try {
		 Assoc<String, int> zip(6);
		 cout << "length of array is " << zip.length() << endl;

		 zip["paul"] = 92024;
		 zip["steve"] = 92119;
		 zip["dave"] = 92071;
		 zip["tom"] = 92038;
		 cout << zip << endl;

		 cout << zip["paul"] << endl;

		 zip["bank"] = 92008;								// this is OK
		 cout << zip["bank"] << endl;						// now this is OK

		 zip["paul"] += 10;
		 cout << zip["paul"] << endl;
		 f(zip["steve"] += 10);
		 cout << (zip["steve"] += 10) << endl;
		 cout << ++zip["dave"] << endl;
		 zip["tom"]--;
		 cout << zip["tom"] << endl;
	}
	catch (const AssocError<String, int> & e) {
		e.response();
		return 1;
	}
	return 0;
}

/******************************************************************

$ zip2
length of array is 6
0 : paul : 92024
1 : steve : 92119
2 : dave : 92071
3 : tom : 92038

92024
92008
92034
z = 92129
92139
92072
92037

*/
