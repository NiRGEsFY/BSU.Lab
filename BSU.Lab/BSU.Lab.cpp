#include "Labs.h"
#include <math.h>
#include <windows.h>
#include <iostream>
#include <stack>

using namespace std;

//Matrix start
Matrix::Matrix() {
	_lenght = 2;
	int** matrix{ new int* [_lenght] {} };
	_matrix = matrix;
	for (int i = 0; i < _lenght; i++) {
		_matrix[i] = new int[_lenght] {};
	}
	srand(time(NULL));
	for (int i = 0; i < _lenght; i++) {
		for (int j = 0; j < _lenght; j++) {
			_matrix[i][j] = rand() % 10;
		}
	}
}
Matrix::Matrix(int lenght) {
	_lenght = lenght;
	int** matrix{ new int* [_lenght] {} };
	_matrix = matrix;
	for (int i = 0; i < _lenght; i++) {
		_matrix[i] = new int[_lenght] {};
	}
	Sleep(1000);
	srand(time(NULL));
	for (int i = 0; i < _lenght; i++) {
		for (int j = 0; j < _lenght; j++) {
			int temp = rand() % 10;
			_matrix[i][j] = temp;
		}
	}
}
Matrix::Matrix(int ** matrix, int lenght) {
		_lenght = lenght;
		_matrix = matrix;
	}
void Matrix::Show() {
		for (int i = 0; i < _lenght; i++) {
			for (int j = 0; j < _lenght; j++) {
				cout << _matrix[i][j] << " | ";
			}
			cout << endl;
		}
	}
int** Matrix::GetMatrix() {
		return _matrix;
	}
int Matrix::GetLenght() {
		return _lenght;
	}
int** Matrix::AdditionMatrix(Matrix matrix) {
		int** newMatrix{ new int* [_lenght] {} };
		for (int i = 0; i < _lenght; i++) {
			newMatrix[i] = new int[_lenght] {};
		}
		if (_lenght == matrix.GetLenght()) {
			for (int i = 0; i < _lenght; i++) {
				for (int j = 0; j < _lenght; j++) {
					newMatrix[i][j] = matrix.GetMatrix()[i][j] + _matrix[i][j];
				}
			}
		}
		return newMatrix;
	}
void Matrix::AdditionMatrix(Matrix matrix, Matrix matrix2) {
		int** newMatrix{ new int* [matrix2.GetLenght()] {} };
		for (int i = 0; i < matrix2.GetLenght(); i++) {
			newMatrix[i] = new int[matrix2.GetLenght()] {};
		}
		if (matrix2.GetLenght() == matrix.GetLenght()) {
			for (int i = 0; i < matrix2.GetLenght(); i++) {
				for (int j = 0; j < matrix2.GetLenght(); j++) {
					newMatrix[i][j] = matrix.GetMatrix()[i][j] + matrix2.GetMatrix()[i][j];
				}
			}
		}
		_matrix = newMatrix;
	}
int** Matrix::DifferenceMatrix(Matrix matrix) {
		int** newMatrix{ new int* [_lenght] {} };
		for (int i = 0; i < _lenght; i++) {
			newMatrix[i] = new int[_lenght] {};
		}
		if (_lenght == matrix.GetLenght()) {
			for (int i = 0; i < _lenght; i++) {
				for (int j = 0; j < _lenght; j++) {
					newMatrix[i][j] = matrix.GetMatrix()[i][j] - _matrix[i][j];
				}
			}
		}
		return newMatrix;
	}
void Matrix::DifferenceMatrix(Matrix matrix, Matrix matrix2) {
		int** newMatrix{ new int* [matrix2.GetLenght()] {} };
		for (int i = 0; i < matrix2.GetLenght(); i++) {
			newMatrix[i] = new int[matrix2.GetLenght()] {};
		}
		if (matrix2.GetLenght() == matrix.GetLenght()) {
			for (int i = 0; i < matrix2.GetLenght(); i++) {
				for (int j = 0; j < matrix2.GetLenght(); j++) {
					newMatrix[i][j] = matrix.GetMatrix()[i][j] - matrix2.GetMatrix()[i][j];
				}
			}
		}
		_matrix = newMatrix;
	}
