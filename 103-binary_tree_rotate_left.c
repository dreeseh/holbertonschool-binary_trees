#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates nodes to the left
 *
 * @tree: original binary tree
 * Return: rotated binary_tree_t*
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *ptree;

	ptree = tree->right;
	tree->right = ptree->left;
	ptree->left = tree;

	return (ptree);
}
