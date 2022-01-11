// ref.C - const reference arguments
#include <iostream.h>

const int MaxBuf = 20;
struct block {
	char buf[MaxBuf];
	int used;
};

int main()
{
	void display(const block &);							// prototype for display()
	block data;
	int i;

	data.used = 5;
	for (i = 0; i < data.used; i++)						// assign some values
		data.buf[i] = i + 'a';
	display(data);
	
	data.used = MaxBuf;
	for (i = 0; i < data.used; i++)
		data.buf[i] = i + 'a';
	display(data);												// call by reference
	return 0;
}

void display(const block & blockref) {
	for (int i = 0; i < blockref.used; i++)
		cout << blockref.buf[i] << ' ';
	cout << endl;
}

/*******************************************************************

$ ref
a b c d e 
a b c d e f g h i j k l m n o p q r s t 

*/
