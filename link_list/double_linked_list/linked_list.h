
#ifndef LINKED_LIST_J
#define LINKED_LIST_J

typedef struct node {
	int value;
	struct node *pNext;
	struct node *prev;
} node;	

node *init_list(int value);

int delete_list(node **ppHead);

int delete_node (node **ppref, node *del);

int show_list(node *pHead);

int insert_tail(node **ppHead, int value);

int insert(node **ppHead, int pos, int value);

int reverse_list(node **ppHead);
#endif
