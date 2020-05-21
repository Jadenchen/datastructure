#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main (void)
{
	stack stk;
	int ret = 0;
	int value;
	ret = init_stack(&stk);
	ret = push_stack(&stk, 1);
	ret = push_stack(&stk, 2);
	ret = push_stack(&stk, 3);
	printf("show stack \n");
	show_stack(&stk);
	pop_stack(&stk,&value);
	printf("show value 1 %d \n", value);
	pop_stack(&stk,&value);
	printf("show stack 2 %d \n", value);
	show_stack(&stk);
	destory_stack(&stk);
	return 0;
}
