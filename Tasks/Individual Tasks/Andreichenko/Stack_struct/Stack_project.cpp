#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include "Header.h"



int main()
{
	int i;
	stack_t *d = NULL; /* указатель на вершину стека */

						/* положить 10 элементов в стек от 0 до 9 */
	for (i = 0; i < 10; ++i)
		push(&d, i);

	printf("contents of the stack: \n");
	print(&d);
	printf("length of the stack: %d \n", length(&d));

	for (int i = 0; i < 5; ++i)
		pop(&d);

	printf("contents of the stack: \n");
	print(&d);
	printf("length of the stack: %d \n", length(&d));
	
	push(&d, 5);

	printf("contents of the stack: \n");
	print(&d);
	printf("length of the stack: %d \n", length(&d));


	/* очистка стека */
	clear(&d);
	system("pause");
	return 666;
}

