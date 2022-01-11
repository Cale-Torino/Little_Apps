// p3.C - Base and derived class standard conversions with pointers
// conversion examples and static binding
#include "Person2.h"

int main()
{
	Person p1("John", "Doe", "867-89-1234");
	Student s2("Jane", "Smith", "934-56-7890", "Biology", 3.5);

	Person *pptr1 = &p1;					// no conversion
	Person *pptr2 = &s2;					// standard conversion (derive to base)
	Student *sptr2 = &s2;				// no conversion

	pptr1->output(cout);					// calls Person::output() (correct)
	pptr2->output(cout);					// calls Person::output() (wrong)
	sptr2->output(cout);					// calls Student::output() (correct)
	return 0;
}

/************************************************************************

$ p3
Doe, John (867-89-1234)
Smith, Jane (934-56-7890)
Smith, Jane (934-56-7890)
Biology: 3.5

*/
