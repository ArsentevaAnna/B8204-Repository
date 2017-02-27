#include "stdafx.h"
#include <iostream>
#include "Header.h"
using namespace std;

void expansion (int el, Vector& vector)
{
		unsigned int* newMass = new unsigned int[vector.size+vector.increase];
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
		vector.size += vector.increase;
		delete[] vector.v;
		vector.v = newMass;
		vector.startPos = 0;
}

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
		expansion (el,vector);
	}
}

void constriction (Vector& vector)
{
		unsigned int* newMass = new unsigned int[vector.size-vector.increase];
		if (vector.startPos < 5)
		{
			for (int i = vector.startPos; i < vector.size - vector.increase + vector.startPos; i++)
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
		vector.size -= vector.increase;
		delete[] vector.v;
		vector.v = newMass;
		vector.startPos = 0;
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
		void constriction (Vector& vector);
	}
	return (outEl);
}

void create (Vector& name,int size,int increase)
{
	name.increase = increase;
	name.size = size;
	name.v = new unsigned int[name.size];
	name.startPos = 0;
	name.currentSize = 0;
}

ostream& operator<<(ostream& cout, Vector& vector)
{
	if ((vector.startPos + vector.currentSize) < vector.size)
	{
		for (int i = vector.startPos; i < vector.currentSize + vector.startPos; i++)
		{
		cout << vector.v[i] << ' ';
		}
	}
	else
	{
		for (int i = vector.startPos; i < vector.size; i++)
		{
		cout << vector.v[i] << ' ';
		}

		for (int i = 0; i < vector.size - vector.currentSize - vector.startPos ; i++)
		{
		cout << vector.v[i] << ' ';
		}
	}
	cout << endl;
	return cout;
}
