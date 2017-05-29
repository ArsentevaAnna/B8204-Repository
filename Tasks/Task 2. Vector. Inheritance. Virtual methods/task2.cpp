// Task2.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class IShape {
public:
	char type;	//c - circule, r - retrangle, s - square
	virtual float getSquare() = 0;
};

class Rectangle : public IShape {
private:
	int a, b;

public:
	Rectangle(int _a, int _b) {
		type = 'r';
		a = _a;
		b = _b;
	}

	float getSquare() {
		return a * b;
	}

};

class Square : public IShape {
private:
	int a;

public:
	Square(int _a) {
		type = 's';
		a = _a;
	}

	float getSquare() {
		return a * a;
	}

};

class Circule : public IShape {
private:
	int R;

public:
	Circule(int _R) {
		type = 'c';
		R = _R;
	}

	float getSquare() {
		return 3.14 * R * R;
	}
	
};

class ShapesProcessor {
private:
	vector<IShape*> vec;

public:
	ShapesProcessor(vector<IShape*> v){
		vec = v;
	}

	float SumSquares() {
		float res = 0;		
		for (int i = 0; i < vec.size(); i++) {
			res += vec[i]->getSquare();
		}

		return(res);
	}

	float MaxS() {
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

	float MinS() {
		float res = vec[0]->getSquare();
		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i]->getSquare() > vec[i + 1]->getSquare()) {
				res = vec[i + 1]->getSquare();
			}
		}
		return(res);
	}

	int EqSquares() {
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

	vector<IShape*> EqSquaresVec() {
		
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
};

int main() {
	Square Sq(4);
	Rectangle Rec(3, 5);
	Rectangle Rec2(2, 8);
	Rectangle Rec3(4, 4);
	Circule Cir(2);
	vector<IShape*> v(5);
	v[0] = &Sq;
	v[1] = &Rec;
	v[2] = &Cir;
	v[3] = &Rec2;
	v[4] = &Rec3;
	ShapesProcessor SP(v);
	SP.EqSquaresVec();
	
	system("pause");
    return 0;
}
