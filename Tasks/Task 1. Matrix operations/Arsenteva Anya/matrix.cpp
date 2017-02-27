#include "stdafx.h" 
#include "matrix.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <stdlib.h> 
#include <fstream>
using namespace std;

Matrix Read(ifstream& fin) //ввод и заполнение матрицы
{
	Matrix a;
	setlocale(LC_ALL, "Russian");
	//srand((unsigned)time(NULL));
	//ifstream fin;
	//ofstream fout;
	//ofstream my_file("matrix.txt");
	//my_file << "hello world";
	//my_file.close();

	//fout.open ("123.txt");
	//if (fin.is_open()) 
	//{
	//	cout << "открыт\n";
	//}
	//else 
	//{
	//	cout << "не открыт\n";
	//}
	//fin.open ("matrix.txt");
	fin >> a.x;
	fin >> a.y;
	//fout <<  "18274";
	//fout.close();
	int i, j;
	a = Create(a.x, a.y);

	for (i = 0; i < a.x; ++i) {
		for (j = 0; j < a.y; ++j){
			//a.masMat[i][j] = rand() % 19 - 9;
			fin >> a.masMat[i][j];
		}
	}
	return a;
}

Matrix Create(int x, int y) //создание матрицы
{
	Matrix a;
	int i;

	a.masMat = new int *[x];
	for (i = 0; i < x; i++)
	{
		a.masMat[i] = new int[y];
	}
	a.x = x; a.y = y;
	return a;
}

void Print(Matrix a) //вывод матрицы на экран
{
	int i, j;
	for (i = 0; i < a.x; i++)
	{
		for (j = 0; j < a.y; j++)
		{
			cout << a.masMat[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Sum(Matrix a, Matrix b) //сложение двух матриц
{
	Matrix c = Create(a.x, a.y);
	printf("\nСумма матриц (A + B):");
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			c.masMat[i][j] = a.masMat[i][j] + b.masMat[i][j];
		}
		cout << endl;
	}
	return c;
}

Matrix Razn(Matrix a, Matrix b) //вычитание двух матриц
{
	Matrix d = Create(a.x, a.y);
	printf("\nРазность матриц (A - B):");
	for (int i = 0; i < a.x; i++)
	{
		for (int j = 0; j < a.y; j++)
		{
			d.masMat[i][j] = a.masMat[i][j] - b.masMat[i][j];
		}
		cout << endl;
	}
	return d;
}

Matrix Umnozh(Matrix a, Matrix b) //произведение двух матриц
{
	Matrix e = Create(a.x, b.y);
	int i, j, k;
	printf("\nПроизведение матриц (A*B):\n");

	for (i = 0; i < a.x; i++) {
		for (j = 0; j < b.y; j++) {
			e.masMat[i][j] = 0;
			for (k = 0; k < a.y; k++)
				e.masMat[i][j] = e.masMat[i][j] + a.masMat[i][k] * b.masMat[k][j];
		}
	}
	return e;
}

Matrix getMat(Matrix a, Matrix p, int i, int j, int x) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki < x - 1; ki++) { // проверка индекса строки 
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < x - 1; kj++) { // проверка индекса столбца 
			if (kj == j) dj = 1;
			p.masMat[ki][kj] = a.masMat[ki + di][kj + dj];
		}
	}
	return p;
}


int Det(Matrix a, int x) //подсчет определителя 
{
	int i, j, d, k, n;
	Matrix p = Create(a.x, a.x);
	j = 0; d = 0;
	k = 1;
	n = x - 1;
	if (x < 1) {
		printf("Определитель вычислить невозможно!");
	}
	if (x == 1) {
		d = a.masMat[0][0];
		return(d);
	}
	if (x == 2) {
		d = a.masMat[0][0] * a.masMat[1][1] - (a.masMat[1][0] * a.masMat[0][1]);
		return(d);
	}
	if (x > 2){
		for (i = 0; i < x; i++) {
			p = getMat(a, p, i, 0, a.x);
			d = d + k * a.masMat[i][0] * Det(p, n);
			k = -k;
		}
	}
	return(d);
}