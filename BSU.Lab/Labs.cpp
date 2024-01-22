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

Book::Book() {
	_name = "None";
	_author = "None";
	_bookPublisher = "None";
	_year = 0;
	_list = 0;
}
Book::Book(string name, string author, string bookPublisher, int year, int list) {
	_name = name;
	_author = author;
	_bookPublisher = bookPublisher;
	_year = year;
	_list = list;
}
void Book::set(Book book) {
	_name = book._name;
	_author = book._author;
	_bookPublisher = book._bookPublisher;
	_year = book._year;
	_list = book._list;
}
int Book::getList(){
	return _list;
}
int Book::getYear() {
	return _year;
}
string Book::getBookPublisher() {
	return _bookPublisher;
}
string Book::getAuthor() {
	return _author;
}
string Book::getName() {
	return _name;
}
void Book::show(bool trust) {
	if (trust) {
		cout << "Название:" << _name << "| автор:" << _author << "| издатель: " << _bookPublisher << "| год: " << _year << "| страницы: " << _list << endl;
		return;
	}
	cout << "Название:" << _name << "| автор:" << _bookPublisher << endl;
}
