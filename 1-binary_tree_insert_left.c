#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_insert_left - function that returns a node as the left-child
 * of another node.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 * Return: A pointer to created node or NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;

	if (parent->left != NULL)
	{
		parent->left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}
