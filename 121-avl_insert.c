#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	return (avl_insert_recursive(tree, NULL, value));
}



/**
 * avl_insert_recursive - Recursively inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node of the current tree node.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, int value)
{
	int balance;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&((*tree)->left), *tree, value);
	}
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert_recursive(&((*tree)->right), *tree, value);
	else
		return (NULL);

	balance = binary_tree_balance(*tree);
	(*tree)->balance = balance;

	if (balance > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));

	if (balance < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));

	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}

	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}

	return (*tree);
}
