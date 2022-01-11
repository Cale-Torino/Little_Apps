// local.c - local classes
#include <iostream.h>
#include <math.h>
#define PI M_PI

enum color { red, green, blue };			// enumeration
bool bright = true;							// global variable

void make_circle(double rad, color c) {
	static bool visible = true;			// static variable
	bool bright = true;						// local variable

	class Circle {								// local class
	private:
		double radius;
		color cn;
		bool visibility;
		bool contrast;
	public:
		Circle(double r, color hue, bool vis = false, bool con = false) {
			radius = r;
			cn = hue;
			visibility = vis;
			contrast = con;
		}
		void appearance() {
			visibility = visible;				// legal, static
			//contrast = bright;					// illegal, local scope
			contrast = ::bright;					// legal, global scope	
		}
		double area() const { return PI * radius * radius; }
	};
	Circle c1(rad, c);							// create Circle object
	cout << c1.area() << endl;					// display Circle's area
	cout << bright << ' ' << visible << endl;
}

int main()
{
	make_circle(10, red);
	return 0;
}

/**********************************************************************

$ local 
314.159
1 1

*/
