#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * bst_search - Search for a value in a binary search tree.
 * @tree: pointer to the root node of the BST search.
 * @value: value to search for in the tree.
 *
 * Return: node or NULL.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
