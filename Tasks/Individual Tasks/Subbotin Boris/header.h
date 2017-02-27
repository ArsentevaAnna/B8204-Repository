#include "stdafx.h"

using namespace std;

class Stack
{
public:
	Stack(int capacity = DEFAULT_STACK_CAPACITY); // Конструктор стека
	~Stack(); // Деструктор стека
	friend ostream& operator<<(ostream& os, const Stack &stack); // Вывод информации о стеке на экран
	int getCapacity() const; // Возвращает текущую вмстимость стека
	int push(int element); // Добавляет элемент в стек и возвращает значение этого элемента
	void pop(); // Удаляет элемент стека

private:
	static const int DEFAULT_STACK_CAPACITY = 5; // Стандартный размер стека
	int *capacity; // Вместимость стека
	int *size; // Текущее количество элементов стека
	unsigned int *head; // Положение элемента головы стека
	unsigned int *V; // Стек
	int getSize() const; // Возвращает текущее количество элементов в стеке
	int getHead() const; // Возвращает индекс головного элемента
	int getIndex(int i = 0) const; // Возвращает i-ый индекс стека относительно его головного элемента
	void setSize(int n); // Задает значение количества элементов стека
	void setHead(int n); // Задает значение головного элемента стека
	void setCapacity(int n); // Задает значение вместимости стека
	bool isEmpty() const; // Проверяет стек на пустоту
	bool isFull() const; // Проверяет стек на заполненность
	void circularShiftRight(); // Циклический сдвиг стека вправо
	void circularShiftLeft(); // Циклический сдвиг стека влево
	void expand(); // Увеличивает вместимость стека в два раза
	void narrow(); // Уменьшает вместимость стека в два раза
};