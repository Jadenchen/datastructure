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

	pTmp->value = value;
	pTmp->pNext = NULL;
	pTmp->prev = NULL;
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

int insert_tail(node **ppHead, int value)
{
	node *pcurr = *ppHead;
	node *pnew = NULL;	
	while(pcurr->pNext) {
		pcurr = pcurr->pNext;
	}
	pnew = new(value);
	pnew->prev = pcurr;
	pcurr->pNext = pnew;
	return 0;
}

int show_list(node *pHead)
{
	node *pcurr = pHead;
	while (pcurr)
	{
		printf(" %d ", pcurr->value);
		pcurr = pcurr->pNext;
	}
	printf("\n");
	return 0;	
}

int insert(node **ppHead, int pos, int value)
{	
	node *pcurr = *ppHead;
	node *pnew = NULL;
	int len = 0;

	while (pcurr->pNext) {	
		if (++len == pos) 
			break;
		pcurr = pcurr->pNext;
	}

	if (len == 1) {
		pnew = new(value);
		pnew->pNext = pcurr;
		pcurr->prev = pnew;
		*ppHead = pnew;
	} else {
		pnew = new(value);
		pnew->prev = pcurr;
		pnew->pNext = pcurr->pNext;
		if (pcurr->pNext) {
			pcurr->pNext->prev = pnew;
		}
		pcurr->pNext = pnew;
	}
	
	return 0;
}
int reverse_list(node **ppHead)
{
#if 0
	node *pcurr = *ppHead;
	node *prev = NULL;
	node *pnext = NULL;

	while(pcurr) {
		pnext = pcurr->pNext;
		prev = pcurr->prev;
		pcurr = pcurr->pNext;
	}

	*ppHead = pcurr;
#endif
	return 0;
}

int delete_node(node **ppref, node *pdel)
{
	node *curr = NULL;
	node *tmp = NULL;
	if (!*ppref || !pdel) {
		printf("%s invalid handle \n", __func__);
		return -1;
	}

	curr = *ppref;
	
	if (curr == pdel) {
		tmp = curr->pNext;
		tmp->prev = NULL;
		*ppref = tmp;
	} else {

		while (curr->pNext) {
			if (curr->pNext == pdel)
				break;
			curr = curr->pNext;
		}
		curr->pNext = pdel->pNext;
		if (pdel->pNext)
			pdel->pNext->prev = curr;
		pdel->prev = NULL;
		pdel->pNext = NULL;
	}
	
	free(pdel);
	pdel = NULL;
	return 0;
}	

