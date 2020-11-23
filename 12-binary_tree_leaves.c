#include "binary_trees.h"
/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_branch, right_branch, leaves;

	if (tree == NULL)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	left_branch = binary_tree_leaves(tree->left);
	right_branch = binary_tree_leaves(tree->right);
	leaves = left_branch + right_branch;

	return (leaves);
}
