// Point6.C - Point implementation
#include "Point6.h"

Point & Point::rmove(motion m, int n) {
	for (register int i = 0; i < n; i++)
		(this->*m)();								// call motion routine
	return *this;									// return modified Point object
}

double Point::originx = 0;						// initialize originx
double Point::originy = 0;						// initialize originy
double Point::leftx = -80;						// initialize left x coord
double Point::rightx = 80;						// initialize right x coord
double Point::lowery = -80;					// initialize lower y coord
double Point::uppery = 80;						// initialize upper y coord
