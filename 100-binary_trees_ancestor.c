#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: pointer or NULL.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor = second;

	while (ancestor != NULL)
	{
		if (ancestor == first)
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	ancestor = first;

	while (ancestor != NULL)
	{
		if (ancestor == second)
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}
	return (NULL);
}
