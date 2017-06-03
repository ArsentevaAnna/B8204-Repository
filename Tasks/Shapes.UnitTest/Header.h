#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Shape {
public:
	char type;
	virtual double getSquare();
};

class Circle : public Shape {
private:
	double R;
public:
	Circle(double _R);

	double getSquare();

};

class Rectangle : public Shape {
private:
	double length, width;
public:
	Rectangle(double _length, double _width);

	double getSquare();

};

class Square : public Shape {
private:
	double side;
public:
	Square(double _side);

	double getSquare();

};

class ShapesProcessor {
private:
	vector<Shape*> v;
public:
	void push(Shape& _v);

	Shape* maxSquare();

	Shape* minSquare();

	double SumSquare();

	int SameSquare();

	vector <Shape*> EqualSquare();
};