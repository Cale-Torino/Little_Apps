// vfi2.C - virtual function implementation
#include <iostream.h>
#include "Person4.h"

int main()
{
	Person *p1 = new Person("John", "Doe", "867-89-1234");
	Person *p2 = new Student("Jane", "Smith", "934-56-7890", "Biology", 3.5);
	Person & rp = *p1;						// Person reference

	p2->output(cout);							// (*(p2->vptr[1]))(p2, cout);
	rp.output(cout);							// (*(rp.vptr[1]))(&rp, cout);
	delete p1;									// (*(p1->vptr[0]))(p1);
	return 0;
}

/**********************************************************************

$ vfi2 
Smith, Jane (934-56-7890)
Biology: 3.5
Doe, John (867-89-1234)

*/
