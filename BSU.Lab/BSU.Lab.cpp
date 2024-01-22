#include <iostream>
#include "Labs.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
    Book* books = new Book[5];
	books[0] = Book("����������", "���", "����", 2025, 991);
	books[1] = Book("������� � ������", "���", "���", 2021, 512);
	books[2] = Book("����������� ����", "�����", "���", 2015, 122);
	books[3] = Book("������ ��������", "�����", "����", 2009, 421);
	books[4] = Book("�������������", "����", "����", 2015, 421);
	for (int i = 0; i < 5; i++) {
		books[i].show(true);
	}
	cout << "�� ������:" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getAuthor() == "�����") {
			books[i].show(true);
		}
	}
	cout << "�� ��������" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getBookPublisher() == "����") {
			books[i].show(true);
		}
	}
	cout << "�� ����" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getYear() == 2015) {
			books[i].show(true);
		}
	}

    return 0;
}