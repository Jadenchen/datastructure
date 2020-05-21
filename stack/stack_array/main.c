#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main (void)
{
	stack test_stack;
	int ret = 0;
	int value;
	ret = init_stack(&test_stack);
	ret = push_stack(&test_stack, 1);
	ret = push_stack(&test_stack, 2);
	show_stack(&test_stack);
	ret = pop_stack(&test_stack, &value);
	printf("value %d \n", value);
	show_stack(&test_stack);
	destory_stack(&test_stack);
	return 0;
}
