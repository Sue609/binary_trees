#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
* binary_tree_node - function that creates a binary node
* @parent: Pointer to the parent node of the node to create
* @value: The value to put in the new node
*
* Return: Pointer to new node or NULL on failure.
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
