#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main (void)
{
	node *phead = NULL;
	int ret = 0;
	phead = init_list(1);
	ret = insert_tail(&phead, 2);
	ret = insert_tail(&phead, 3);
	ret = insert_tail(&phead, 4);
	ret = show_list(phead);

	printf("insert head  value 5\n\n");
	ret = insert(&phead, 1, 5);
	show_list(phead);

	printf("insert 2 value 6\n\n");
	ret = insert(&phead, 2, 6);	
	show_list(phead);
	
	printf("insert tail value 7\n");
	ret = insert(&phead, 6, 7);
	show_list(phead);
	printf("dele node  head \n");
	ret = delete_node(&phead, phead);
	show_list(phead);	
	printf("delenode head->pnext \n");
	ret = delete_node(&phead, phead->pNext);
	show_list(phead);
	printf("delenode head->pnext \n");
	ret = delete_node(&phead, phead->pNext);
	show_list(phead);
	printf("delenode head->pnext \n");
	ret = delete_node(&phead, phead->pNext);
	show_list(phead);
	printf("delenode head->pnext \n");
	ret = delete_node(&phead, phead->pNext);
	show_list(phead);	
	printf("delenode head->pnext \n");
	ret = delete_node(&phead, phead->pNext);
	show_list(phead);
#if 0
	printf("insert head 0 \n\n");
	ret = insert_head(&phead, 0);
	ret = show_list(phead);
	//! inser position 3, value 7
	printf("insert pos 3 value 7 \n\n");
	ret = insert(&phead, 3, 7);
	ret = show_list(phead);

	printf("delete head\n\n");
	ret = delete_node(&phead, 1);
	ret = show_list(phead);

	printf("delete position 3 \n\n");
	ret = delete_node(&phead, 3);
	ret = show_list(phead);
	
	printf("reverse list \n");
	ret = reverse_list(&phead);
	show_list(phead);
	#endif
	delete_list(&phead);
	return 0;
}
