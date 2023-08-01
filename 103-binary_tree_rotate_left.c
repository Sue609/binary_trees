#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to new node.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *A;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	A = tree->right;
	tree->right = A->left;

	if (A->left != NULL)
		A->left->parent = tree;

	A->left = tree;
	A->parent = tree->parent;
	tree->parent = A;

	if (A->parent != NULL)
	{
		if (A->parent->left == tree)
			A->parent->left = A;
		else
			A->parent->right = A;
	}
	else
	{
		A->parent = NULL;
	}

	return (A);
}
