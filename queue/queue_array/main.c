#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main (void)
{
	queue tq;
	int ret = 0;
	int value;
	ret = init_queue_array(&tq);
	ret = en_queue_array(&tq, 1);
	ret = en_queue_array(&tq, 2);
	ret = en_queue_array(&tq, 3);
	printf("show queue \n");
	show_queue_array(&tq);
	de_queue_array(&tq, &value);
	printf("show value %d \n", value);
	de_queue_array(&tq,&value);
	printf("show value %d \n", value);
	show_queue_array(&tq);
	en_queue_array(&tq, 4);
	en_queue_array(&tq, 5);
	en_queue_array(&tq, 6);
	en_queue_array(&tq, 7);
	printf("queue length %d \n", get_queue_len(&tq));
	show_queue_array(&tq);
	destory_queue_array(&tq);
	return 0;
}
