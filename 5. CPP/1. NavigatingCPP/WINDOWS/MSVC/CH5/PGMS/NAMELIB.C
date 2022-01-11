// namelib.C - namespaces and libraries
#include "contain.h"
#include "allstack.h"

namespace CATS = Containers_and_Things;					// alias 
namespace STACK = All_Its_Stacked_Up_To_Be;				// alias

void sub() {
	using CATS::ArrayInt;				// using declaration
	using STACK::StackChr;				// using declaration

	ArrayInt a(100);						// from CATS
	StackChr b(80);						// from STACK
}

int main()
{
	sub();
	return 0;
}
