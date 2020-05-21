
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linked_list.h"	

/* crate list */
static node *new(int value)
{
	node *pTmp = NULL;
	pTmp = (node *) malloc (sizeof (node));
	if (!pTmp) {
		printf("init node failed \n");
		return NULL;
	}

	pTmp ->value = value;
	pTmp ->pNext = NULL;
	return pTmp;
}

node *init_list(int value)
{
	node *pTmp = NULL;
	pTmp = new(value);
	return pTmp;	
}

int delete_list(node **ppHead)
{	
	node *pcurr = *ppHead;
	node *prev = NULL;
	assert(pcurr);
	while (pcurr) {
		prev = pcurr;
		pcurr = pcurr->pNext;
		free(prev);
	}

	return 0;
}

int insert(node **ppHead, int pos, int value)
{
	node *prev = *ppHead;
	node *pnew = NULL;
	int len = 1;
	assert(prev);
	while(prev->pNext) {
		if (++len == pos)
			break;
		prev = prev->pNext;
		//++len;
	}

	pnew = new(value);
	pnew->pNext = prev->pNext;
	prev->pNext = pnew;
	return 0;
}

int insert_head(node **ppHead, int value)
{
	node *pcurr = *ppHead;
	node *pnew_head = NULL;
	assert(pcurr);
	pnew_head = new(value);
	*ppHead = pnew_head;
	pnew_head->pNext = pcurr;
	return 0;
}

int insert_tail(node **ppHead, int value)
{
	node *prev = *ppHead;
	node *pnew = NULL;
	while (prev->pNext) {
		prev = prev->pNext;
	}

	pnew = new(value);
	prev->pNext = pnew;
	return 0;
}

int show_list(node *pHead)
{
	node *pcurr = pHead;
	while (pcurr)
	{
		printf("list value %d \n", pcurr->value);
		pcurr = pcurr->pNext;
	}
	return 0;	
}

int delete_node(node **ppHead, int pos)
{
	node *prev = *ppHead;
	node *pTmp = NULL;
	int len = 1;
	assert(prev);
	if (pos == 1) {
		pTmp = prev->pNext;
		*ppHead = pTmp;
		free(prev);
	} else {
		while(prev->pNext) {
			if (++len == pos)
				break;
			prev = prev->pNext;
		}

		if (pos > len) {
			printf("pos is bigger than list length\n");
			return -1;
		}
		pTmp = prev->pNext;
		prev->pNext = pTmp->pNext;
		free(pTmp);
	}

	return 0;
}

int reverse_list(node **ppHead)
{
	//! need three pointer
	node *prev = NULL;
	node *pnext = NULL;
	node *pcurr = *ppHead;
	while(pcurr != NULL) {
		pnext = pcurr->pNext;
		pcurr->pNext = prev;
		prev = pcurr;
		pcurr = pnext;
	}
	*ppHead = prev;
	return 0;
}
