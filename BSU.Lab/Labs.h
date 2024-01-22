#ifndef LABS_H
#define LABS_H

#include <string>

using namespace std;

struct BookPublisher {
public:
	string Name;
	BookPublisher() {

	}
};

class Book {
public:
	string _name;
	string _author;
	BookPublisher _bookPublisher;
	int _year;
	int _list;

	Book() {

	}
	void set() {

	}
	void get() {

	}
	void show() {

	}
};

#endif