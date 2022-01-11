// circle.C - const data members
#include <iostream.h>
#include <math.h>
#define PI M_PI

class Circle {
private:
	const double radius;
	const double areav;
	const double circumv;
public:
	Circle(double r=1) : radius(r), areav(PI * r * r), circumv(2 * PI * r) { }
	double area() const { return areav; }
	double circum() const { return circumv; }
	double getrad() const { return radius; }
};

int main()
{
	Circle c1(10);
	const Circle c2(20);
	const Circle c3 = c2;						// same as const Circle c3(c2)
	cout << c1.area() << ' ' << 
				c2.circum() << ' ' << c3.circum() << endl;
	return 0;
}

/**********************************************************************

$ circle 
314.159 125.664 125.664

*/
