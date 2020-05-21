
#ifndef STACK_LINKED_LIST
#define STACK_LINKED_LIST
#define MAXSIZE (5)

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int init_stack(stack *ps)
{
	if(!ps) {
		printf("invalid address \n");
		return -1;
	}

	ps->count = 0;
	ps->top = NULL;
	return 0;
}
int push_stack(stack *ps, int value)
{
	node *new = NULL;
	if (ps->count == MAXSIZE)
	{
		printf("stack overflow \n");
		return -1;
	}

	new = (node *)malloc(sizeof(node));
	if (!new) {
		printf("malloc error \n");
		return -1;
	}
	
	new->value = value;
	new->pNext = ps->top;
	ps->top = new;
	ps->count++;
	return 0;
}

int pop_stack(stack *ps, int *pvalue)
{
	node *tmp = NULL;
	if (ps->count == 0) {
		printf("empty stack\n");
		return -1;
	}
	tmp = ps->top;
	*pvalue = tmp->value;
	ps->top = tmp->pNext;
	ps->count--;
	free(tmp);
	tmp = NULL;
	return 0;
}

int destory_stack(stack *ps)
{
	int i = 0;
	node *tmp = NULL;
	if (!ps) {
		printf("invalid address\n");
		return -1;
	}
	
	while(ps->count){
		tmp = ps->top;
		ps->top = tmp->pNext;
		free(tmp);
		tmp = NULL;
		ps->count--;
	}
	return 0;
}

int show_stack(stack *ps)
{
	int i = ps->count;
	node *tmp = ps->top;
	while (i)
	{
		printf("%d \n", tmp->value);
		tmp = tmp->pNext;	
		i--;
	}
	return 0;
}
#endif
