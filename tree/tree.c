
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node *new_node(int value)
{
	node *new = NULL;
	new = (node *)calloc(1, sizeof(node));
	if (!new) {
		printf("[%s] init failed \n",__func__);
		return NULL;
	}

	new->value = value;
	new->pleft = NULL;
	new->pright = NULL;
	return new;
}

int preorder(node *root)
{
	if(!root)
		return 0;
	printf("[%s] %d \n",__func__, root->value);
	preorder(root->pleft);
	preorder(root->pright);
	return 0;
}

int postorder(node *root)
{
	if (!root) {
		return -1;
	}
	postorder(root->pleft);
	postorder(root->pright);
	printf("[%s] %d \n", __func__, root->value);
	return 0 ;
}

int inorder(node *root)
{
	if (!root) {
		//printf("[%s] invalid root\n", __func__);
		return -1;
	}

	inorder(root->pleft);
	printf("[%s] %d \n", __func__, root->value);
	inorder(root->pright);
	return 0;
}

int release_tree(node *root)
{
	if (!root) {
		//printf("[%s] invalid root \n", __func__);
		return -1;
	}
	
	release_tree(root->pleft);
	release_tree(root->pright);
	free(root);
	root = NULL;	
	return 0;
}

int get_tree_height(node *root)
{
	int lheight = 0;
	int rheight = 0;
	if (!root) {
		//printf("[%s] invalid root \n",__func__);
		return 0;
	}
//	if (root->pleft)
//		printf("[%s] left %d \n", __func__, root->pleft->value);
//	if (root->pright)
//		printf("[%s] right %d \n", __func__, root->pright->value);
	lheight = get_tree_height(root->pleft);
	rheight = get_tree_height(root->pright);
	
//	printf("[%s] lheight %d rheight %d \n", __func__, lheight, rheight);
	if(lheight > rheight) 
		return lheight + 1;
	else
		return rheight + 1;

}

static int count_node(node *root, int depth)
{
	int lcount = 0;
	int rcount = 0;
	if (depth == 1)
		return 1;
	else {
		if (root->pleft)
			lcount = count_node(root->pleft, depth -1);
		if (root->pright)
			rcount = count_node(root->pright, depth -1); 
	}
	return lcount + rcount;
}

int get_total_node(node *root)
{
	int depth = 0;	
	int i;
	int count = 0;
	int tmp = 0;
	if (!root) 
		return -1;
	depth = get_tree_height(root);
	printf("[%s] depth %d \n", __func__, depth);
	for (i = 1; i <= depth; i++)
	{
		tmp =  count_node(root, i);		
		printf("[%s] tmp %d \n",__func__, tmp);
		count += tmp;
	}	
	
	return count;	
}
