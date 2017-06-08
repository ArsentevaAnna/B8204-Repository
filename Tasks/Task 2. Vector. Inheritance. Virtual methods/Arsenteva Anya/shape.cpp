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
		cout << "Окружность " << radius << " ";
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
		cout << "Прямоугольник " << length << " " << width << " ";
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
		cout << "Квадрат " << length << " ";
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

	vector<float> getSquare() //Метод для подсчёта площадей всех фигур внутри вектора фигур;
	{
		vector<float> result;
		for (unsigned int i = 0; i < vectorShape.size(); i++)
		{
			result.push_back(vectorShape[i]->getSquare());
		}
		return result;
	}

	Shape* maxSquare() //Метод для поиска фигуры с наибольшей площадью;
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

	Shape* minSquare() // Метод для поиска фигуры с наименьшей площадью;
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

	int sameSquare() //Метод для поиска фигур с одинаковой площадью, возвращает максимальное число фигур одинаковой площади;
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
			if (count > result)  //получился вектор большей длины
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

		//Метод для поиска фигур с одинаковой площадью, но разного типа, возвращает вектор из этих фигур;
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