
#ifndef QUEUE_ARRAY_J
#define QUEUE_ARRAY_J

#define MAXSIZE (5)
typedef struct queue {
	int data[MAXSIZE];
	int front;
	int rear;
}queue;

int init_queue_array(queue *pq);
int en_queue_array(queue *pq, int value);
int de_queue_array(queue *pq, int *pvalue);
int destory_queue_array(queue *pq);
int get_queue_len(queue *pq);
int show_queue_array(queue *pq);
#endif
