// setnh.c - set_new_handler
#include <iostream.h>
#include <new.h>
#include <stdlib.h>

const int bsize = 512;
int *psav;
bool allocate = true;

void get_memory() {
	cerr << "free store exhausted" << endl;
	delete [] psav;									// release saved block
	allocate = false;
}

void eat_memory(int size) {
	int *p = new int[size];							// allocate memory
	if (allocate)
		eat_memory(size);								// recursive call
	else
		cerr << "free store addr = " << p << endl;
}

int main()
{
	set_new_handler(get_memory);					// specify handler
	psav = new int[bsize];							// block to save
	cerr << "free store addr = " << psav << endl;
	eat_memory(bsize);
	return 0;
}

/***************************************************************

$ setnh
free store addr = 0x006529e8
free store exhausted
free store addr = 0x006529e8

*/
