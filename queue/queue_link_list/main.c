#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_linked_list.h"

int main (void)
{
	linkqueue lq;
	int ret = 0;
	int devalue;
	memset(&lq, 0, sizeof(linkqueue));
	ret = init_linkqueue(&lq);
	ret = en_linkqueue(&lq, 1);
	ret = en_linkqueue(&lq, 2);
	ret = en_linkqueue(&lq, 3);
	show_linkqueue(&lq);
	ret = de_linkqueue(&lq, &devalue);
	printf("[%s] dequeue %d \n",__func__, devalue);
	ret = de_linkqueue(&lq, &devalue);
	printf("[%s] dequeue %d \n",__func__, devalue);
	ret = de_linkqueue(&lq, &devalue);
	printf("[%s] dequeue %d \n",__func__, devalue);
	show_linkqueue(&lq);
	ret = delete_linkqueue(&lq);
	return 0;
}
