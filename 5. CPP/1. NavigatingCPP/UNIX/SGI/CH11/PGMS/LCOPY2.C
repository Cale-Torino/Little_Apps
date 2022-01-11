// lcopy2.C - Show deepcopy semantics with polymorphic type
#include "Shape.h"
#include "ListCopy.h"

void build_list(ListCopyA<Shape> &);

int main()
{
	ListCopyA<Shape> list1;							// instantiate list

	build_list(list1);
	ListCopyA<Shape> list2(list1);				// copy constructor
	cout << "List 1 = " << list1 << endl;		// display entire list
	cout << "List 2 = " << list2 << endl;		// display entire list
	PtrIterator<Shape> iter1(list1);				// list iterator
	delete list1.remove(iter1);					// remove first item
	list2 = list1;										// assignment
	cout << "List 1 = " << list1 << endl;		// display entire list
	cout << "List 2 = " << list2 << endl;		// display entire list
	return 0;
}

void build_list(ListCopyA<Shape> & list) {
	list.append(new Square(5));
	list.append(new Circle(3));
	list.append(new RTriangle(4, 6));
	cout << "Shape list built with " << 
		list.length() << " shapes." << endl;
}

/**********************************************************************

$ lcopy2
Shape list built with 3 shapes.
List 1 = Square: side 5 Circle: radius 3 RTriangle: height 4, base 6 
List 2 = Square: side 5 Circle: radius 3 RTriangle: height 4, base 6 
List 1 = Circle: radius 3 RTriangle: height 4, base 6 
List 2 = Circle: radius 3 RTriangle: height 4, base 6 
 
*/
