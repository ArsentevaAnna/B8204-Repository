// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Shape {
public:
	char type;
	virtual double getSquare() {return 0;}
};

class Circle : public Shape {
private:
	double R;
public: 
	Circle(double _R) { 
		R = _R;
		type = 'C';
	}

	double getSquare() { return 3.14*R*R; }

};

class Rectangle : public Shape {
private:
	double length, width;
public:
	Rectangle(double _length, double _width) {
		length = _length;
		width = _width;
		type = 'R';
	}

	double getSquare() { return length*width; }

};

class Square : public Shape {
private:
	double side;
public:
	Square(double _side) { 
		side = _side;
		type = 'S';
	}

	double getSquare() { return side*side; }

};


class ShapesProcessor {
private:
	vector<Shape*> v;
public:
	void push(Shape& _v) { v.push_back(&_v); }

	Shape* maxSquare() {
		Shape* res = v[0];
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i]->getSquare() > res->getSquare()) { res = v[i]; }
		}
		return res;
	}

	Shape* minSquare() {
		Shape* res = v[0];
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i]->getSquare() < res->getSquare()) { res = v[i]; }
		}
		return res;
	}

	float SumSquare() {
		float res = 0;
		for (int i = 0; i < v.size(); i++) {
			res += v[i]->getSquare();
		}
		return res;
	}

	int SameSquare() {
		vector<float> Squares;
		for (int i = 0; i < v.size(); i++)
			Squares.push_back(v[i]->getSquare());

		int res = 0;
		for (int i = 0; i < Squares.size(); i++)
		{
			int count = 1;
			for (int j = i + 1; j < Squares.size(); j++)
				if (Squares[i] == Squares[j]) count++;
			if (count > res) res = count;			
		}
		return res;
	}

	vector <Shape*> EqualSquare() {
		vector <Shape*> res;
		vector <Shape*> temp;

		char types[3] = "";
		
	
			for (int i = 0; i <v.size(); i++)
			{
				temp.clear();
				temp.push_back(v[i]);
				types[0] = v[i]->type;
				int count = 0;
				for (int j = i + 1; j < v.size(); j++)
				{
					if ((v[i]->getSquare() == v[j]->getSquare()) && (strchr(types, v[j]->type) == 0)) {
						temp.push_back(v[j]);
						count++;
						types[count] = v[j]->type;
					}
				}
				if (temp.size() > res.size()) 
					res = temp;
				
			}
			return (res);
	}

};

int main() {
	Square a(2);
	Rectangle b(1, 4);
	Rectangle d(4, 1);
	Circle c(2);
	

	ShapesProcessor Shapes;
	Shapes.push(a);
	Shapes.push(b);
	Shapes.push(c);
	Shapes.push(d);
	cout << Shapes.maxSquare()->getSquare() << endl;
	cout << Shapes.SumSquare() << endl;
	cout << Shapes.SameSquare();

	Shapes.EqualSquare();


	system("pause");
	return 0;
}
