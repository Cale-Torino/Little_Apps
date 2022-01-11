// answer.C - answering machine
#include "Message.h"

int main()
{
	try {
		 Machine answer;
		 answer.execute();
	}
	catch(const Error_Condition & except_obj) {
		// handle exception here
		return 1;
	}
	return 0;
}

/************************************************************************

$ answer
Input outgoing msg: On vacation until the 12th
Outgoing message playback: On vacation until the 12th
Input outgoing msg: Not home, leave a message
Outgoing message playback: Not home, leave a message
Outgoing message playback: On vacation until the 12th
Input incoming msg: Dinner on Friday nite?
Outgoing message playback: On vacation until the 12th
Input incoming msg: Call me as soon as you can
Outgoing message playback: On vacation until the 12th
Input incoming msg: Do you want football tickets?
Outgoing message playback: On vacation until the 12th
Outgoing message playback: Not home, leave a message
Incoming message playback: Dinner on Friday nite?
Incoming message playback: Call me as soon as you can
Incoming message playback: Do you want football tickets?

*/
