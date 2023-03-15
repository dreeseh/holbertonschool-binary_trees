#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates nodes to the right
 *
 * @tree: original binary tree
 * Return: rotated binary_tree_t*
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *temp;

	if (!tree)
		return (NULL);

	if (!tree->left)
		return (tree);

	node = tree->left;
	node->parent = tree->parent;
	tree->left = NULL;

	if (node->right == NULL)
	{
		node->right = tree;
		tree->parent = node;
		return (node);
	}

	temp = node->right;
	node->right = tree;
	tree->parent = node;
	tree->left = temp;
	temp->parent = tree;

	return (node);
}
