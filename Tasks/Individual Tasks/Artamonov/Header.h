#include "stdafx.h"
#include <iostream>
using namespace std;

struct Vector
{
	int increase; // увеличение масс
	int size; // размер масс
	int currentSize;// колич эл.
	unsigned int *v;// указ. на масс
	int startPos;// поз. головы
};

void expansion (int el, Vector& vector);
void  push(int el, Vector& vector);
void constriction (Vector& vector);
int pop(Vector& vector);
void create (Vector& name,int size,int increase);
ostream& operator<<(ostream& cout, Vector& vector);