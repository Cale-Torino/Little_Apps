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
Mpool constr(size, nitems): 2,256
Mpool::alloc - 0x1756
Mpool::alloc - 0x1758
Mpool::alloc - 0x175a
Mpool::alloc - 0x175c
Mpool::alloc - 0x175e
Mpool::alloc - 0x1760
Mpool::alloc - 0x1762
Mpool::alloc - 0x1764
Mpool::alloc - 0x1766
Mpool::alloc - 0x1768
Mpool::alloc - 0x176a
Mpool::dealloc - 0x1756
Mpool::dealloc - 0x1758
Mpool::dealloc - 0x175a
Mpool::dealloc - 0x175c
Mpool::dealloc - 0x175e
Mpool::dealloc - 0x1760
Mpool::dealloc - 0x1762
Mpool::dealloc - 0x1764
Mpool::dealloc - 0x1766
Mpool::dealloc - 0x1768
Mpool::dealloc - 0x176a
Mpool destructor

*/
