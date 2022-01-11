// com.C - command line arguments
#include <iostream.h>

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " option filename" << endl;
		return 1;
	}
	cout << argv[1] << '\t' << argv[2] << endl;
	cout << argv[1][0] << '\t' << argv[1][1] << endl;
	return 0;
}

/*******************************************************************

$ com
Usage: com option filename

$ com -r file
-r		file
-		r

*/
