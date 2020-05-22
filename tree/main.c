#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//! inserting node in level order
int main (void)
{
	// 10
	// 11  9 
	// 7  15 8
	int height = 0;
	int complete_node = 0;
	node *root = new_node(10);
	root->pleft = new_node(11);
	root->pright = new_node(9);
	root->pleft->pleft = new_node(7);
	root->pright->pleft = new_node(15);
	root->pright->pright = new_node(8);

		
	preorder(root);
	printf("\n\n\n\n");
	inorder(root);
	printf("\n\n\n\n");
	postorder(root);
	height = get_tree_height(root);
	printf("[%s] tree height %d \n",__func__, height);
	complete_node = get_total_node(root);
	printf("[%s] complete_node %d \n", __func__, complete_node);
	release_tree(root);
	return 0;
}
