#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
public:
	int type;
	virtual float getSquare() = 0;
	virtual void getName() = 0;
};

class Circle : public Shape
{
private:
	float radius;

public:
	Circle(float _radius)
	{
		type = 1;
		radius = _radius;
	}
	float getSquare()
	{
		return (pow(radius, 2)*3.14);
	}
	void getName()
	{
		cout << "���������� " << radius << " ";
	}

};

class Rectangle : public Shape
{
private:
	float length;
	float width;

public:

	Rectangle(float _length, float _width)
	{
		type = 2;
		length = _length;
		width = _width;
	}
	float getSquare()
	{
		return (length*width);
	}
	void getName()
	{
		cout << "������������� " << length << " " << width << " ";
	}
};

class Square : public Shape
{
private:
	float length;

public:
	Square(float _length)
	{
		type = 3;
		length = _length;
	}
	float getSquare()
	{
		return (length*length);
	}
	void getName()
	{
		cout << "������� " << length << " ";
	}

};

class ShapesProcessor
{
private:
	vector <Shape*> vectorShape;

public:
	void Add(Shape& S)
	{
		vectorShape.push_back(&S);
	}

	void Del()
	{
		vectorShape.clear();
	}

	vector<float> getSquare() //����� ��� �������� �������� ���� ����� ������ ������� �����;
	{
		vector<float> result;
		for (unsigned int i = 0; i < vectorShape.size(); i++)
		{
			result.push_back(vectorShape[i]->getSquare());
		}
		return result;
	}

	Shape* maxSquare() //����� ��� ������ ������ � ���������� ��������;
	{
		Shape* result = vectorShape[0];
		for (unsigned int i = 0; i < vectorShape.size(); i++)
		{
			if (vectorShape[i]->getSquare() > result->getSquare())
			{
				result = vectorShape[i];
			}
		}
		return result;
	}

	Shape* minSquare() // ����� ��� ������ ������ � ���������� ��������;
	{
		Shape* result = vectorShape[0];
		for (unsigned int i = 0; i < vectorShape.size(); i++)
		{
			if (vectorShape[i]->getSquare() < result->getSquare())
			{
				result = vectorShape[i];
			}
		}
		return result;
	}

	int sameSquare() //����� ��� ������ ����� � ���������� ��������, ���������� ������������ ����� ����� ���������� �������;
	{
		vector<float> Squares = getSquare();
		int result = 0;

		for (unsigned int i = 0; i < Squares.size(); i++)
		{
			int count = 1;
			for (unsigned int j = i + 1; j < Squares.size(); j++)
			{
				if ((Squares[i] == Squares[j]) && (i != j))
				{
					count++;
				}
			}
			if (count > result)  //��������� ������ ������� �����
			{
				result = count;
			}
			if (result == 1)
			{
				result = 0;
			}
		}
		return result;

	}

		//����� ��� ������ ����� � ���������� ��������, �� ������� ����, ���������� ������ �� ���� �����;
	ShapesProcessor sameSquareDifType()
	{
		ShapesProcessor result;
		ShapesProcessor temp;

		vector<float> Squares = getSquare();

		for (unsigned int i = 0; i < Squares.size(); i++) {
			temp.Del();
			for (unsigned int j = 0; j < Squares.size(); j++) {
				if ((Squares[i] == Squares[j]) && ((vectorShape[i]->type != vectorShape[j]->type) || (i == j))) {
					temp.Add(*(vectorShape[j]));
				}
			}
			if (temp.vectorShape.size() > result.vectorShape.size()) {
				result = temp;
			}
		}
		return result;	
}

	void Print()
	{
		for (unsigned int i = 0; i < vectorShape.size(); i++)
		{
			vectorShape[i]->getName();
			cout << endl;
		}

	}

};