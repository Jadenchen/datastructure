
#ifndef QUEUE_LINKED_LIST_J
#define QUEUE_LINKED_LIST_J

typedef struct node {
	int value;
	struct node *pNext;
} node;	

typedef struct linkqueue {
	node *pfront;
	node *prear;
} linkqueue;

int init_linkqueue(linkqueue *lq);

int delete_linkqueue(linkqueue *lq);

int show_linkqueue(linkqueue *lq);

int en_linkqueue(linkqueue *lq, int value);

int de_linkqueue(linkqueue *lq, int *pvalue);

#endif
