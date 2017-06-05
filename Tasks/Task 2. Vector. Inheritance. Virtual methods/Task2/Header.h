#pragma once
// Task2.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class IShape {
public:
	char type;	//c - Circle, r - retrangle, s - square
	virtual float getSquare();
};

class Rectangle : public IShape {
private:
	int a, b;

public:
	Rectangle(int _a, int _b);

	float getSquare();

};

class Square : public IShape {
private:
	int a;

public:
	Square(int _a);

	float getSquare();

};

class Circle : public IShape {
private:
	int R;

public:
	Circle(int _R);

	float getSquare();

};

class ShapesProcessor {
private:
	vector<IShape*> vec;

public:
	ShapesProcessor(vector<IShape*> v);

	float SumSquares();

	float MaxS();

	float MinS();

	int EqSquares();

	vector<IShape*> EqSquaresVec();
};