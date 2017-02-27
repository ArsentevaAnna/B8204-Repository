#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100 //размерность массива


void main (void)
{
	unsigned int x1,y1,x2,y2;
	do {
		printf("Put number of strings matrix A= \n");	
		scanf("%d",&x1);
		printf("Put number of column matrix A= \n");	
		scanf("%d",&y1);
		printf("Put number of strings matrix B= \n");	
		scanf("%d",&x2);
		printf("Put number of column matrix B= \n");	
		scanf("%d",&y2);
		if ((x1>N)||(x2>N)||(y1>N)||(y2>N))
			printf("Invalid value of array, put right numbers");
	} while ((x1>N)||(x2>N)||(y1>N)||(y2>N));

	char **A;
	A=(char**) malloc(x1 * sizeof(char*));
	for (int i = 0; i < y1; i++) {
	    A[i] = (char*) malloc((i + 1) * sizeof(char));
	}
	char **B;
	B=(char**) malloc(x2 * sizeof(char*));
	for (int i = 0; i < y2; i++) {
	    B[i] = (char*) malloc((i + 1) * sizeof(char));
	}

	printf("matrix A\n");
	srand(time(NULL));
	randPrint(x1,y1,A);

	printf("matrix B\n");
	randPrint(x2,y2,B);

	char op = 0;

	do {
		printf("Choose a operation (* mult,+ summ,- dif) ");	
		scanf("%c",&op);
	} while ((op!='*')&&(op!='+')&&(op!='-'));

	switch (op)
	{
		case '+':
			summ(x1,y1,x2,y2,A,B);
			break;
		case '-':
			diff(x1,y1,x2,y2,A,B);
			break;
		case '*':
			mult(x1,y1,x2,y2,A,B);
			break;
	}

	return;
}