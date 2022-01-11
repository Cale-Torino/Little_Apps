// ptrlist3.C - STL list container with pointer semantics, generic destroy
#include <iostream.h>
#include <list.h>
#include "Shape.h"

template <class Container>
void destroy_objects(Container &);

template <class TYPE>
class PtrList : public list<TYPE *> {
public:
	PtrList() { }
	~PtrList() { destroy_objects(*this); }
};

void build_list(PtrList<Shape> &);
void shape_info(PtrList<Shape> &);

int main() 
{
	PtrList<Shape> shapelist;

	build_list(shapelist);						// build Shape * list
	shape_info(shapelist);						// display Shape data

	delete shapelist.front();					// delete Shape at front
	shapelist.pop_front();						// remove ptr from shapelist
	cout << "There are " << Shape::num_shapes() 
			<< " shapes left" << endl;
	return 0;
}

void build_list(PtrList<Shape> & ls) {
	ls.push_back(new Square(5));
	ls.push_back(new Circle(3));
	ls.push_back(new RTriangle(4, 6));
	cout << "Shape list built with " << 
			Shape::num_shapes() << " shapes" << endl;
}

void shape_info(PtrList<Shape> & ls) {
	PtrList<Shape>::const_iterator iter = ls.begin();
	for (; iter != ls.end(); iter++) {
		cout << "I'm a " << *(*iter) << ", ";
		cout << "area " << (*iter)->area() << " and ";
		cout << "perimeter " << (*iter)->perimeter() << endl;
	}
}

template <class Container>
void destroy_objects(Container & c) {
	Container::iterator iter = c.begin();
	for (; iter != c.end(); iter++)
		delete *iter;
}

/******************************************************************

$ ptrlist3
Shape list built with 3 shapes
I'm a Square: side 5, area 25 and perimeter 20
I'm a Circle: radius 3, area 28.2743 and perimeter 18.8496
I'm a RTriangle: height 4, base 6, area 12 and perimeter 17.2111
There are 2 shapes left

*/
