#pragma once

typedef struct stack {
	int value;
	struct stack * next;
} node_t, stack_t;

int is_empty(stack_t ** top);
void push(stack_t ** top, int value);
void pop(stack_t **top);
int top(stack_t **top);
void clear(stack_t **top);
int length(stack_t **top);
void print(stack_t **top);

