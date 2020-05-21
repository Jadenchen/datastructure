
#ifndef LINKED_LIST_J
#define LINKED_LIST_J
#define MAXSIZE (5)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int init_stack(stack *ps)
{
	int i = 0;
	if(!ps) {
		printf("invalid address \n");
		return -1;
	}

	ps->top = -1;
	for (i = 0; i < MAXSIZE; i++) {
		ps->data[i] = -1;
	}
	return 0;
}
int push_stack(stack *ps, int value)
{
	if (ps->top == MAXSIZE -1)
	{
		printf("stack overflow \n");
		return -1;
	}

	ps->top++;
	ps->data[ps->top] = value;
	return 0;
}

int pop_stack(stack *ps, int *pvalue)
{
	if (ps->top == -1) {
		printf("empty stack\n");
		return -1;
	}
	*pvalue = ps->data[ps->top];
	ps->top--;
	return 0;
}

int destory_stack(stack *ps)
{
	int i = 0;
	if (!ps) {
		printf("invalid address\n");
		return -1;
	}
	ps->top = -1;
	for (i = 0; i < MAXSIZE; i++) {
		ps->data[i] = -1;
	}
	return 0;
}

int show_stack(stack *ps)
{
	int i = ps->top;
	while (i != -1)
	{
		printf("%d \n", ps->data[i]);
		i--;
	}
	return 0;
}
#endif
