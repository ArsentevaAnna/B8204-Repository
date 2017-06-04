#include "stdafx.h"
#include "Header.h"
#include <iterator>
using namespace std;

double IShape::getSquare() { return 0; }

Circle::Circle(double _R) {
	Rad = _R;
	name = 'C';
};

double Circle::getSquare() { return 3.14*Rad*Rad; };

Rectangle::Rectangle(double _len, double _wid) {
	len = _len;
	wid = _wid;
	name = 'R';
};

double Rectangle::getSquare() { return len*wid; };

Square::Square(double _side) {
	side = _side;
	name = 'S';
};

double Square::getSquare() { return side*side; };

//void ShapesProcessor::push(Shape& _v) { v.push_back(&_v); };

vector<double> ShapesProcessor::getSquare(){
	vector<double> Squares;
	for (unsigned int i = 0; i < vec.size(); i++) {
		Squares.push_back(vec[i]->getSquare());
	}
	return Squares;
}

IShape* ShapesProcessor::maxSquare() {
	IShape* res = vec[0];
	unsigned int l = vec.size();
	for (unsigned int i = 0, l = vec.size(); i < l; i++)
	{
		if (vec[i]->getSquare() > res->getSquare()) { res = vec[i]; }
	}
	return res;
};

IShape* ShapesProcessor::minSquare() {
	IShape* res = vec[0];
	unsigned int l = vec.size();
	for (unsigned int i = 0, l = vec.size(); i < l; i++)
	{
		if (vec[i]->getSquare() < res->getSquare()) { res = vec[i]; }
	}
	return res;
};

double ShapesProcessor::SumSquare() {
	double res = 0;
	unsigned int l = vec.size();
	for (unsigned int i = 0, l = vec.size(); i < l; i++) {
		res += vec[i]->getSquare();
	}
	return res;
}

int ShapesProcessor::IdenSquare() {
	vector<double> Squares = getSquare();

	int res = 0;
	unsigned int l = Squares.size(), l1 = Squares.size();
	for (unsigned int i = 0, l = Squares.size(); i < l; i++)
	{
		int count = 1;
		for (unsigned int j = i + 1, l1 = Squares.size(); j < l; j++)
			if (Squares[i] == Squares[j]) count++;
		if (count > res) res = count;
	}
	return res;
}

void ShapesProcessor::clear(){
	vec.clear();
}

vector <IShape*> ShapesProcessor::EqualSquare() {
	vector<IShape*> res;
	vector<IShape*> temp;
	vector<double> Squares = getSquare();
	int k = 0; double d = 0, d1 = 0;

	for (unsigned int i = 0, l = Squares.size(); i < l; i++)
	{
		int count = 1;
		for (unsigned int j = i + 1, l1 = Squares.size(); j < l; j++)
			if (Squares[i] == Squares[j]) { d1 = Squares[i]; count++; }
		if (count > k) { k = count; d = d1; }
	}
	bool p = true;
	for (unsigned int i = 0, l = Squares.size(); i < l; i++)
	{
		if (Squares[i] == d) {
			for (unsigned int j = 0; j < res.size(); j++) {
				if (vec[i]->name == res[j]->name) {
					p = false;
				}
			}
			if (p = true) res.push_back(vec[i]);
		}
	}
	return res;
};