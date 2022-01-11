// setnh.c - set_new_handler
#include <iostream.h>
#include <new.h>
#include <stdlib.h>

void memfail() {
	cerr << "no free store memory" << endl;
	exit(1);
}

void get_memory(int size) {
	int *p = new int[size];
	cerr << "memory address is " << p << endl;
	delete [] p;
}

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " length" << endl;
		return 1;
	}
	int size = atoi(argv[1]);

	set_new_handler(memfail);				// specify handler
	get_memory(size);
	return 0;
}

/***************************************************************

$ setnh 50
memory address is 0xc910

$ setnh 50000000
no free store memory

*/
