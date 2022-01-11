// using2.C - dominance with overloaded virtual functions
#include <iostream.h>

class Word { };
class Sentence { };
class Character { };

class Paragraph {
public:
	virtual ~Paragraph() { }
	virtual void remove(Word *);
	virtual void remove(Sentence *);
	virtual void remove(Character *);
};

class JustifiedParagraph : public Paragraph {
public:
	using Paragraph::remove;			// bring them all into current scope
	void remove(Sentence *);			// override
};

void Paragraph::remove(Word *)
{ cout << "Paragraph::remove(Word *)" << endl; }

void Paragraph::remove(Sentence *)
{ cout << "Paragraph::remove(Sentence *)" << endl; }

void Paragraph::remove(Character * )
{ cout << "Paragraph::remove(Character *)" << endl; }

void JustifiedParagraph::remove(Sentence * )
{ cout << "JustifiedParagraph::remove(Sentence *)" << endl; }

int main()
{
	JustifiedParagraph *jp = new JustifiedParagraph;
	Paragraph *prp = jp;
	Word w;
	Sentence s;
	Character c;
	prp->remove(&w);
	prp->remove(&s);
	prp->remove(&c);
	jp->remove(&w);
	jp->remove(&s);
	jp->remove(&c);
	delete jp;
	return 0;
}

/******************************************************************

$ using2
Paragraph::remove(Word *)
JustifiedParagraph::remove(Sentence *)
Paragraph::remove(Character *)
Paragraph::remove(Word *)
JustifiedParagraph::remove(Sentence *)
Paragraph::remove(Character *)

*/
