#include "stdafx.h"
#include "Header.h"
#include <iterator>
using namespace std;

double Shape::getSquare() { return 0; }

Circle::Circle(double _R) {
	R = _R;
	type = 'C';
};

double Circle::getSquare() { return 3.14*R*R; };

Rectangle::Rectangle(double _length, double _width) {
	length = _length;
	width = _width;
	type = 'R';
};

double Rectangle::getSquare() { return length*width; };

Square::Square(double _side) {
	side = _side;
	type = 'S';
};

double Square::getSquare() { return side*side; };

void ShapesProcessor::push(Shape& _v) { v.push_back(&_v); };

Shape* ShapesProcessor::maxSquare() {
	Shape* res = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getSquare() > res->getSquare()) { res = v[i]; }
	}
	return res;
};

Shape* ShapesProcessor::minSquare() {
	Shape* res = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getSquare() < res->getSquare()) { res = v[i]; }
	}
	return res;
};

double ShapesProcessor::SumSquare() {
	float res = 0;
	for (int i = 0; i < v.size(); i++) {
		res += v[i]->getSquare();
	}
	return res;
}

int ShapesProcessor::SameSquare() {
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

vector <Shape*> ShapesProcessor::EqualSquare() {
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
};