#include "stdafx.h"

struct Matrix
{
  int n;
  int m;
  int** Mass;
};

long double determ(int** Arr, int size);//������������
void Summ (Matrix Matr1,Matrix Matr2,Matrix &matr_rez);//��������
void Dif (Matrix Matr1,Matrix Matr2,Matrix &matr_rez);//���������
void Multiplication (Matrix Matr1,Matrix Matr2,Matrix &matr_rez);//���������
void Print_Matrix (Matrix matr,int n,int m); //������
void Create (Matrix &Matr , int n, int m); //�������� �������
void Create_rand (Matrix &Matr , int n, int m);