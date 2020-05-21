
#ifndef STACK_J
#define STACK_J
#define MAXSIZE (5)

typedef struct stack {
	int top;
	int data[MAXSIZE];
}stack;	

int init_stack(stack *ps);
int push_stack(stack *ps, int value);
int pop_stack(stack *ps, int *pvalue);
int destory_stack(stack *ps);
int show_stack(stack *ps);
#endif
