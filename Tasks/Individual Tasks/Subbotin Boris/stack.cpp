#include "stdafx.h"
#include "header.h"

using namespace std;

Stack::Stack(int capacity)
{
	this->capacity = new int(capacity);
	this->head = new unsigned int((capacity - 1) / 2);
	this->size = new int(0);
	this->V = new unsigned int[capacity];
}

Stack::~Stack()
{
	delete this->capacity;
	delete this->head;
	delete this->size;
	delete[] this->V;
}

int Stack::getCapacity() const
{
	return *this->capacity;
}

int Stack::getSize() const
{
	return *this->size;
}

int Stack::getHead() const
{
	return *this->head;
}

bool Stack::isEmpty() const
{
	return this->getSize() == 0 ? true : false;
}

int Stack::getIndex(int i) const
{
	return (this->getHead() + i) % this->getCapacity();
}

void Stack::setSize(int n)
{
	*this->size = n;
}

void Stack::setHead(int n)
{
	*this->head = n;
}

void Stack::setCapacity(int n)
{
	*this->capacity = n;
}

bool Stack::isFull() const
{
	return this->getSize() == this->getCapacity() ? true : false;
}

void Stack::circularShiftRight()
{
	int tmp = this->V[this->getIndex(-1)];
	for (int i = this->getCapacity() - 2; i >= 0; i--)
		this->V[this->getIndex(i + 1)] = this->V[this->getIndex(i)];
	this->V[this->getIndex()] = tmp;
}

void Stack::circularShiftLeft()
{
	int tmp = this->V[this->getIndex(this->getCapacity())];
	for (int i = 0; i < this->getCapacity() - 1; i++)
		this->V[this->getIndex(i)] = this->V[this->getIndex(i + 1)];
	this->V[this->getIndex(this->getCapacity() - 1)] = tmp;
}

ostream& operator<<(ostream& os, const Stack &stack)
{
		cout << "Вместимость стека: " << stack.getCapacity() << endl;
		cout << "Количество элементов в стеке: " << stack.getSize() << endl;
	if (!stack.isEmpty())
	{
		cout << "Индекс начального элемента вектора: " << stack.getHead() << endl;
		for (int i = 0; i < stack.getSize(); i++)
			os << stack.V[stack.getIndex(i)] << " ";
		os << endl;
	}
	return os;
}

void Stack::expand()
{
	Stack tmp(this->getCapacity()*2);
	for (int i = 0; i < this->getSize(); i++)
		tmp.V[tmp.getIndex(i)] = this->V[this->getIndex(i)];
	tmp.setSize(this->getSize());
	delete[] this->V;
	this->setCapacity(tmp.getCapacity());
	this->setHead(tmp.getHead());
	this->V = new unsigned int[this->getCapacity()];
	for (int i = 0; i < tmp.getSize(); i++)
		this->V[this->getIndex(i)] = tmp.V[this->getIndex(i)];
}

void Stack::narrow()
{	
	Stack tmp(this->getCapacity() / 2);
	for (int i = 0; i < this->getSize(); i++)
		tmp.V[tmp.getIndex(i)] = this->V[this->getIndex(i)];
	tmp.setSize(this->getSize());
	delete[] this->V;
	this->setCapacity(tmp.getCapacity());
	this->setHead(tmp.getHead());
	this->V = new unsigned int[this->getCapacity()];
	for (int i = 0; i < tmp.getSize(); i++)
		this->V[this->getIndex(i)] = tmp.V[this->getIndex(i)];
}

int Stack::push(int element)
{
	if (this->isFull())
		this->expand();
	if (!this->isEmpty())
		this->circularShiftRight();
	this->V[this->getIndex()] = element;
	this->setSize(this->getSize() + 1);
	return element;
}

void Stack::pop()
{
	if (!this->isEmpty()) {
		this->circularShiftLeft();
		this->setSize(this->getSize() - 1);
		if ((this->getSize() != 0) && (this->getCapacity() / this->getSize() == 2))
			this->narrow();
	}
}