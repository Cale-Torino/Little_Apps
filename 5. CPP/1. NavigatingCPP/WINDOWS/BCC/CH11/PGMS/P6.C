// p6.C - polymorphic inheritance, correct operator overloading
#include "Person3.h"

int main()
{
   Person p1("John", "Doe", "867-89-1234");
	Student s2("Jane", "Smith", "934-56-7890", "Biology", 3.5);
	cout << p1 << endl;
	cout << s2 << endl;
	return 0;
}
/***************************************************************

$ p6
Doe, John (867-89-1234)

Smith, Jane (934-56-7890)
Biology: 3.5

Student destructor
Person destructor
Person destructor

*/
