#include "Labs.h"

#include <iostream>

using namespace std;

struct BookPublisher {
public:
	string _name;
	BookPublisher() {
		_name = "None";
	}
	BookPublisher(string name) {
		_name = name;
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
		_name = "None";
		_author = "None";
		_bookPublisher = BookPublisher();
		_year = 0;
		_list = 0;
	}
	Book(string name, string author, BookPublisher bookPublisher, int year, int list) {
		_name = name;
		_author = author;
		_bookPublisher = bookPublisher;
		_year = _year;
		_list = list;
	}
	void set(Book book) {
		_name = book._name;
		_author = book._author;
		_bookPublisher = book._bookPublisher;
		_year = book._year;
		_list = book._list;
	}
	Book & get() {
		return *this;
	}
	void show(bool trust) {
		if (trust) {
			cout << "Book name:" << _name << "| author:" << _author << "| publisher: " << _bookPublisher._name << "| year: " << _year << "| lists: " << _list << endl;
			return;
		}
		cout << "Book name:" << _name << "| author:" << endl;
	}

};