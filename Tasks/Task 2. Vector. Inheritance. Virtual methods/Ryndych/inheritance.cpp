
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include "ShapeProc.h"
using namespace std;

Rectangle ::Rectangle(float inX, float inY) {
	this->x = inX;
	this->y = inY;
}
float Rectangle::getSquare() {
	return x*y;
}
string Rectangle::getType() {
	return "Rectangle";
}


Circle  ::Circle(float inR) {
	this->r = inR;
}
float Circle::getSquare() {
	return pi314*r*r;
}
string getTypr() {
	return "Circle";
}


Square::Square(float inA) {
	this->a = inA;
}
float Square::getSquare() {
	return a*a;
}
string Square::getType() {
	return "Square";
}


void ShapeProcessor::push(Shape shape) {
	this->arrayShapes.push_back(shape);
}
float ShapeProcessor::getAllSquare() {
	if (arrayShapes.empty()) {
		return 0;
	}
	int res=0;
	for each  (Shape x in arrayShapes) {
		res += x.getSquare();
	}
	return res;
}
float ShapeProcessor::maxSquare() {
	int res = 0;
	for each  (Shape x in arrayShapes) {
		res = res > x.getSquare() ? res : x.getSquare();
	}
	return res;
}
float ShapeProcessor::minSquare() {
	int res = 0;
	for each  (Shape x in arrayShapes) {
		res = res < x.getSquare() ? res : x.getSquare();
	}
	return res;
}
int ShapeProcessor::sameSquare() {
	int res = -1;
	for (int i = 0; i < arrayShapes.size(); i++) {
		int temp = 0;
		for (int j = i + 1; j < arrayShapes.size(); i++)
			if (arrayShapes[i].getSquare() == arrayShapes[j].getSquare())
				temp++;
		res = res > temp ? res : temp;
	}
	return res;
}
vector<ShapeProcessor> ShapeProcessor::sameSquareShapes() {
	vector<ShapeProcessor> res;
	bool SameSameButDifferent = true;
	for (int i = 0; i < arrayShapes.size(); i++) {
		int temp = 0;
		for (int j = i + 1; j < arrayShapes.size(); i++) {
			SameSameButDifferent = (
				arrayShapes[i].getSquare() == arrayShapes[j].getSquare() &&
				arrayShapes[i].getType() != arrayShapes[j].getType());
			if (SameSameButDifferent) {
				ShapeProcessor temp;
				temp.push(arrayShapes[i]);
				temp.push(arrayShapes[j]);
				for (int k = j; k < arrayShapes.size(); k++) {
					bool differentType =
						arrayShapes[i].getType() != arrayShapes[k].getType() &&
						arrayShapes[j].getType() != arrayShapes[k].getType();
					if (differentType) {
						temp.push(arrayShapes[k]);
						k = arrayShapes.size();
					}
				}
				res.push_back(temp);
			}
		}
	}
	return res;
}

