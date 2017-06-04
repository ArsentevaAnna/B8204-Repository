#pragma once
#include <string.h>
#include <vector>
using namespace std;
const float pi314 = 3.14;
class Shape {
public:
	virtual float getSquare();
	virtual string getType();
};
class Rectangle : public Shape {
	float x;
	float y;
public:
	Rectangle(float inX, float inY);
	float getSquare();
	string getType();
};
class Circle : public Shape {
	float r;
public:
	Circle(float inR);
	float getSquare();
	string getType();
};
class Square : public Shape {
	float a;
public:
	Square(float inA);
	float getSquare();
	string getType();
};
class ShapeProcessor {
	vector<Shape> arrayShapes;
public:
	void push(Shape shape);
	float getAllSquare();
	float maxSquare();
	float minSquare();
	int sameSquare();
	vector<ShapeProcessor> sameSquareShapes();
};