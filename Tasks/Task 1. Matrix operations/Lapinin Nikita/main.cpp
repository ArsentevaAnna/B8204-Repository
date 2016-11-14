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

  Matr1 = Create_rand (Matr1.n, Matr1.m);

  Print_Matrix (Matr1);

	if (Matr1.n==Matr1.m) 
  {
    cout << determ(Matr1);
	  cout << endl;
  }

  cout << "������� ���������� ����� � ���������� �������� 2-�� �������:\n";
  cin >> Matr2.n >> Matr2.m;

  Matr2 = Create_rand (Matr2.n, Matr2.m);
 
  Print_Matrix (Matr2);

	if (Matr2.n==Matr2.m) 
  {
    cout << determ(Matr2);
	  cout << endl;
  }

  if ((Matr1.n==Matr2.n) & (Matr1.m==Matr2.m))
  {  
    matr_rez = Summ (Matr1,Matr2);  
    cout << "����� �����:\n";
    Print_Matrix(matr_rez);
    delete [] matr_rez.Mass;

    matr_rez = Dif (Matr1,Matr2);	 
    cout << "�������� �����:\n";
    Print_Matrix(matr_rez);
    delete [] matr_rez.Mass;
  }


    if (Matr1.m==Matr2.n)
    {
      matr_rez = Multiple (Matr1,Matr2);
      cout << "������������ �����:\n";
      Print_Matrix(matr_rez);
      delete [] matr_rez.Mass;
    }

delete []  Matr1.Mass; delete []  Matr2.Mass;

  system("pause");
	return 0;
}


