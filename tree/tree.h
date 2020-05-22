
#ifndef TREE_J
#define TREE_J

typedef struct node {
	int value;
	struct node *pleft;
	struct node *pright;
} node;	

node *new_node(int value);
int preorder(node *root);
int inorder(node *root);
int postorder(node *root);
int release_tree(node *root);
int get_tree_height(node *root);
int get_total_node(node *root);
#endif
