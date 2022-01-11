// shapes.C - PtrList class with Shapes
#include <iostream.h>
#include "PtrList.h"
#include "Shape.h"

void build_list(PtrList<Shape> &);
void shape_info(const PtrList<Shape> &);

int main() 
{
	try {
		 PtrList<Shape> shapelist;

		 build_list(shapelist);							// build a Shape list
		 shape_info(shapelist);							// display Shape data

		 PtrIterator<Shape> iter(shapelist);
		 delete shapelist.remove(iter);				// remove first Shape
		 cout << "There are " << Shape::num_shapes() 
				 << " shapes left" << endl;
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

void build_list(PtrList<Shape> & list) {
	list.append(new Square(5));
	list.append(new Circle(3));
	list.append(new RTriangle(4, 6));
	cout << "Shape list built with " << 
			Shape::num_shapes() << " shapes" << endl;
}

void shape_info(const PtrList<Shape> & list) {
	for (PtrIterator<Shape> iter(list); !iter; iter++) {
		cout << "I'm a " << *iter() << ", ";
		cout << "area " << iter()->area() << " and ";
		cout << "perimeter " << iter()->perimeter() << endl;
	}
}

/***************************************************************

$ shapes
Shape list built with 3 shapes
I'm a Square: side 5, area 25 and perimeter 20
I'm a Circle: radius 3, area 28.2743 and perimeter 18.8496
I'm a RTriangle: height 4, base 6, area 12 and perimeter 17.2111
There are 2 shapes left

*/
