
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int init_queue_array(queue *pq)
{
	int i = 0;
	if(!pq) {
		printf("invalid address \n");
		return -1;
	}

	for (i = 0; i < MAXSIZE; i++) 
	{
		pq->data[i] = 0;
	}

	pq->front = 0;
	pq->rear = 0;
	return 0;
}

int en_queue_array(queue *pq, int value)
{
	//! add rear when enqueue 
	printf("front %d rear %d \n", pq->rear, pq->front);
	if ((pq->rear + 1)%MAXSIZE == pq->front) {
		printf("[%s] no space \n",__func__);
		return -1;
	}

	pq->data[pq->rear] = value;
	pq->rear = (pq->rear + 1) %MAXSIZE;
	return 0;
}

int de_queue_array(queue *pq, int *pvalue)
{
	if (pq->front == pq->rear) {
		printf("empty queue \n");
		return -1;
	}

	*pvalue = pq->data[pq->front];
	pq->front = (pq->front + 1)%MAXSIZE;
	return 0;
}

int destory_queue_array(queue *pq)
{
	int i = 0;
	for(i =0; i < MAXSIZE; i++)
	{
		pq->data[i] = 0;
	}
	return 0;
}

int show_queue_array(queue *pq)
{
	int i = pq->front;
	while (i != pq->rear) {
		printf("queue %d \n", pq->data[i]);
		 i = (i+1)%MAXSIZE;
	}
	return 0;
}

int get_queue_len(queue *pq)
{
	return ((pq->rear - pq->front) + MAXSIZE) %MAXSIZE;
}
