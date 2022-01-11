// switch2.C - switch construct, enumerated types
#include <iostream.h>
#include <sys/types.h>
#include <unistd.h>

enum colors { red = 1, yellow = 2, blue = 4 };

colors getcolor() {
   return colors(getpid() % 7);
}

int main() {
  colors paint = getcolor();

  switch (paint) {
    case red:
    case yellow:
    case blue:
      cout << "It's primary" << endl;
      break;
    case red + yellow:
      cout << "It's orange" << endl;
      break;
    case blue + yellow:
      cout << "It's green" << endl;
      break;
    case blue + red:
      cout << "It's violet" << endl;
      break;
    case red + blue + yellow:
      cout << "It's black" << endl;
      break;
    default:
      cout << "It's white" << endl;
      break;
  }
  cout << paint << endl;
  return 0;
}

/**********************************************************************

$ switch2
It's primary
1

*/
