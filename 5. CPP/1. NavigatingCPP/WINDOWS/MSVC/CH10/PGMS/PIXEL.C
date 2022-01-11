// pixel.C - Template class default types
#include <iostream.h>
#include "Point5.h"
#include "String.h"

template <class TYPE = String>                      
class Pixel {
private:
	Point p;
   TYPE attrib;
public:
    Pixel(double x, double y, const TYPE & a) : p(x, y), attrib(a) { }
	 TYPE get_attrib() const { return attrib; }
};

int main()
{
   Pixel <int> p(10.5, 10.5, 0);
   Pixel <> q(-3.4, -6.7, "colorbar");

	cout << p.get_attrib() << endl;
	cout << q.get_attrib() << endl;
   return 0;
}

/************************************************************************

$ pixel
0
colorbar

*/
