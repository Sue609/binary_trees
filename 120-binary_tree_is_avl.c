#include "binary_trees.h"
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_height - Calculate the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + MAX(left_height, right_height));
}


/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);
	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
