// shape2.C - display shapes
#include <iostream.h>
#include "PtrList.h"
#include "Shape.h"

void build_list(PtrList<Shape> &);
void myshape(Shape *);

int main() 
{
	try {
		PtrList<Shape> shapelist;
		build_list(shapelist);							// build a Shape list

		for (PtrIterator<Shape> iter(shapelist); !iter; iter++) 
			myshape(iter());
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

void build_list(PtrList<Shape> & list) {
	list.append(new Circle(3));
	list.append(new Square(5));
	list.append(new Special_Circle(4));
	list.append(new RTriangle(4, 6));
	list.append(new Very_Special_Circle(5, "Loom"));
}

void myshape(Shape *sp) {
	Special_Circle *scp = dynamic_cast<Special_Circle *>(sp);
	if (scp) 
		scp->set_password("RTTI_is_cool");
	cout << "I'm a " << *sp << endl;
}

/**********************************************************************

$ shape2
I'm a class Circle: radius 3
I'm a class Square: side 5
I'm a class Special_Circle: radius 4
My password is RTTI_is_cool

I'm a class RTriangle: height 4, base 6
I'm a class Very_Special_Circle: radius 5
My password is RTTI_is_cool
My title is Loom


*/
