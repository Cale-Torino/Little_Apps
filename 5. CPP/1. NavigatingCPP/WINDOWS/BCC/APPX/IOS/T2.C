// t2.c- file status
#include <iostream.h>
#include <stdio.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>

const int MaxSz = 80;
char buf[MaxSz];

int main()
{
	bool status = true;
	bool notso = false;
	char *mystring = "red and white";

	cout << "status = " << status << " notso = " << notso << endl;
	cout << setiosflags(ios::boolalpha);
	cout << "status = " << status << " notso = " << notso << endl;
	cout << resetiosflags(ios::boolalpha);
	cout << "status = " << status << " notso = " << notso << endl;
	cout << mystring << endl;

	cout << setiosflags(ios::showbase);
	int i = 64, *ip = &i;
	long addr = (long)ip;
	cout << "i = " << "(dec): " << i;
	cout << " (hex): " << hex << i;
	cout << " (oct): " << oct << i << endl;
	cout << "******************" << endl;
	cout << "i = " << i << endl;
	cout << oct << i << endl;
	cout << dec << i << endl;
	cout << hex << i << endl;
	// use other form
	cout << setbase(10);
	cout << "i(10) = " << i << endl;
	cout << setbase(8);
	cout << "i(8) = " << i << endl;
	cout << setbase(16);
	cout << "i(16) = " << i << endl;

	cout << setiosflags(ios::dec);
	cout << "ip = " << ip << endl;		// default
	cout << "(long)ip = " << (long)ip << endl;		// default
	cout << "addr = " << addr << endl;
	cout << "mystring ptr = " << static_cast<void *>(mystring) << endl;

	char buf[] = "Write writes the right stuff";
	cout.write(buf, strlen(buf));
	cout << endl;
	for (i = 0; i < strlen(buf); i++)
		cout.put(buf[i]);
	cout << endl;

	cout << 1;
	printf("2");
	cout << 3;
	printf("4\n");
	cout << setiosflags(ios::unitbuf | ios::stdio);
	cout << 1;
	printf("2");
	cout << 3;
	printf("4\n");
	cout << resetiosflags(ios::unitbuf | ios::stdio);
	return 0;
}

/***************************************************************************

$ t2
status = 1 notso = 0
status = true notso = false
status = 1 notso = 0
red and white
i = (dec): 64 (hex): 0x40 (oct): 0100
******************
i = 0100
0100
64
0x40
i(10) = 64
i(8) = 0100
i(16) = 0x40
ip = 0xffd0
(long)ip = 391905232
addr = 391905232
mystring ptr = 0x00c5
Write writes the right stuff
Write writes the right stuff
1234
1234

*/
