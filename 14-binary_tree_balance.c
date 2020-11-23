#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right, balance;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	balance = left - right;

	return (balance);
}

/**
 * binary_tree_height - height binary tree
 * @tree: root node of tree
 * Return: height of tree
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;


	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	left_height++;

	right_height = binary_tree_height(tree->right);
	right_height++;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
