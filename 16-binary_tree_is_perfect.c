#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_full(tree) && binary_tree_balance(tree) == 0)
		return (1);
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_branch, right_branch, balance;

	if (tree == NULL)
		return (0);

	left_branch = binary_tree_height(tree->left);
	right_branch = binary_tree_height(tree->right);
	balance = left_branch - right_branch;

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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	left_height++;

	right_height = binary_tree_height(tree->right);
	right_height++;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_branch, right_branch;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left || tree->right)
	{
		left_branch = binary_tree_is_full(tree->left);
		right_branch = binary_tree_is_full(tree->right);

		if (left_branch && right_branch)
			return (0);
		else
			return (1);
	}

	return (0);
}
