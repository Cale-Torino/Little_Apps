// p2.C - Public inheritance
#include "Person2.h"

int main()
{
	Person p1("John", "Doe", "867-89-1234");
	Student s1 ("Jane", "Smith", "934-56-7890", "Biology", 3.5);
	p1.output(cout);						// calls Person::output()
	s1.output(cout);						// calls Student::output()
	return 0;
}

/*********************************************************************

$ p2
Doe, John (867-89-1234)
Smith, Jane (934-56-7890)
Biology: 3.5

*/
