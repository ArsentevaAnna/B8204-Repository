
#include "stdafx.h"
#include"myStack.h"
#include <fstream>
#include <iostream>
using namespace std;

void push(stek* &NEXT, const int VALUE)
{
    stek *MyStack = new stek; // объявляем новую динамическую переменную типа stek
    MyStack->value = VALUE; // записываем значение, которое помещается в стек
    MyStack->next = NEXT; // связываем новый элемент стека с предыдущим
    NEXT = MyStack; // новый элемент стека становится его вершиной
}

int pop(stek* &NEXT)
{
    int temp = NEXT->value; // извлекаем в переменную temp значение в вершине стека
    stek *MyStack = NEXT; // запоминаем указатель на вершину стека, чтобы затем
    // освободить выделенную под него память
    NEXT = NEXT->next; // вершиной становится предшествующий top элемент
    delete MyStack; // освобождаем память, тем самым удалили вершину
    return temp; // возвращаем значение, которое было в вершине
}

int Size(stek* NEXT)
{
    int temp = 0; 
	
while (NEXT!=NULL)
    { 
		temp ++;
		NEXT = NEXT->next;
    };
    return temp; 
}

void Write(stek* NEXT)
{
	while (NEXT!=NULL)
    { 
      cout <<NEXT->value<<' ';  
      NEXT = NEXT->next; 
	}
	cout<<endl;
}