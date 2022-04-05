#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to lowest common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *j, *k;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	j = first->parent;
	k = second->parent;

	if (j == NULL || first == k || (!j->parent && k))
		return (binary_trees_ancestor(first, k));

	else if (k == NULL || j == second || (!k->parent && j))
		return (binary_trees_ancestor(j, second));

	return (binary_trees_ancestor(j, k));
}
