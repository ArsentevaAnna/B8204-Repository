#include "stdafx.h"
#include "vector.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void init(Vector& a) //инициализация вектора
{
	a.vSize = 5;
	a.currentSize = 0;
	a.v = new unsigned int[a.vSize];
	//for (int i = 0; i < a.vSize; ++i)
	//a.v[i] = 0;
}

void print(Vector& a) //печать вектора
{
	for (int i = 0; i < a.currentSize; i++)
	{
		//if (a.v[i] != NULL)
		cout << a.v[i] << "  ";
	}
	cout << "\n";
}

int insert(Vector& a, int index, int element) //добавление элемента на нужную позицию
{
	int i;
	if (a.currentSize >= a.vSize)
	{
		unsigned int *newMass = new unsigned int[a.vSize + INCREASE_SIZE];
		for (int j = 0; j < a.vSize + INCREASE_SIZE - 1; j++)
			newMass[j] = a.v[j];
		delete a.v;
		a.vSize = a.vSize + INCREASE_SIZE;
		a.v = newMass;
	}
	
	if (a.v[index] == NULL)
	{
		a.v[index] = element;
		a.currentSize++;
	}
	else
	/*	if (a.v[index] != NULL) 
		{
			for (i = a.vSize; i >= index; i--)
			{
				a.v[i] = a.v[i-1];
			}
			a.v[index] = element;
			a.currentSize++;
		}*/
		{
			i = index;
			while (a.v[i] != NULL)
				i--;
			if ((a.v[i] == NULL) || (i > 0))
			{
				for (int j = 0; j < index - i; ++j)
					a.v[i] = a.v[i + j];
				a.v[index] = element;
				a.currentSize++;
			}
			else
			{
				i = a.vSize - 1;
				while ((a.v[i] != NULL) && (i != 0))
					i--;
				for (int j = i; j > index - i; --j)
					a.v[i] = a.v[ i -j];
				a.v[index] = element;
				a.currentSize++;
			}
		}
		return -1;
}

int del(Vector& a, int index) //удаление элемента с нужной позиции
{
	for (int i = index; i < a.vSize; ++i)
		if (a.v[i] != NULL)
		{
			a.v[i] = a.v[i + 1];
			a.v[a.vSize - 1] = NULL;
			a.currentSize--;
			if ((a.currentSize == a.vSize - INCREASE_SIZE) && (a.vSize > 5))
			{
				unsigned int *newMass = new unsigned int[a.vSize - INCREASE_SIZE];
				for (int j = 0; j < a.vSize - INCREASE_SIZE - 1; j++)
				{
					newMass[j] = a.v[j];
					a.v[j] = NULL;
				}
				a.vSize = a.vSize - INCREASE_SIZE;
				delete a.v;
				a.v = newMass;
			}
			return a.v[index];
		}
		return -1;
}

int get(Vector& a, int index) //получение элемента по позиции
{
	int er=-1;
	if (a.v[index] != NULL)
	{
		return a.v[index];
	}
	else
	{
		return er;
	}
}

int length (Vector& a) //возвращение длины заполненного вектора
{
	int l = 0;
	for (int i = 0; i < a.currentSize; i++)
	{
		l=l+1;
	}
	return l;
}