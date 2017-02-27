// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"myStack.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int buff;
	ifstream st_file("input.txt");
	if (st_file.is_open())
	{
		stek *p = 0;
		while (!st_file.eof())
		{
			st_file >> buff;
			cout << buff << ' ';
			push(p, buff);
		}
		cout << "\n";
		cout << Size(p) << endl;
		cout << pop(p) << endl;
		cout << Size(p) << endl;
		st_file.close();
	}
	else
	{
		cout << "Ошибка открытия файла!"<<endl;
	}
	system("pause");
	return 0;
}
