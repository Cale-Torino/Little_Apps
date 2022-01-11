// mp1.c - class specific overloading new and delete, memory pools
#include "A1.h"

int main()
{
	try {
		 A *p1 = new A;							// A::new(sizeof(A))
		 A *p2 = new A;							// A::new(sizeof(A))
		 A *p3 = new A;							// A::new(sizeof(A))
		 A *p4 = new A;							// A::new(sizeof(A))
		 A *p5 = new A;							// A::new(sizeof(A))
		 A *p6 = new A;							// A::new(sizeof(A))
		 A *p7 = new A;							// A::new(sizeof(A))
		 A *p8 = new A;							// A::new(sizeof(A))
		 A *p9 = new A;							// A::new(sizeof(A))
		 A *pa = new A;							// A::new(sizeof(A))
		 A *pb = new A;							// A::new(sizeof(A))

		 delete p1;
		 delete p2;
		 delete p3;
		 delete p4;
		 delete p5;
		 delete p6;
		 delete p7;
		 delete p8;
		 delete p9;
		 delete pa;
		 delete pb;
	}
	catch (const MpoolError & e) {
		e.response();
		A::free_pool();						// free Memory pool
		return 1;
	}
	A::free_pool();							// free Memory pool
	return 0;
}

/**********************************************************************

$ mp1 
Mpool constr(size, nitems): 4,256
Mpool::alloc - 0x10014708
Mpool::alloc - 0x1001470c
Mpool::alloc - 0x10014710
Mpool::alloc - 0x10014714
Mpool::alloc - 0x10014718
Mpool::alloc - 0x1001471c
Mpool::alloc - 0x10014720
Mpool::alloc - 0x10014724
Mpool::alloc - 0x10014728
Mpool::alloc - 0x1001472c
Mpool::alloc - 0x10014730
Mpool::dealloc - 0x10014708
Mpool::dealloc - 0x1001470c
Mpool::dealloc - 0x10014710
Mpool::dealloc - 0x10014714
Mpool::dealloc - 0x10014718
Mpool::dealloc - 0x1001471c
Mpool::dealloc - 0x10014720
Mpool::dealloc - 0x10014724
Mpool::dealloc - 0x10014728
Mpool::dealloc - 0x1001472c
Mpool::dealloc - 0x10014730
Mpool destructor

NOTES:
	1. Inside the private section of Mpool.h, we use **chunks to point to an array of 
		Alloc * pointers that we will create and extend on the fly.

	2. The Mpool constructor calls malloc() to create the Alloc * array, and the Mpool 
		destructor calls free() to release it.

	3. The grow() function calls realloc() to extend the Alloc * array by enumerator
		delta (50).

*/
