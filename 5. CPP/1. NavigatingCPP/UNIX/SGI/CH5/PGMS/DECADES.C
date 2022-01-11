// decades.C - Static data member for Roman counts
#include <iostream.h>
#include <assert.h>
#include "Roman2.h"

int main()
{
	cout << "There are " << Roman::getcount() 
			<< " Roman objects." << endl;
	int i;
	Roman *decades[10];

	decades[0] = new Roman(1970);		assert(decades[0]);
	decades[1] = new Roman(1980);		assert(decades[1]);
	decades[2] = new Roman(1990);		assert(decades[2]);

	cout << "Now there are " << Roman::getcount();
	cout << " Roman objects." << endl;
	for (i = 0; i < Roman::getcount(); i++) {
		cout << decades[i]->getnum() << " is ";
		cout << decades[i]->getroman() << endl;
	}
	delete decades[2];								// delete third Roman

	cout << "Now there are " << Roman::getcount();
	cout << " Roman objects." << endl;
	for (i = 0; i < Roman::getcount(); i++) {
		cout << decades[i]->getnum() << " is ";
		cout << decades[i]->getroman() << endl;
	}
	delete decades[0];	delete decades[1];
	return 0;
}

/**********************************************************************

$ decades 
There are 0 Roman objects.
Now there are 3 Roman objects.
1970 is MCMLXX
1980 is MCMLXXX
1990 is MCMXC
Now there are 2 Roman objects.
1970 is MCMLXX
1980 is MCMLXXX

*/
