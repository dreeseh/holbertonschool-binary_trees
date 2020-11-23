#include "binary_trees.h"
/**
 * bianry_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: If tree is NULL, the function must return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes, total_nodes = 0;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	if (tree->left || tree->right)
	{
		left_nodes = binary_tree_nodes(tree->left) + 1;
		right_nodes = binary_tree_nodes(tree->right) + 1;
		total_nodes = left_nodes + right_nodes - 1;
	}

	return (total_nodes);
}
