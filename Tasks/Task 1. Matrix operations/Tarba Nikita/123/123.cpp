// �������.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "TMatrix.h"

#include <iostream>
#include <ctime>

using namespace std;

	int _tmain()
{ Matrix Matr1,Matr2,matr_rez;
  setlocale(LC_ALL, "Russian");
  srand(unsigned(time(NULL)));
  cout << "������� ���������� ����� � ���������� ��������:\n";
  cin >> Matr1.n >> Matr1.m;
  
  Create_rand(Matr1, Matr1.n,Matr1.m);

  Print_Matrix(Matr1,Matr1.n,Matr1.m);

	if (Matr1.n==Matr1.m) 
  {
    cout << determ(Matr1.Mass, Matr1.n);
	  cout << endl;
  }

  cout << "������� ���������� ����� � ���������� �������� 2-�� �������:\n";
  cin >> Matr2.n >> Matr2.m;
  
  Create_rand(Matr2, Matr2.n,Matr2.m);


  Print_Matrix(Matr2,Matr2.n,Matr2.m);

	if (Matr2.n==Matr2.m) 
  {
    cout << determ(Matr2.Mass, Matr2.n);
	  cout << endl;
  }

  if ((Matr1.n==Matr2.n) & (Matr1.m==Matr2.m))
  {  
    Summ (Matr1,Matr2,matr_rez);  
    cout << "����� �����:\n";
    Print_Matrix(matr_rez,Matr2.n,Matr2.m);
    delete [] matr_rez.Mass;

    Dif (Matr1,Matr2,matr_rez);	 
    cout << "�������� �����:\n";
    Print_Matrix(matr_rez,Matr2.n,Matr2.m);
    delete [] matr_rez.Mass;
  }


    if (Matr1.m==Matr2.n)
    {
      Multiplication (Matr1,Matr2,matr_rez);
      cout << "������������ �����:\n";
      Print_Matrix(matr_rez,Matr1.n,Matr2.m);
      delete [] matr_rez.Mass;
    }

delete []  Matr1.Mass; delete []  Matr2.Mass;

  system("pause");
	return 0;
}


