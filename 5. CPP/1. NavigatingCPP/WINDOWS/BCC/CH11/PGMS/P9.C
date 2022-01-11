// p9.C - Mixing access levels; don't do this
#include "Person5.h"

int main()
{
	Student s2("Jane", "Smith", "934-56-7890", "Biology", 3.5);
	// s2.output(cout);				// illegal, Student::output() not accessible
	Person *pptr = &s2;
	pptr->output(cout);			// OK, Person::output() is accessible, but
									   // calls Student::output() (virtual function)
	return 0;
}
/***************************************************************

$ p9
934-56-7890 (Smith, Jane) 
Biology: 3.5
Student destructor
Person destructor

*/
