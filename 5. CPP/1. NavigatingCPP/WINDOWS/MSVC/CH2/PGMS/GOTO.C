// goto.c - go to construct
#include <iostream.h>
#define MAX 100

bool error1 = true;
bool error2 = false;
bool error3 = false;

int main()
{																// start of block
	for (int i = 0; i < MAX; i++) {					// start of for loop
		if (error1) goto stop;
		while (true) {										// start of outer while loop
			if (error2) goto stop;
			while (i < MAX) {								// start of inner while loop
				if (error3) goto stop;
			}													// end of inner while loop
			goto stop;
		}													 	// end of outer while loop
	}															// end of for loop
	stop:														// handle error condition
		cerr << "stop right here..." << endl;
	return 0;
}																// end of block

/**********************************************************************

$ goto
stop right here...

*/
