#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - function that performs the inorder traversal
 * @tree: The binary tree.
 * @prev_val: pointer to track previously visited node.
 *
 * Return: pointer.
 */

int is_bst_helper(const binary_tree_t *tree, int *prev_val)
{
	if (tree == NULL)
		return (1);

	if (!is_bst_helper(tree->left, prev_val))
		return (0);

	if (*prev_val >= tree->n)
		return (0);

	*prev_val = tree->n;

	return (is_bst_helper(tree->right, prev_val));
}

/**
 * binary_tree_is_bst - Check if a binary tree is a valid Binary
 * Search Tree (BST)
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_val = INT_MIN;

	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, &prev_val));
}
