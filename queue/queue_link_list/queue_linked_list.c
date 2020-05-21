
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue_linked_list.h"	

static node *new_node(int value)
{
	node *new = NULL;
	new = (node *)malloc(sizeof(node));
	if (!new) {
		printf("[%s] malloc failed \n",__func__);
		return NULL;
	}
	new->value = value;
	new->pNext = NULL;
	return new;
}

int init_linkqueue(linkqueue *lq)
{
	if (!lq) {
		printf("[%s] invalid address \n",__func__);
		return -1;
	}

	lq->pfront = NULL;
	lq->prear = NULL;
	return 0;
}

int show_linkqueue(linkqueue *lq)
{	
    	node *ptmp = NULL;
	if (lq->pfront == NULL) {
		printf("[%s] empty queue \n",__func__);
		return -1;
	}
        ptmp = lq->pfront;	
        while (ptmp) {
                printf("queue %d \n",ptmp->value);
                ptmp = ptmp->pNext;
        }
        return 0;
}

int delete_linkqueue(linkqueue *lq)
{
	node *ptmp = NULL;
	node *prev = NULL;
	ptmp = lq->pfront;
	while (ptmp)
	{	prev = ptmp;
		ptmp = ptmp->pNext;
		free(prev);
	}
	return 0;
}

int en_linkqueue(linkqueue *lq, int value)
{
	//! start add rear 
	node *pnew = NULL;
	pnew = new_node(value);
	if(!pnew) {
		printf("[%s] new node init failed \n",__func__);
		return -1;
	}
	if (lq->pfront == NULL)
		lq->pfront = pnew;
	if (lq->prear == NULL)
		lq->prear = pnew;
	else {
		lq->prear->pNext = pnew;
		lq->prear = pnew;
	}
	
	return 0;
}

int de_linkqueue(linkqueue *lq, int *pvalue)
{
	node *ptmp = NULL;
	if (!lq->pfront) {
		printf("[%s] empty queue \n", __func__);
		return -1;
	}
	
	ptmp = lq->pfront;
	*pvalue = ptmp->value;
	lq->pfront = ptmp->pNext;
	free(ptmp);
	return 0;
}


