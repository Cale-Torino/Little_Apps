// pixel.C - Pixel template class (Derived class Generic) 
#include <iostream.h>
#include "Point3.h"
#include "String.h"

template <class TYPE>                      
class Pixel : public Point {
private:
   TYPE c;
public:
    Pixel(const TYPE & cn, double x, double y) : Point(x, y), c(cn) { }
};

enum color { red, blue, green };

int main()
{
   Pixel <color> p(red, 10.5, 10.5);
   Pixel <String> q("dot", -3.4, -6.7);
   return 0;
}
