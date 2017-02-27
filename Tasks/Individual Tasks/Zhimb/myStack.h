#pragma once
struct stek
{
	int value;
	struct stek *next; // указатель на следующий элемент списка (стека)
};

void push(stek* &NEXT, const int VALUE);
int pop(stek* &NEXT);
int Size(stek* NEXT);