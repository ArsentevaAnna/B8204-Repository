
#include "stdafx.h"


#include <vector>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Shape
{
public:
	virtual double getSquare() = 0;
	virtual string getName() = 0;
};

class Circle : public Shape
{
public:
	Circle(double radius)
	{
		if (radius <= 0) {
			radius = 1;
		}		
		this->radius = radius;
	}

	double getSquare()
	{
		return round((3.14 * pow(radius, 2)) * 100) / 100;
	}

	string getName()
	{
		return "Circle";
	}

private:
	double radius;
};

class Rectangle : public Shape
{
public:
	Rectangle(double length, double width)
	{
		if (length <= 0 || width <= 0) {
			lenght = 1;
			width = 1;
		}
		this->lenght = length;
		this->width = width;
	}

	double getSquare()
	{
		return round((lenght * width) * 100) / 100;
	}

	string getName()
	{
		return "Rectangle";
	}

private:
	double lenght;
	double width;
};

class Square : public Shape
{
public:
	Square(double lenght)
	{
		if (lenght <= 0) {
			lenght = 1;
		}			
		this->lenght = lenght;
	}

	double getSquare()
	{
		return round(pow(lenght, 2) * 100) / 100;
	}

	string getName()
	{
		return "Square";
	}

private:
	double lenght;
};


class ShapesProcessor
{
public:
	void push(Shape& figure)
	{
		v.push_back(&figure);
	}

	void clear()
	{
		v.clear();
	}

	vector<double> getSquare()
	{
		vector<double> squaresVector;
		for (unsigned int i = 0; i < v.size(); i++) {
			squaresVector.push_back(v[i]->getSquare());
		}
		return squaresVector;
	}

	Shape* maxSquare()
	{
		Shape* max = v[0];
		for (unsigned int i = 0; i < v.size(); i++) {
			if (v[i]->getSquare() > max->getSquare()) {
				max = v[i];
			}
		}
		return max;
	}

	Shape* minSquare()
	{
		Shape* min = v[0];
		for (unsigned int i = 0; i < v.size(); i++) {
			if (v[i]->getSquare() < min->getSquare()) {
				min = v[i];
			}
		}
		return min;
	}

	unsigned int sameSquare()
	{
		vector<double> Squares = getSquare();
		int max = 0;
		for (unsigned int i = 0; i < Squares.size(); i++) {
			int count = 0;
			for (unsigned int j = 0; j < Squares.size(); j++) {
				if ((Squares[i] == Squares[j]) && (i != j)) {
					count++;
				}
			}
			if (count > max) {
				max = count;
			}
		}
		return max;
	}

	ShapesProcessor sameSquareDiffType()
	{
		ShapesProcessor result;
		ShapesProcessor temp;

		vector<double> Squares = getSquare();
		for (unsigned int i = 0; i < Squares.size(); i++) {
			temp.clear();
			for (unsigned int j = 0; j < Squares.size(); j++) {
				if ((Squares[i] == Squares[j]) && ((v[i]->getName() != v[j]->getName()) || (i == j))) {
					temp.push(*(v[j]));
				}
			}
			if (temp.v.size() > result.v.size()) {
				result = temp;
			}
		}
		return result;
	}

public:
	vector<Shape*> v;
};

	ostream&  operator << (ostream& os, ShapesProcessor el)
	{
		for (unsigned int i = 0; i < el.v.size(); i++) {
			cout << el.v[i]->getName() << ": " << el.v[i]->getSquare() << ' ';
		}
		cout << endl;
		return os;
	}

int main()
{
	setlocale(LC_ALL, "Russian");

	Square s1(1.234);
	Rectangle r1(3, 7);
	Circle c1(1);
	Circle c2(3);

	ShapesProcessor Shapes;
	Shapes.push(s1);
	Shapes.push(r1);
	Shapes.push(c1);
	Shapes.push(c2);
	cout << Shapes;

	cout << "MinSquare " << Shapes.minSquare()->getName() << " " << Shapes.minSquare()->getSquare() << endl;
	cout << "MaxSquare " << Shapes.maxSquare()->getName() << " " << Shapes.maxSquare()->getSquare() << endl;


	system("pause");
	return 0;
}


