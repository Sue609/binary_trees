#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the right-child
 * of another node.
 * @parent: Pointerto the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (!parent)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (!new_node)
		return (NULL);

	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
