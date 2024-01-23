#include "Labs.h"
#include <math.h>
#include <windows.h>
#include <iostream>
#include <stack>
#include <sstream>

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
Matrix Matrix::operator+(Matrix matrix) {
	return Matrix(matrix.AdditionMatrix(*this),this->_lenght);
};
Matrix Matrix::operator-(Matrix matrix) {
	return Matrix(matrix.DifferenceMatrix(*this), this->_lenght);
};
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

//Vehicle start
class Time {
private:
	int _days;
	int _hours;
	int _minuts;
	int _seconds;
public:
	Time(double seconds) {
		_seconds = (int)seconds % 60;
		_minuts = (int)seconds / 60 % 60;
		_hours = (int)seconds / 3600 % 24;
		_days = (int)seconds / 86400;
	}
	Time(int seconds) {
		_seconds = seconds % 60;
		_minuts = seconds / 60;
		_hours = seconds / 3600;
		_days = seconds / 86400;
	}
	string ToString() {
		if (_seconds == 0 && _minuts == 0 && _hours == 0 && _days == 0) {
			return "";
		}
		if (_minuts == 0 && _hours == 0 && _days == 0) {
			ostringstream  temp;
			temp << " Sec: " << _seconds;
			return temp.str();
		}
		if (_hours == 0 && _days == 0) {
			ostringstream  temp;
			temp << "Min: " << _minuts << " Sec: " << _seconds;
			return temp.str();
		}
		if (_days == 0) {
			ostringstream  temp;
			temp << "Hours: " << _hours<< " Min: " << _minuts << " Sec: " << _seconds;
			return temp.str();
		}
		ostringstream  temp;
		temp << "Days: " << _days << " Hours: " << _hours << " Min: " << _minuts << " Sec: " << _seconds;
		return temp.str();

	}
};
class Vehicle {
protected:
	double _speed;
	int _people;
	double _weight;
	double _cost;
	string _name;
public:
	Vehicle(double speed, int people, double weight, double cost, string name) {
		_speed = speed;
		_people = people;
		_weight = weight;
		_cost = cost;
		_name = name;
	}
	double GetSpeed() {
		return _speed;
	}
	int GetPeople() {
		return _people;
	}
	virtual void Travel(double distance, int people) {};
	virtual void Travel(double distance, double weight) {};
};
class Car :public Vehicle {
public:
	Car(double speed, int people, double weight, double cost, string name) : Vehicle{ speed,people,weight,cost,name } {}
	void Travel(double distance, int people) override {
		int counter = 0;
		for (int i = people; i > 0; i -= _people) {
			counter++;
		}
		Time time = Time((distance / _speed) * counter * 3600);
		double cost = (_cost * distance * counter) / 2000;
		cout << _name << " = " << "Time: " << time.ToString() << " || " << "Cost: " << cost << " $" << endl;
	}
	void Travel(double distance, double weight) override {
		int counter = 0;
		for (double i = weight; i > 0; i -= _weight) {
			counter++;
		}
		Time time = Time((distance / _speed) * counter * 3600);
		double cost = (_cost * distance * counter) / 2000;
		cout << _name << " = " << "Time: " << time.ToString() << " || " << "Cost: " << cost << " $" << endl;
	}
};
class Carriage :public Vehicle {
public:
	Carriage(double speed, int people, double weight, double cost, string name) : Vehicle{ speed,people,weight,cost,name } {}
	void Travel(double distance, int people) override {
		int counter = 0;
		for (int i = people; i > 0; i -= _people) {
			counter++;
		}
		Time time = Time((distance / _speed) * counter * 3600);
		double cost = (_cost * distance * counter) / 2000;
		cout << _name << " = " << "Time: " << time.ToString() << " || " << "Cost: " << cost << " $" << endl;
	}
	void Travel(double distance, double weight) override {
		int counter = 0;
		for (double i = weight; i > 0; i -= _weight) {
			counter++;
		}
		Time time = Time((distance / _speed) * counter * 3600);
		double cost = (_cost * distance * counter) / 2000;
		cout << _name << " = " << "Time: " << time.ToString() << " || " << "Cost: " << cost << " $" << endl;
	}
};
class Bicycle :public Vehicle {
public:
	Bicycle(double speed, int people, double weight, double cost, string name) : Vehicle{ speed,people,weight,cost,name } {}
	void Travel(double distance, int people) override {
		int counter = 0;
		for (int i = people; i > 0; i -= _people) {
			counter++;
		}
		Time time = Time((distance / _speed) * counter * 3600);
		double cost = (_cost * distance * counter) / 2000;
		cout << _name << " = " << "Time: " << time.ToString() << " || " << "Cost: " << cost << " $" << endl;
	}
	void Travel(double distance, double weight) override {
		int counter = 0;
		for (double i = weight; i > 0; i -= _weight) {
			counter++;
		}
		Time time = Time((distance / _speed) * counter * 3600);
		double cost = (_cost * distance * counter) / 2000;
		cout << _name << " = " << "Time: " << time.ToString() << " || " << "Cost: " << cost << " $" << endl;
	}
};
void WriteWay(int people, int distance) {
	Car lightCar = Car(120, 4, 300, 1,"Light Car");
	Car heavyCar = Car(90, 3, 8000, 3, "Heavy Car");
	Car busCar = Car(70, 30, 50, 2.5, "Bus");
	Bicycle smallBicycle = Bicycle(10, 2, 5, 0.01, "Small Bicycle");
	Bicycle smartBicycle = Bicycle(20, 1, 3, 0.01, "Smart Bicycle");
	Bicycle mountainBicycle = Bicycle(15, 1, 10, 0.01 , "Mountain Bicycle");
	Carriage carriage = Carriage(15, 20, 500, 0.25, "Carriage");

	cout << "Distance '"<< distance << "', people '"<< people <<"':" << endl;
	lightCar.Travel(distance, (int)people);
	heavyCar.Travel(distance, (int)people);
	busCar.Travel(distance, (int)people);
	smallBicycle.Travel(distance, (int)people);
	smartBicycle.Travel(distance, (int)people);
	mountainBicycle.Travel(distance, (int)people);
	carriage.Travel(distance, (int)people);
	cout << endl;

}
void WriteWay(double weight, int distance) {
	Car lightCar = Car(120, 4, 300, 1, "Light Car");
	Car heavyCar = Car(90, 3, 8000, 3, "Heavy Car");
	Car busCar = Car(70, 30, 50, 2.5, "Bus");
	Bicycle smallBicycle = Bicycle(10, 2, 5, 0.01, "Small Bicycle");
	Bicycle smartBicycle = Bicycle(20, 1, 3, 0.01, "Smart Bicycle");
	Bicycle mountainBicycle = Bicycle(15, 1, 10, 0.01, "Mountain Bicycle");
	Carriage carriage = Carriage(15, 20, 500, 0.25, "Carriage");

	cout << "Distance '" << distance << "', weight '" << weight << "':" << endl;
	lightCar.Travel(distance, weight);
	heavyCar.Travel(distance, weight);
	busCar.Travel(distance, weight);
	smallBicycle.Travel(distance, weight);
	smartBicycle.Travel(distance, weight);
	mountainBicycle.Travel(distance, weight);
	carriage.Travel(distance, weight);
	cout << endl;
}
//Vehicle end

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

