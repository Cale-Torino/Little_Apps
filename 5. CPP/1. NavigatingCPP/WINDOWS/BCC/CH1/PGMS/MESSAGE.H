#ifndef MESSAGEH
#define MESSAGEH
// Message.h -Message machine
#include <iostream.h>
#include "String.h"
#include "PtrList.h"

class Error_Condition { };					// exception class

class Message {
protected:
	String msgtext;							// accessible to derived classes
public:
	virtual ~Message() {  }
	virtual void record() = 0;
	virtual void erase() = 0;
	virtual void playback(ostream & os) const = 0;
};

ostream & operator<<(ostream & os, const Message & msg) {
	msg.playback(os);							// virtual call
	return os;
}

class Out_Going_Message : public Message {
public:
	void record() { cout << "Input outgoing msg: "; cin >> msgtext; }
	void erase() { cout << "Erase outgoing msg\n"; msgtext = ""; }
	void playback(ostream & os) const 
		{ os << "Outgoing message playback: " << msgtext << endl; }
};

class In_Coming_Message : public Message {
public:
	void record() { cout << "Input incoming msg: "; cin >> msgtext; }
	void erase() { cout << "Erase incoming msg\n"; msgtext = ""; }
	void playback(ostream & os) const 
		{ os << "Incoming message playback: " << msgtext << endl; }
};

class Error_Message : public Out_Going_Message {
public:
	void playback(ostream & os) const { 
		os << "Error message playback: " << endl; 
		Out_Going_Message::playback(os);
	}
};

class Machine {
private:
	PtrList<Out_Going_Message> msg_output;
	PtrList<In_Coming_Message> msg_input;
public:
	void execute() throw (Error_Condition);
	void setup() throw (Error_Condition);
};

void Machine::setup() throw (Error_Condition) {
	Out_Going_Message *msgptr = new Out_Going_Message;
	msgptr->record();
	msgptr->playback(cout);
	msg_output.append(msgptr);
	msgptr = new Out_Going_Message;
	msgptr->record();
	msgptr->playback(cout);
	msg_output.append(msgptr);
}

void Machine::execute() throw (Error_Condition) {
	setup();
	PtrIterator<Out_Going_Message> iter_out(msg_output);
	In_Coming_Message *inptr;
	for (int i = 0; i < 3; i++) {
		iter_out()->playback(cout);
		inptr = new In_Coming_Message;
		inptr->record();
		msg_input.append(inptr);
	}
	for (iter_out.restart(); !iter_out; iter_out++)
		iter_out()->playback(cout);

	for (PtrIterator<In_Coming_Message> iter_in(msg_input); !iter_in; iter_in++)
		iter_in()->playback(cout);
}
#endif
