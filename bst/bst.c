/*
 * This file is bst.c
 * Binary search tree implementation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

 /*
  * Creates an empty tree
  */
pedge new_tree(void)
{
	pedge root = malloc(sizeof(struct edge));
	if (NULL == root)
	{
		printf("ERROR: failed allocation of memory for new tree!\n");
		return NULL;
	}
	root->left = NULL;
	root->right = NULL;
	root->key = NULL;
	root->value = 0.0;
	return root;
}

/*
* Insert new edge into tree
*/
int add_edge(pedge root, int key, double value)
{
	pedge new_edge = new_tree();
	new_edge->key = key;
	new_edge->value = value;
	if (NULL == new_edge)
	{
		printf("ERROR: failed allocation of memory for new element!\n");
		return -1;
	}
	if (NULL == root->key && 0.0 == root->value)
	{
		root->key = key;
		root->value = value;
		return 0;
	}
	pedge current = root;
	while (NULL == current->left && NULL == current->right)
	{
		if (current->value < value)
			current = current->left;
		else
			current = current->right;
	}
	if (current->value < value)
		current->left = new_edge;
	else
		current->right = new_edge;
	return 0;
}

/*
* Delete tree
*/
void delete_tree(pedge tree)
{
	if (NULL != tree)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		free(tree);
	}
}

/*
* Depth first search
*/
double dfs(pedge root)
{
	if (NULL != root)
	{
		dfs(root->left);
		printf("%lf ", root->value);
		dfs(root->right);
		return root->value;
	}
}