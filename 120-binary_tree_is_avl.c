#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
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

/**
 * bst_utility - verifies this is a bst
 * @tree: tree we are verifying
 * @max: largest node
 * @min: smallest node
 * Return: 1 for true, 0 for false
 */
int bst_utility(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return ((bst_utility(tree->left, min, tree->n - 1)) &&
		(bst_utility(tree->right, tree->n + 1, max)));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if successful, 0 if otherwise or NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_utility(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root node of the tree to check
 * Return: 1 if tree is valid AVL, and 0 otherwise; if tree==NULL return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && binary_tree_is_bst(tree) &&
		(binary_tree_height(tree->left) - binary_tree_height(tree->right) == 0))
		return (1);

	return (0);
}
