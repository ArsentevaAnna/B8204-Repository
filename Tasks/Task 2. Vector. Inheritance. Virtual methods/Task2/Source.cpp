// Task2.cpp: определяет точку входа для консольного приложения.


#include "stdafx.h"
#include "Header.h"
#include <iostream>

using namespace std;

float IShape::getSquare() {
	return(0);
};

Rectangle::Rectangle(int _a, int _b) {
	type = 'r';
	a = _a;
	b = _b;
};

float Rectangle::getSquare() {
	return a * b;
};

Square::Square(int _a) {
	type = 's';
	a = _a;
};

float Square::getSquare() {
	return a * a;
};

Circle::Circle(int _R) {
	type = 'c';
	R = _R;
};

float  Circle::getSquare() {
	return 3.14 * R * R;
};


ShapesProcessor::ShapesProcessor(vector<IShape*> v) {
	vec = v;
};

float ShapesProcessor::SumSquares() {
	float res = 0;
	for (int i = 0; i < vec.size(); i++) {
		res += vec[i]->getSquare();
	}
	return(res);
}

float ShapesProcessor::MaxS() {
	float res = vec[0]->getSquare();
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i]->getSquare() < vec[i + 1]->getSquare()) {
			res = vec[i + 1]->getSquare();
		}
	}
	return(res);
}

/*float MaxS2() {
max_element(vec.begin()->getSquare(), vec.end()->getSquare()) - vec.begin()->getSquare();
}*/

float ShapesProcessor::MinS() {
	float res = vec[0]->getSquare();
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i]->getSquare() > vec[i + 1]->getSquare()) {
			res = vec[i + 1]->getSquare();
		}
	}
	return(res);
}

int ShapesProcessor::EqSquares() {
	map <float, int> SquaresMap;
	SquaresMap.insert(pair<float, int>(vec[0]->getSquare(), 1));
	for (int i = 1; i < vec.size(); i++) {

		map<float, int>::iterator  it = SquaresMap.find(vec[i]->getSquare());
		if (it != SquaresMap.end()) {
			SquaresMap[vec[i]->getSquare()]++;
		}
		else {
			SquaresMap.insert(pair<float, int>(vec[i]->getSquare(), 1));
		}
	}
	int res = 1;
	for (auto it = SquaresMap.begin(); it != SquaresMap.end(); ++it) {
		if (it->second > res) {
			res = it->second;
		}
	}
	return(res);
}

vector<IShape*> ShapesProcessor::EqSquaresVec() {

	vector<IShape*> res;
	res.clear();

	if (EqSquares() == 1) return(res);

	vector<IShape*> temp;
	char types[3] = "";

	for (int i = 0; i < vec.size(); i++) {
		temp.clear();
		temp.push_back(vec[i]);
		types[0] = vec[i]->type;
		int typesCount = 0;
		for (int j = i + 1; j < vec.size(); j++) {
			if ((vec[i]->getSquare() == vec[j]->getSquare()) && (strchr(types, vec[j]->type) == 0)) {
				temp.push_back(vec[j]);
				typesCount++;
				types[typesCount] = vec[j]->type;
			}

		}
		if (temp.size() > res.size()) {
			res = temp;
		}
	}
	return(res);
}
