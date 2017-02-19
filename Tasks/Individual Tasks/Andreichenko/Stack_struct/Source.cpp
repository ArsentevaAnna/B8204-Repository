#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include "Header.h"


int is_empty(stack_t ** top) {
	return *top == NULL;
}
/* push
* ����� ������� � ����
*/
void push(stack_t ** top, int value) {
	node_t *node = (node_t *)malloc(sizeof(node_t));


	node->value = value;
	node->next = NULL;

	/* ���� ���� �� ����, �� ������ �� ���������� ������� */
	if (!is_empty(top))
		node->next = *top;
	(*top) = node;
}
/* pop
* �������� ��������.
*/
void pop(stack_t **top) {
	node_t *node;

	/* ���� ���� ����, �� ������� ������ �� ���� */
	if (!is_empty(top)) {
		node = *top;
		*top = (*top)->next;

		free(node);
		node = NULL;
	}
}


int top(stack_t **top) {
	if (!is_empty(top))
		return (*top)->value;
	else
		return 0;
}

/* clear
* ������� �����.
*/
void clear(stack_t **top) {
	while (!is_empty(top))
		pop(top);
}
/* length
* ����� �����.
*/
int length(stack_t **top) {
	node_t *node;
	int value = 0;
	for (node = *top; node != NULL; node = node->next) {
		value = value + 1;
	}
	return value;
}

/* print
* �������� ����.
*/
void print(stack_t **top) {
	node_t *node;
	for (node = *top; node != NULL; node = node->next)
		printf("%d -> ", node->value);
	printf("\b\b\b   \n");
}