#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates nodes to the left
 *
 * @tree: original binary tree
 * Return: rotated binary_tree_t*
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree)
		return (NULL);

	if (!tree->right)
		return (tree);

	node = tree->right;
	node->left = tree;
	node->parent = tree->parent;
	tree->parent = node;
	tree->right = NULL;

	return (node);
}
