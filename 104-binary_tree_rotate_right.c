#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *A;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	A = tree->left;
	tree->left = A->right;
	if (A->right != NULL)
		A->right->parent = tree;

	A->right = tree;
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
		A->parent = NULL;

	return (A);
}
