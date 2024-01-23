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

bool Quotes(const string& s);
void QuotesTest(const string& s);

template<class T> class MatrixTemplate {
private:
	T** _matrix;
	int _lenght;
public:
	MatrixTemplate();
	MatrixTemplate(int lenght);
	MatrixTemplate(T** matrix, int lenght);
	T** AdditionMatrix(MatrixTemplate matrix);
	void AdditionMatrix(MatrixTemplate matrix, MatrixTemplate matrix2);
	T** DifferenceMatrix(MatrixTemplate matrix);
	void DifferenceMatrix(MatrixTemplate matrix, MatrixTemplate matrix2);
	T** MultiplicationMatrix(MatrixTemplate matrix);
	void MultiplicationMatrix(MatrixTemplate matrix, MatrixTemplate matrix2);
	T NormaMatrix();
	void Show();
	T** GetMatrix();
	int GetLenght();
	void SetMatrix(T** matrix, int lenght);
	void SetMatrix(MatrixTemplate matrix);
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