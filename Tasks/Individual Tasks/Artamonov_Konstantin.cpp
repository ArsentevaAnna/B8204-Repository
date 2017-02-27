// SAKOD.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Vector
{
	int size; // размер масс
	int currentSize;// колич эл.
	unsigned int *v;// указ. на масс
	int startPos;// поз. головы
};

void  push(int el, Vector& vector)// функция добавления эл.

{
	if (vector.currentSize < vector.size)
	{
		if (vector.startPos + vector.currentSize < vector.size)
		{
			vector.v[vector.startPos + vector.currentSize] = el;
			vector.currentSize++;
		}
		else
		{
			vector.v[vector.startPos + vector.currentSize - vector.size] = el;
			vector.currentSize++;
		}
	}
	else  // увеличить размер массива с добавлением эл.
	{	
		expansion(el, vector);
	}

}

int pop(Vector& vector) // функция возвращающая эл.
{
	unsigned int outEl = -1;
	if (vector.currentSize == 0)
	{
		return(-1);
	}
	else
	{
		outEl = vector.v[vector.startPos];
		if (vector.startPos == vector.size - 1)
		{
			vector.startPos == 0;
			vector.currentSize--;
		}
		else
		{
			vector.startPos++;
			vector.currentSize--;
		}
	}

	if ((vector.currentSize == vector.size - 5) && (vector.size > 5)) // Уменьшение массива
	{		
		constriction(vector);
	}
	return (outEl);
}

void expansion(int el, Vector& vector)
{
	unsigned int* newMass = new unsigned int[vector.size + 5];
	for (int i = vector.startPos; i < vector.size; i++)
	{
		newMass[i - vector.startPos] = vector.v[i];
	}
	for (int i = 0; i < vector.startPos; i++)
	{
		newMass[vector.size - vector.startPos - 1 + i] = vector.v[i];
	}
	vector.currentSize++;
	newMass[vector.currentSize - 1] = el;
	vector.size += 5;
	delete[] vector.v;
	vector.v = new unsigned int[vector.size];
	memcpy(vector.v, newMass, sizeof(unsigned int)*vector.size);
	delete[] newMass;
	vector.startPos = 0;
}

void constriction(Vector& vector)
{
	unsigned int* newMass = new unsigned int[vector.size - 5];
	if (vector.startPos < 5)
	{
		for (int i = vector.startPos; i < vector.size - 5 + vector.startPos; i++)
		{
			newMass[i - vector.startPos] = vector.v[i];
		}
	}
	else
	{
		for (int i = vector.startPos; i < vector.size; i++)
		{
			newMass[i - vector.startPos] = vector.v[i];
		}
		for (int i = 0; i < vector.startPos - 5; i++)
		{
			newMass[vector.size - vector.startPos - 1 + i] = vector.v[i];
		}
	}
	vector.size -= 5;
	delete[] vector.v;
	vector.v = new unsigned int[vector.size];
	memcpy(vector.v, newMass, sizeof(unsigned int)*vector.size);
	delete[] newMass;
	vector.startPos = 0;
}

int main() //Очередь
{
	setlocale(LC_ALL, "Russian");

	Vector vector;

	vector.size = 2;
	vector.v = new unsigned int[vector.size];
	int i;
	vector.startPos = 0;
	vector.currentSize = 0;

	push(1, vector);
	push(2, vector);
	push(3, vector);
	cout << pop(vector) <<endl;
	cout << pop(vector) << endl;
	cout << pop(vector) << endl;
	cout << pop(vector) <<endl;

	delete[]vector.v;
	system("pause");
	return 0;
}