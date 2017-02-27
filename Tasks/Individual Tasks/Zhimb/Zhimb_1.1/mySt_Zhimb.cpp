// mySt_Zhimb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"myStack.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL,"rus");
   int buff;  
 ifstream st_file ("input.txt");
 if (st_file.is_open())
 {
	 stek *p=0;
    while (!st_file.eof())
    {
        st_file >> buff;
       cout << buff << ' ';
	   push(p,buff);
    }
	cout << "\n";
	cout <<Size(p)<<endl;
	Write(p);
	cout <<pop(p)<<endl;
	cout <<Size(p)<<endl;
	Write(p);
 st_file.close();
 }
 else
 {
  cout << "Ошибка открытия файла!"; 
 }
 system("pause");   
 return 0;
}