int** Matrix::MultiplicationMatrix(Matrix matrix) {
		int** newMatrix{ new int* [_lenght] {} };
		for (int i = 0; i < _lenght; i++) {
			newMatrix[i] = new int[_lenght] {};
		}
		if (_lenght == matrix.GetLenght()) {
			for (int i = 0; i < _lenght; i++) {
				for (int j = 0; j < _lenght; j++) {
					int temp = 0;
					for (int k = 0; k < _lenght; k++) {
						temp += _matrix[i][k] * matrix.GetMatrix()[k][j];
					}
					newMatrix[i][j] = temp;
				}
			}
		}
		return newMatrix;
	}
void Matrix::MultiplicationMatrix(Matrix matrix, Matrix matrix2) {
		int** newMatrix{ new int* [matrix2.GetLenght()] {}};
		for (int i = 0; i < matrix2.GetLenght(); i++) {
			newMatrix[i] = new int[matrix2.GetLenght()] {};
		}
		if (matrix2.GetLenght() == matrix.GetLenght()) {
			for (int i = 0; i < matrix2.GetLenght(); i++) {
				for (int j = 0; j < matrix2.GetLenght(); j++) {
					int temp = 0;
					for (int k = 0; k < matrix2.GetLenght(); k++) {
						temp += matrix2.GetMatrix()[i][k] * matrix.GetMatrix()[k][j];
					}
					newMatrix[i][j] = temp;
				}
			}
		}
		_matrix = newMatrix;
	}
int Matrix::NormaMatrix() {
		int max = 0;
		int temp = 0;
		for (int i = 0; i < _lenght; i++) {
			for (int j = 0; j < _lenght; j++) {
				if (_matrix[j][i] < 0) {
					temp -= _matrix[j][i];
				}
				else {
					temp += _matrix[j][i];
				}
			}
			if (temp > max) {
				max = temp;
			}
			temp = 0;
		}
		return max;
	}
void Matrix::SetMatrix(int ** matrix, int lenght) {
		_lenght = lenght;
		_matrix = matrix;
	}
void Matrix::SetMatrix(Matrix matrix) {
		_lenght = matrix.GetLenght();
		_matrix = matrix.GetMatrix();
	}
void MatrixToSquare(Matrix* matrixArr, int lenght) {
	for (int i = 0; i < lenght; i++) {
		matrixArr[i].MultiplicationMatrix(matrixArr[i], matrixArr[i]);
	}
}
//Matrix end

//MatrixTemplate start
template<class T> MatrixTemplate<T>::MatrixTemplate() {
	_lenght = 2;
	T** matrix{ new T * [_lenght] {} };
	_matrix = matrix;
	for (int i = 0; i < _lenght; i++) {
		_matrix[i] = new T[_lenght] {};
	}
	for (int i = 0; i < _lenght; i++) {
		for (int j = 0; j < _lenght; j++) {
			_matrix[i][j] = T();
		}
	}
};
template<class T> MatrixTemplate<T>::MatrixTemplate(int lenght) {
	_lenght = lenght;
	T** matrix{ new T * [_lenght] {} };
	_matrix = matrix;
	for (int i = 0; i < _lenght; i++) {
		_matrix[i] = new T[_lenght]{};
	}
	for (int i = 0; i < _lenght; i++) {
		for (int j = 0; j < _lenght; j++) {
			_matrix[i][j] = T();
		}
	}
}
template<class T> MatrixTemplate<T>::MatrixTemplate(T** matrix,int lenght) {
	_lenght = lenght;
	_matrix = matrix;
}

