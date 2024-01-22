#ifndef LABS_H
#define LABS_H

#include <string>

using namespace std;

class Book {
	string _name;
	string _author;
	string _bookPublisher;
	int _year;
	int _list;
public:

	Book(string name, string author, string bookPublisher, int year, int list);
	Book();
	void set(Book book);
	string getName();
	string getAuthor();
	string getBookPublisher();
	int getYear();
	int getList();
	void show(bool trust);
};

#endif
