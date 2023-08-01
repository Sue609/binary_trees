#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree
 * using level_order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node's value.
 *
 * Return: null
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[1000];
	int front = 0;
	int rear = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current_node = queue[front++];

		func(current_node->n);

		if (current_node->left != NULL)
			queue[rear++] = current_node->left;

		if (current_node->right != NULL)
			queue[rear++] = current_node->right;
	}
}
