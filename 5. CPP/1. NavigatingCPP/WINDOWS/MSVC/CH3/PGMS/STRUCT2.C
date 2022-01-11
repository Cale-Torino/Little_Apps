// struct2.C - nested structures
#include <iostream.h>

struct team {
	struct address {										// nested structure
		char location[80];								// team location
		int zipcode;										// team zipcode
	};
	char name[20];											// name of team
	address sponsor;										// sponsor's address
	address home_field;									// address of home_field
};
	
int main()
{
	team soccer = { "bears", {"123 Main", 30302}, {"8 Elm", 32240} };
	team *ps = &soccer;

	cout << soccer.name << endl;						// displays "bears"
	cout << soccer.sponsor.zipcode << endl;		// displays 30302
	cout << ps->home_field.zipcode << endl;		// displays 32240
	return 0;
}

/*******************************************************************

$ struct2
bears
30302
32240

*/
