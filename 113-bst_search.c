#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	temp = (bst_t *)tree;

	while (temp)
	{
		if (temp->n == value)
			return (temp);

		if (temp->n < value)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return (NULL);
}
