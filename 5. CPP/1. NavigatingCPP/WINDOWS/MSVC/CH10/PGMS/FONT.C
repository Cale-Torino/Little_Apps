// font.c - templates with typedefs and enumerations
#include <iostream.h>
#include "Buffer.h"

template <class TYPE, int height, int width>
class Font {
public:
	enum contrast { dim, bright };
private:
	contrast c;
	typedef Buffer<TYPE, height*width> pointbuf;
	pointbuf p;
	enum pvalues { first = 0, last = height*width-1 };
public:
	Font(contrast cf = bright) : c(cf) { }
};

class Point { };
typedef Font<Point, 10, 10> Palentino;
typedef Font<Point, 15, 15> Gothic;

int main()
{
	try {
		Palentino p;									// bright by default
		Gothic g;										// bright by default
		Gothic h(Gothic::dim);						// Gothic font is dim
	}
	catch (const BufferError & e) {
		e.response();
		return 1;
	}
	return 0;
}
