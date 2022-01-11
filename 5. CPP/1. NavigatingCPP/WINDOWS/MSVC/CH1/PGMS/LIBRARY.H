#ifndef LIBRARYH
#define LIBRARYH
// Library.h - Library interface
#include "String.h"
#include "ListCopy.h"
#include "Assoc.h"

class Library;
class Person;
class Catalog_of_LibraryMembers;
class LibraryMember;
class BookCatalog;
class LibraryBook;
class Date;

class Library {
private:
	String name;
	Catalog_of_LibraryMembers* ptrCatalog_of_LibraryMembers;
	BookCatalog* ptrBookCatalog;
public:
	Library(const String & n = "") : name(n) { }
	String getname() const { return name; }
};

class Person {
private:
	String fullname;
};

class Catalog_of_LibraryMembers {
private:
	Assoc<String,LibraryMember *> memberlist;
public:
	Catalog_of_LibraryMembers():memberlist(25) { }
	LibraryMember *search_CardID(const String &) const { return 0; }
	LibraryMember *search_fullname(const String &) const { return 0; }
	void add(LibraryMember *) { }
	void remove(LibraryMember *) { }
};

class Date {
private:
	int day;
	int month;
	int year;
};

class BookCatalog {
private:
	// map ISBN with list of LibraryBooks
	Assoc<String, ListCopyC<LibraryBook> > booklist;
public:
	BookCatalog() : booklist(25) { }
	bool search_ISBN(const String &, ListCopyC<LibraryBook> &) const 
		{ return true; }
	bool search_title(const String &, ListCopyC<LibraryBook> &) const 
		{ return true; }
	bool search_author(const Person &, ListCopyC<LibraryBook> &) const 
		{ return true; }
	void add(LibraryBook *) { }
	void remove(LibraryBook *) { }
};

class LibraryMember : public Person {
private:
	String CardID;
	Assoc<String, LibraryBook *> borrowed_books; 	// map title with LibraryBook
public:
	LibraryMember() : borrowed_books(25) { }
	void checkout (LibraryBook *) { }
};

class LibraryBook {
private:
	String title;
	String publisher;
	String ISBN;
	Person author;
	Date *due_date; 						// only significant when checked out
	LibraryMember *borrower;
public:
	void checkout(LibraryMember *) { }
	void print(ostream & os) const { os << title << endl; }
};

ostream & operator<<(ostream & os, const LibraryBook & lb) {
	lb.print(os);
	return os;
}
#endif
