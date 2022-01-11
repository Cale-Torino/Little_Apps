// defs.C - exported template function
#include <iostream.h>
#include "defs.h"
#define export

export template <class TYPE>
void print(const TYPE *a, int len) {
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;
}
