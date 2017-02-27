#include "stdafx.h"
#include "vector.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Vector a;
	init(a);
	print(a);
	insert(a, 0, 1);
	insert(a, 1, 2);
	insert(a, 2, 3);
	insert(a, 3, 4);
	print(a);
	cout << get(a,5) << "\n";
	cout << length (a) << "\n";
	insert(a, 4, 5);
	print(a);
    del(a, 1);
	print(a);
	insert(a, 4, 6);
	print(a);
	insert(a, 1, 9);
	print(a);
	insert(a, 2, 9);
	print(a);
	insert(a, 2, 7);
	print(a); 
	insert(a, 2, 8);
	print(a);
	insert(a, 7, 10);
	print(a);
	insert(a, 2, 11);
	print(a);
	cout << del(a, 2) <<"\n";
	cout << del(a,5) <<"\n";
	cout << del(a,4) <<"\n";
	print(a);
	cout << del(a, 4) << "\n";
    cout << del(a, 2) << "\n";
	print(a);
	cout << get(a, 4)<< "\n";
	cout << get(a, 1)<< "\n";
	cout << length (a) << "\n";
	system("pause");
	return 0;
}