//Point start
class CPoint {
protected:
	double _x;
	double _y;
public:
	CPoint(double x = 0, double y = 0) {
		_x = x;
		_y = y;
	}
	void SetX(double x) {
		_x = x;
	}
	void SetY(double y) {
		_y = y;
	}
	void SetPoint(CPoint point) {
		*this = point;
	}
	double GetX() {
		return _x;
	}
	double GetY() {
		return _y;
	}
	CPoint GetPoint() {
		return *this;
	}
};
class CcoloredPoint : public CPoint {
protected:
	string _color;
public:
	CcoloredPoint(double x = 0, double y = 0, string color = "black") {
		_x = x;
		_y = y;
		_color = color;
	}
	string GetColor() {
		return _color;
	}
	void SetColor(string color) {
		_color = color;
	}
}; 
class CLine : public CPoint{
protected:
	CPoint _firstPoint;
	CPoint _secondPoint;
public:
	CLine(CPoint first = CPoint(),CPoint second = CPoint()) {
		_x = (first.GetX() + second.GetX()) / 2;
		_y = (first.GetX() + second.GetX()) / 2;
		_firstPoint = first;
		_secondPoint = second;
	}
	CPoint GetFirstPoint() {
		return _firstPoint;
	}
	CPoint GetSecondPoint() {
		return _secondPoint;
	}
	void SetFirstPoint(CPoint point) {
		_firstPoint = point;
	}
	void SetSecondPoint(CPoint point) {
		_secondPoint = point;
	}
};
class CcoloredLine : public CLine {
protected:
	string _color;
public:
	CcoloredLine(CPoint first = CPoint(), CPoint second = CPoint(), string color = "black") {
		_x = (first.GetX() + second.GetX()) / 2;
		_y = (first.GetX() + second.GetX()) / 2;
		_firstPoint = first;
		_secondPoint = second;
		_color = color;
	}
	string GetColor() {
		return _color;
	}
	void SetColor(string color) {
		_color = color;
	}
};
//Point end

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
	Matrix matrix = Matrix(4);
	Matrix matrix2 = Matrix(4);
	Matrix matrix3 = Matrix(matrix + matrix2);
	matrix.Show();
	cout << '+' << endl;
	matrix2.Show();
	cout << '=' << endl;
	matrix3.Show();
}
void Labs::Thirdy() {
	QuotesTest("{test(a) = test[b}");
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
void Labs::Fifth() {
	WriteWay((int) 25, 50);
	WriteWay((int) 100, 500);
	WriteWay((double)1000, 100);
	WriteWay((double)20000, 500);
}
void Labs::Sixth() {
	CPoint firstPoint = CPoint(5,1);
	CPoint secondPoint = CPoint(2,7);
	cout << "First Point X: " << firstPoint.GetX() << " Y: " << firstPoint.GetY() << endl;
	cout << "Second Point X: " << secondPoint.GetX() << " Y: " << secondPoint.GetY() << endl;
	CcoloredPoint firstColoredPoint = CcoloredPoint(7,3,"yellow");
	CcoloredPoint secondColoredPoint = CcoloredPoint(7, 3, "red");
	cout << "First Colored Point X: " << firstColoredPoint.GetX() << " Y: " << firstColoredPoint.GetY() << " Color: " << firstColoredPoint.GetColor() << endl;
	cout << "Second Colored X: " << secondColoredPoint.GetX() << " Y: " << secondColoredPoint.GetY() << " Color: " << firstColoredPoint.GetColor() << endl;
	CLine line = CLine(firstPoint,secondPoint);
	cout << "Line: " << endl;
	cout << "First Line Point X: " << line.GetFirstPoint().GetX() << " Y: " << line.GetFirstPoint().GetY() << endl;
	cout << "Second Line Point X: " << line.GetSecondPoint().GetX() << " Y: " << line.GetSecondPoint().GetY() << endl;
	CcoloredLine coloredLine = CcoloredLine(CPoint(8,1),CPoint(15,-5),"green");
	cout << "Colored Line: " << endl;
	cout << "First Line Point X: " << coloredLine.GetFirstPoint().GetX() << " Y: " << coloredLine.GetFirstPoint().GetY() << endl;
	cout << "Second Line Point X: " << coloredLine.GetSecondPoint().GetX() << " Y: " << coloredLine.GetSecondPoint().GetY() << endl;
	cout << "Color: " << coloredLine.GetColor() << endl;
}
//Labs end