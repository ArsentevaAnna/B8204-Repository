#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:

	int type;

	virtual float getSquare() = 0;
	virtual void printFunc() = 0;
};

class Rectangle : public Shape
{
private:

	float dlina;
	float shirina;

public:

	Rectangle(float _dlina, float _shirina)
	{
		type = 1;
		dlina = _dlina;
		shirina = _shirina;
	}

	float getSquare()
	{
		float result = dlina * shirina;
		return result;
	}

	void printFunc()
	{
		cout << "Rectangle " << dlina << " " << shirina << endl;
	}
};

class Circle : public Shape
{
private:

	float radius;

public:

	Circle(float _radius)
	{
		type = 2;
		radius = _radius;
	}

	float getSquare()
	{
		float result = 3.14 * radius * radius;
		return result;
	}

	void printFunc()
	{
		cout << "Circle " << radius << endl;
	}
};

class Square : public Shape
{
private:

	float storona;

public:

	Square(float _storona)
	{
		type = 3;
		storona = _storona;
	}

	float getSquare()
	{
		float result = storona * storona;
		return result;
	}

	void printFunc()
	{
		cout << "Square " << storona << endl;
	}
};

class ShapesProcessor
{
private:

	vector<Shape*> vect;

	bool typeContains(int _type)
	{
		for (int i = 0; i < vect.size(); i++)
		{
			if (vect[i]->type == _type) return true;
		}
		return false;
	}

public:

	void add(Shape& S)
	{
		vect.push_back(&S);
	}

	void clear()
	{
		vect.clear();
	}
	//TASK 2.a
	vector<float> getSquare()
	{
		vector<float> result;
		for (int i = 0; i < vect.size(); i++)
		{
			result.push_back(vect[i]->getSquare());
		}
		return result;
	}
	//TASK 2.b
	Shape* maxSquare()
	{
		Shape* result = vect[0];
		for (int i = 0; i < vect.size(); i++)
		{
			if (vect[i]->getSquare() > result->getSquare())
			{
				result = vect[i];
			}
		}
		return result;
	}
	//TASK 2.c
	Shape* minSquare()
	{
		Shape* result = vect[0];
		for (int i = 0; i < vect.size(); i++)
		{
			if (vect[i]->getSquare() < result->getSquare())
			{
				result = vect[i];
			}
		}
		return result;
	}
	//TASK 2.d
	int sameSquare()
	{
		vector<float> Squares = this->getSquare();
		int result = 0;
		for (int i = 0; i < Squares.size(); i++)
		{
			int count = 0;
			for (int j = i; j < Squares.size(); j++)
			{
				if ((Squares[i] == Squares[j]) && (i != j))
				{
					count++;
				}
			}
			if (count > result)
			{
				result = count;
			}
		}
		return result + 1;
	}
	//TASK 2.e
	ShapesProcessor* sameSquareType()
	{
		ShapesProcessor* result = new ShapesProcessor;
		ShapesProcessor* temp = new ShapesProcessor;

		vector<float> Squares = this->getSquare();
		for (int i = 0; i < Squares.size(); i++)
		{
			temp->clear();
			for (int j = i; j < Squares.size(); j++)
			{
				if ((Squares[i] == Squares[j]) && (temp->typeContains(vect[j]->type) == false))
				{
					temp->add(*(vect[j]));
				}
			}
			if (temp->vect.size() > result->vect.size())
			{
				result->clear();
				for (int k = 0; k < temp->vect.size(); k++)
					result->add(*(temp->vect[k]));
			}
		}
		return result;
	}

	void print()
	{
		for (int i = 0; i < vect.size(); i++)
		{
			vect[i]->printFunc();
		}
	}
};