template<class T> T** MatrixTemplate<T>::AdditionMatrix(MatrixTemplate matrix) {
	T** newMatrix{ new T* [_lenght] {} };
	for (int i = 0; i < _lenght; i++) {
		newMatrix[i] = new T[_lenght] {};
	}
	if (_lenght == matrix.GetLenght()) {
		for (int i = 0; i < _lenght; i++) {
			for (int j = 0; j < _lenght; j++) {
				newMatrix[i][j] = matrix.GetMatrix()[i][j] + _matrix[i][j];
			}
		}
	}
	return newMatrix;
}
template<class T> void MatrixTemplate<T>::AdditionMatrix(MatrixTemplate matrix, MatrixTemplate matrix2) {
	T** newMatrix{ new T* [matrix2.GetLenght()] {} };
	for (int i = 0; i < matrix2.GetLenght(); i++) {
		newMatrix[i] = new T[matrix2.GetLenght()] {};
	}
	if (matrix2.GetLenght() == matrix.GetLenght()) {
		for (int i = 0; i < matrix2.GetLenght(); i++) {
			for (int j = 0; j < matrix2.GetLenght(); j++) {
				newMatrix[i][j] = matrix.GetMatrix()[i][j] + matrix2.GetMatrix()[i][j];
			}
		}
	}
	_matrix = newMatrix;
}
template<class T> T** MatrixTemplate<T>::DifferenceMatrix(MatrixTemplate matrix) {
	T** newMatrix{ new T * [_lenght] {} };
	for (int i = 0; i < _lenght; i++) {
		newMatrix[i] = new T[_lenght]{};
	}
	if (_lenght == matrix.GetLenght()) {
		for (int i = 0; i < _lenght; i++) {
			for (int j = 0; j < _lenght; j++) {
				newMatrix[i][j] = matrix.GetMatrix()[i][j] - _matrix[i][j];
			}
		}
	}
	return newMatrix;
}
template<class T> void MatrixTemplate<T>::DifferenceMatrix(MatrixTemplate matrix, MatrixTemplate matrix2) {
	T** newMatrix{ new T* [matrix2.GetLenght()] {} };
	for (int i = 0; i < matrix2.GetLenght(); i++) {
		newMatrix[i] = new T[matrix2.GetLenght()] {};
	}
	if (matrix2.GetLenght() == matrix.GetLenght()) {
		for (int i = 0; i < matrix2.GetLenght(); i++) {
			for (int j = 0; j < matrix2.GetLenght(); j++) {
				newMatrix[i][j] = matrix.GetMatrix()[i][j] - matrix2.GetMatrix()[i][j];
			}
		}
	}
	_matrix = newMatrix;
}
template<class T> T** MatrixTemplate<T>::MultiplicationMatrix(MatrixTemplate matrix) {
	T** newMatrix{ new T* [_lenght] {} };
	for (int i = 0; i < _lenght; i++) {
		newMatrix[i] = new T[_lenght] {};
	}
	if (_lenght == matrix.GetLenght()) {
		for (int i = 0; i < _lenght; i++) {
			for (int j = 0; j < _lenght; j++) {
				T temp = 0;
				for (int k = 0; k < _lenght; k++) {
					temp += _matrix[i][k] * matrix.GetMatrix()[k][j];
				}
				newMatrix[i][j] = temp;
			}
		}
	}
	return newMatrix;
}
template<class T> void MatrixTemplate<T>::MultiplicationMatrix(MatrixTemplate matrix, MatrixTemplate matrix2) {
	T** newMatrix{ new T* [matrix2.GetLenght()] {} };
	for (int i = 0; i < matrix2.GetLenght(); i++) {
		newMatrix[i] = new T[matrix2.GetLenght()] {};
	}
	if (matrix2.GetLenght() == matrix.GetLenght()) {
		for (int i = 0; i < matrix2.GetLenght(); i++) {
			for (int j = 0; j < matrix2.GetLenght(); j++) {
				T temp = 0;
				for (int k = 0; k < matrix2.GetLenght(); k++) {
					temp += matrix2.GetMatrix()[i][k] * matrix.GetMatrix()[k][j];
				}
				newMatrix[i][j] = temp;
			}
		}
	}
	_matrix = newMatrix;
}
template<class T> T MatrixTemplate<T>::NormaMatrix() {
	T max = 0;
	T temp = 0;
	for (int i = 0; i < _lenght; i++) {
		for (int j = 0; j < _lenght; j++) {
			if (_matrix[j][i] < 0) {
				temp -= _matrix[j][i];
			}
			else {
				temp += _matrix[j][i];
			}
		}
		if (temp > max) {
			max = temp;
		}
		temp = 0;
	}
	return max;
}
template<class T> void MatrixTemplate<T>::Show() {
	for (int i = 0; i < _lenght; i++) {
		for (int j = 0; j < _lenght; j++) {
			cout << _matrix[i][j] << " | ";
		}
		cout << endl;
	}
}
template<class T> T** MatrixTemplate<T>::GetMatrix() {
	return _matrix;
};
template<class T> int MatrixTemplate<T>::GetLenght() {
	return _lenght;
}
template<class T> void MatrixTemplate<T>::SetMatrix(T** matrix, int lenght) {
	_lenght = lenght;
	_matrix = matrix;
};
template<class T> void MatrixTemplate<T>::SetMatrix(MatrixTemplate matrix) {
	_lenght = matrix.GetLenght();
	_matrix = matrix.GetMatrix();
};
//MatrixTemplate end

