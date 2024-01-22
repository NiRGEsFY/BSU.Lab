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


void Labs::First() {
	setlocale(LC_ALL, "Russian");
	Book* books = new Book[5];
	books[0] = Book("Маргаритка", "Эля", "Бром", 2025, 991);
	books[1] = Book("Роджерс и Андерс", "Эля", "Тен", 2021, 512);
	books[2] = Book("Приключения Роба", "Антон", "Тен", 2015, 122);
	books[3] = Book("Адские робрышки", "Антон", "Бром", 2009, 421);
	books[4] = Book("Робототехника", "Крон", "Бром", 2015, 421);
	for (int i = 0; i < 5; i++) {
		books[i].show(true);
	}
	cout << "По автору:" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getAuthor() == "Антон") {
			books[i].show(true);
		}
	}
	cout << "По издателю" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getBookPublisher() == "Бром") {
			books[i].show(true);
		}
	}
	cout << "По году" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getYear() == 2015) {
			books[i].show(true);
		}
	}
}
