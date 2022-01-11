// node1.C - instantiations of class Node
#include <iostream.h>
#include "String.h"

template <class TYPE>
class Node {								// generic Node
private:
	TYPE data;								// generic data item
	Node<TYPE> *pd;						// pointer to another Node
public:
	Node(TYPE);								// inefficient ...
	TYPE getdata() const { return data; }
};

template <class TYPE>
Node<TYPE>::Node(TYPE n) { data = n; }			// inefficient ...

int main()
{
	int num = 12;	String s = "abc";
	Node<int> a = num;						// integer Node
	Node<String> b = s;						// String Node
	cout << a.getdata() << ' ' << b.getdata() << endl;
	return 0;
}

/**********************************************************************

$ node1
12 abc

*/
