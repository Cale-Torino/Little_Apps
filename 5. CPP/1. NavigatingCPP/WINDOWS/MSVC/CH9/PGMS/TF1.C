// tf1.c - template functions
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline void f(const TYPE &) { }					// inline

template <class TYPE>
extern TYPE g(const TYPE &);					// external - pgm scope

template <class TYPE>
String h(const TYPE &) { }

int main() {
	//template <class TYPE>
	//inline void f(const TYPE &);				// illegal - local scope
	return 0;
}
