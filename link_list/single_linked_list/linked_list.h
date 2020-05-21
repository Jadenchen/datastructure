
#ifndef LINKED_LIST_J
#define LINKED_LIST_J

typedef struct node {
	int value;
	struct node *pNext;
} node;	

node *init_list(int value);

int delete_list(node **ppHead);

int show_list(node *pHead);

int insert_tail(node **ppHead, int value);

int insert_head(node **ppHead, int value);

int insert(node **ppHead, int pos, int value);

int delete_node(node **ppHead, int pos);

int reverse_list(node **ppHead);
#endif