//Book start
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
int Book::getList() {
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
		cout << "Name:" << _name << "| Author:" << _author << "| Publisher: " << _bookPublisher << "| Year: " << _year << "| Lists: " << _list << endl;
		return;
	}
	cout << "Name:" << _name << "| Publisher:" << _bookPublisher << endl;
}
//Book end

//Stack start
bool Quotes(const string& s) {
	stack<char> stack;
	for (char c : s) {
		switch (c) {

		case '(': stack.push(')'); break;
		case '[': stack.push(']'); break;
		case '{': stack.push('}'); break;

		case ')':
		case ']':
		case '}':
			if (stack.empty() || stack.top() != c) {
				return false;
			}
			stack.pop();
			break;
		default:
			break;
		}
	}
	return stack.empty();
}
void QuotesTest(const string& s) {
	cout << '|' << s << '|' << " - " << (Quotes(s) ? "Yes" : "No") << '\n';
}
//Stack end

//Labs start
void Labs::First() {
	setlocale(LC_ALL, "Russian");
	Book* books = new Book[5];
	books[0] = Book("Trone of god", "Tom", "RedCon", 2025, 991);
	books[1] = Book("End Worm", "Tom", "RedCon", 2021, 512);
	books[2] = Book("War is war", "Deni", "MonkeyType", 2015, 122);
	books[3] = Book("End game", "Deni", "MonkeyType", 2009, 421);
	books[4] = Book("Theory of sintez", "Tom", "RedCon", 2015, 421);
	for (int i = 0; i < 5; i++) {
		books[i].show(true);
	}
	cout << "Get Author:" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getAuthor() == "Tom") {
			books[i].show(true);
		}
	}
	cout << "Get Publisher" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getBookPublisher() == "MonkeyType") {
			books[i].show(true);
		}
	}
	cout << "Get Year" << endl;
	for (int i = 0; i < 5; i++) {
		if (books[i].getYear() == 2015) {
			books[i].show(true);
		}
	}
}
void Labs::Second() {
	int count = 3;
	int lenght = 3;
	Matrix* matrixArr = new Matrix[count];
	for (int i = 0; i < count; i++) {
		matrixArr[i] = Matrix(lenght);
	}
	for (int i = 0; i < count; i++) {
		matrixArr[i].Show();
		cout << endl;
	}
	MatrixToSquare(matrixArr,lenght);
	for (int i = 0; i < count; i++) {
		matrixArr[i].Show();
		cout << endl;
	}
}
void Labs::Thirdy() {
	QuotesTest("{test(a) = test[b]}");
	QuotesTest("test[1].WriteLine(End)");
	QuotesTest("Empty");
	QuotesTest("morder[2].End[} = morder.End]{");
	QuotesTest("{EndToBuild}{{ProStore]}");
}
void Labs::Forth() {
	int lenght = 4;
	MatrixTemplate<string> matrix = MatrixTemplate<string>(lenght);
	string** matrixStr = new string * [lenght];
	for (int i = 0; i < lenght; i++) {
		matrixStr[i] = new string[lenght]{};
	}
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght; j++) {
			matrixStr[i][j] = "Test";
		}
	}
	matrix.SetMatrix(matrixStr, lenght);
	matrix.Show();
	cout << endl;
	double** matrixDouble0 = new double* [lenght];
	double** matrixDouble1 = new double* [lenght];
	double** matrixDouble2 = new double* [lenght];
	srand(time(NULL));
	for (int i = 0; i < lenght; i++) {
		matrixDouble0[i] = new double[lenght] {};
		matrixDouble1[i] = new double[lenght] {};
		matrixDouble2[i] = new double[lenght] {};
	}
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght; j++) {
			matrixDouble0[i][j] = (double)rand() / 10000;
			matrixDouble1[i][j] = (double)rand() / 10000;
		}
	}
	MatrixTemplate<double> matrixTemplateDouble0 = MatrixTemplate<double>(matrixDouble0, lenght);
	MatrixTemplate<double> matrixTemplateDouble1 = MatrixTemplate<double>(matrixDouble1, lenght);
	MatrixTemplate<double> matrixTemplateDouble2 = MatrixTemplate<double>(matrixTemplateDouble0.DifferenceMatrix(matrixTemplateDouble1), lenght);
	cout << endl;
	matrixTemplateDouble0.Show();
	cout << endl;
	matrixTemplateDouble1.Show();
	cout << endl;
	matrixTemplateDouble2.Show();
}
//Labs end