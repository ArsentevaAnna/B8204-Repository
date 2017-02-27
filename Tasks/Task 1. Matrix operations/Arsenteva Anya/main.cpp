#include "stdafx.h" 
#include "matrix.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix a, b, c, d, e;
	ifstream fin;
	fin.open("matrix.txt");
	a = Read(fin);
	if (a.x > 9 || a.x <= 0 || a.y > 9 || a.y <= 0)
	{
		cout << "Количество столбцов и строк должно входить в интервал от 1 до 9\n";
		cout << "Измените данные входного файла\n";
	}
	else
	{
		cout << "Матрица A:\n";
		Print(a);
		if (a.x == a.y)
		{
			cout << "Определитель матрицы A = " << Det(a, a.x);
			cout << "\n\n";
		}
		else {
			cout << "Для подсчёта определителя матрица должна быть квадратной";
		}
		b = Read(fin);
		if (b.x > 9 || b.x <= 0 || b.y > 9 || b.y <= 0)
		{
			cout << "\nКоличество столбцов и строк должно входить в интервал от 1 до 9\n";
			cout << "Измените данные входного файла ";
		}
		else
		{
			cout << "\n";
			cout << "Матрица B:\n";
			Print(b);
			fin.close();
			if (b.x == b.y)
			{
				cout << "Определитель матрицы B = " << Det(b, b.x);
				cout << "\n";
			}
			else {
				cout << "Для подсчёта определителя матрица должна быть квадратной";
			}
			if (a.x == b.x && a.y == b.y)
			{
				c = Sum(a, b);
				Print(c);
				d = Razn(a, b);
				Print(d);
				delete[] d.masMat;
			}
			else
			{
				cout << "\nДля сложения и вычитания матрицы должны быть одной размерности\n";
			}
			if (a.y == b.x) {
				e = Umnozh(a, b);
				//cout << "\n";
				Print(e);
				delete[] e.masMat;
			}
			else
			{
				cout << "\nДля умножения количество столбцов первой матрицы должно совпадать с количеством строк второй\n";
			}
			delete[] b.masMat;
		}
	}
	delete[] a.masMat;
	system("pause");
	return 0;
}