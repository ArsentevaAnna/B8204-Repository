#include <iostream>

#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

void readMat(int** x, int *sizeLineFunc, int *sizeColFunc) { //read from file "input.txt"

	//Создаем файловый поток и связываем его с файлом
	ifstream in("input.txt");
	int error = 0;

	if (in.is_open())
	{
		//Вначале посчитаем сколько чисел в файле
		int count = 0;// число чисел в файле
		int temp;//Временная переменная

		while (!in.eof())
		{
			in >> temp;//считываем
			count++;
		}

		//посчитаем число пробелов до знака перевода на новую строку
		//переход в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//Число пробелов в первой строчке вначале равно 0
		int count_space = 0;
		char symbol;
		while (!in.eof()) {
			//теперь нам нужно считывать не числа, а посимвольно считывать данные
			in.get(symbol);//считали текущий символ
			if (symbol == ' ') count_space++;//Если это пробел, то число пробелов увеличиваем
			if (symbol == '\n') break;//Если дошли до конца строки, то выходим из цикла
		}

		//переход в начало файла
		in.seekg(0, ios::beg);
		in.clear();

		//считаем матрицу
		int n = count / (count_space + 1);//число строк
		int m = count_space + 1;//число столбцов на единицу больше числа пробелов

		//Считаем матрицу из файла
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];

		in.close();

		//передадим параметры матрицы
		*sizeLineFunc=n;
		*sizeColFunc=m;
	}
	else
	{
		cout << "File is not found";
	}
}

void printMat(int** x, int sizeLine, int sizeCol) //to file out.txt
{
	ofstream f;
	f.open("Out.txt");
	for (int i=0; i<sizeLine; i++) {
		for (int j=0; j<sizeCol; j++) {
			f<<x[i][j]<<"  ";
		}
		f<<" "<<endl;
	}
	f.close();
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int **x;
	x = new int*[100];
	for (int i = 0; i<100; i++) x[i] = new int[100];

	int sizeLine, sizeCol;
	readMat(x, &sizeLine, &sizeCol);
	printMat(x,sizeLine, sizeCol);


	for (int i = 0; i<sizeLine; i++) delete[] x[i];
	delete[] x;
	system("pause");
	return 0;
}

