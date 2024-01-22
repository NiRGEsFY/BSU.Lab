#ifndef LABS_H
#define LABS_H

#include <string>

using namespace std;

class Book {
private:
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
class Matrix {
private:
	int** _matrix;
	int _lenght;
public:
	Matrix();
	Matrix(int lenght);
	Matrix(int** matrix, int lenght);
	void Show();
	int** GetMatrix();
	int GetLenght();
	int** AdditionMatrix(Matrix matrix);
	void AdditionMatrix(Matrix matrix, Matrix matrix2);
	int** DifferenceMatrix(Matrix matrix);
	void DifferenceMatrix(Matrix matrix, Matrix matrix2);
	int** MultiplicationMatrix(Matrix matrix);
	void MultiplicationMatrix(Matrix matrix, Matrix matrix2);
	int NormaMatrix();
	void SetMatrix(int** matrix, int lenght);
	void SetMatrix(Matrix matrix);
};


class Labs {
public:
	void First();
	void Second();
	void Thirdy();
	void Forth();
	void Fifth();
	void Sixth();
	void Seventh();
	void Eighth();
};

#endif