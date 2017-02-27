#include "funcs.h"

void randPrint (int x1, int y1, char** A)
{
	for (int i = 0; i < x1; i++) {
	for (int j = 0; j < y1; j++)
	{
	    A[i][j] = rand() % 10;
	    printf("%d ", A[i][j]);
	}
	printf("\n");
	}
}

void summ (int x1, int y1, int x2, int y2, char** A, char** B)
{
	if ((x1==x2)&&(y1==y2)){
		char** C;
		C=(char**) malloc(x1 * sizeof(char*));
		for (int i = 0; i < y2; i++) {
		    C[i] = (char*) malloc((i + 1) * sizeof(char));
		}
		printf("result: A+B:\n");
		for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y1; j++)
		    {
		        C[i][j] = A[i][j]+B[i][j];
		        printf("%d ", C[i][j]);
		    }
		    printf("\n");
		}
	}
	else {
		printf("Error, can't summ matrix with this values");
	}
}

void diff (int x1, int y1, int x2, int y2, char** A, char** B)
{
	if ((x1==x2)&&(y1==y2)){
		char** C;
		C=(char**) malloc(x1 * sizeof(char*));
		for (int i = 0; i < y2; i++) {
		    C[i] = (char*) malloc((i + 1) * sizeof(char));
		}
		printf("result: A+B:\n");
		for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y1; j++)
		    {
		        C[i][j] = A[i][j]-B[i][j];
		        printf("%d ", C[i][j]);
		    }
		    printf("\n");
		}
	}
	else {
		printf("Error, can't summ matrix with this values");
	}
}

void mult (int x1, int y1, int x2, int y2, char** A, char** B)
{
	if (y1==x2){
		char** C;
		C=(char**) malloc(x1 * sizeof(char*));
		for (int i = 0; i < y2; i++) {
		    C[i] = (char*) malloc((i + 1) * sizeof(char));
		}
		printf("result: A*B:\n");
		for (int i = 0; i < x1; i++) {
		    for (int j = 0; j < y2; j++)
		    {
		    	C[i][j] = 0;
		        for(int k=0;k<x2;k++){
		        	C[i][j]+=A[i][k]*B[k][j];
		        }
		        printf("%d ", C[i][j]);
		    }
		    printf("\n");
		}
	}
	else {
		printf("Error, can't mult matrix with this values");
	}
}

