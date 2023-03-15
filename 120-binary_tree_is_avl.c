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
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root node of the tree to check
 * Return: 1 if tree is valid AVL, and 0 otherwise; if tree==NULL return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) <= 1 &&
		binary_tree_is_avl(tree->right) &&
		binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}
