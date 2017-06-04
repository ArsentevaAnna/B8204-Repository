#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Shape
{
public:

	char type;

	virtual float getSquare() = 0;
	virtual void print() = 0;
};

class Rectangle : public Shape
{
private:

	float width;
	float length;

public:

	Rectangle(float width, float length)
	{
		type = 'r';
		this->width = width;
		this->length = length;
	}

	float getSquare()
	{
		return length * width;
	}

	void print()
	{
		cout << "Rectangle " << "[length = " << length << "] [width = " << width << "]" << endl;
	}

};

class Circle : public Shape
{
private:

	float radius;

public:

	Circle(float radius)
	{
		type = 'c';
		this->radius = radius;
	}

	float getSquare()
	{
		return 3.14 * radius * radius;
	}

	void print()
	{
		cout << "Circle " << "[radius = " << radius << "]" << endl;
	}

};

class Square : public Shape
{
private:

	float side;

public:

	Square(float side)
	{
		type = 's';
		this->side = side;
	}

	float getSquare()
	{
		return side * side;
	}

	void print()
	{
		cout << "Square " << "[side = " << side << "]" << endl;
	}

};

class ShapesProcessor
{
private:

	vector <Shape*> vectorOfShapes;

	bool findType(char _type)
	{
		for (auto i = vectorOfShapes.begin(), end = vectorOfShapes.end(); i != end; i++)
		{
			if ((*i)->type == _type) return true;
		}
		return false;
	}

public:

	void addShape(Shape &obj)
	{
		vectorOfShapes.push_back(&obj);
	}

	void clearVec()
	{
		vectorOfShapes.clear();
	}

	Shape* getMaxSquare()
	{
		auto lambda = [](Shape *first, Shape *second) { return first->getSquare() < second->getSquare(); };

		vector<Shape*>::iterator result;

		result = max_element(vectorOfShapes.begin(), vectorOfShapes.end(), lambda);

		return vectorOfShapes[distance(vectorOfShapes.begin(), result)];
	}

	Shape* getMinSquare()
	{
		auto lambda = [](Shape *first, Shape *second) { return first->getSquare() < second->getSquare(); };

		vector<Shape*>::iterator result;

		result = min_element(vectorOfShapes.begin(), vectorOfShapes.end(), lambda);

		return vectorOfShapes[distance(vectorOfShapes.begin(), result)];
	}

	vector <float> getSquareAllShapes()
	{
		vector <float> output;

		for (auto i : vectorOfShapes)
		{
			output.push_back(i->getSquare());
		}

		return output;
	}

	int getSameSquare()
	{
		int maxCount = 0, iterCount = 0;
		vector<float> Squares = this->getSquareAllShapes();

		for (auto i : Squares)
		{
			iterCount = count(Squares.begin(), Squares.end(), i);
			if (maxCount < iterCount) { maxCount = iterCount; }
		}

		return maxCount;
	}

	void print()
	{
		for (auto i : vectorOfShapes) i->print();
	}

	ShapesProcessor getSameSquareType()
	{
		ShapesProcessor res, tmp;
		
		vector<float> Squares = this->getSquareAllShapes();

		for (auto i = vectorOfShapes.begin(), end = vectorOfShapes.end(); i != end; i++)
		{
			tmp.clearVec();

			for (auto j = vectorOfShapes.begin(), t = i + 1; j != t; j++)
			{
				if (Squares[i - vectorOfShapes.begin()] == Squares[j - vectorOfShapes.begin()] && !(tmp.findType((*j)->type)))
				{
					tmp.addShape(**j);
				}
			}

			if (tmp.vectorOfShapes.size() > res.vectorOfShapes.size() && tmp.vectorOfShapes.size() > 1) res = tmp;
		}

		return res;
	}

};