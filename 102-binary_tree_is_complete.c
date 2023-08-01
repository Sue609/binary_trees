#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 or 0.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count;

	if (tree == NULL)
		return (0);

	node_count = binary_tree_size(tree);

	return (is_complete_recursive(tree, 0, node_count));
}


/**
 * is_complete_recursive - recursively checks if a binary tree is complete.
 * @tree: pointer to the current node being checked.
 * @index: index of the current node in the current level.
 * @node_count: total number of nodes in the entire tree.
 *
 * Return: 1 or 0.
 */

int is_complete_recursive(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
		is_complete_recursive(tree->right, 2 * index + 2, node_count));
}


/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree (number of nodes).
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
