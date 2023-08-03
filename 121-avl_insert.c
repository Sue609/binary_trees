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
	return (avl_insert_recursive(tree, value, NULL));
}



/**
 * avl_insert_recursive - Recursively inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node of the current tree node.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */

avl_t *avl_insert_recursive(avl_t **tree, int value, avl_t *parent)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}
	if (value < (*tree)->n)
		return (avl_insert_recursive(&((*tree)->left), value, *tree));
	else if (value > (*tree)->n)
		return (avl_insert_recursive(&((*tree)->right), value, *tree));
	return (NULL);
}
