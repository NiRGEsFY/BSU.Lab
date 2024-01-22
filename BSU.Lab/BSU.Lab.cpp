#include <iostream>
#include "Labs.h"
using namespace std;

int main()
{
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

    return 0;
}
