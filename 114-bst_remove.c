#include "binary_trees.h"

/**
 * in_order_successor - replaces childreen of deleted nodes
 * @root: pointer to the root node of the tree
 * Return: pointer to the new root node of tree after removing desired value
 */
bst_t *in_order_successor(bst_t *root)
{
	while (root->left)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_remove - a function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: is the value to remove in the tree
 * Return: pointer to the new root node of tree after removing desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else
		if (root->n < value)
			root->right = bst_remove(root->right, value);
		else
		{
			if (root->left && root->right)
			{
				temp = in_order_successor(root->right);
				root->n = temp->n;
				root->right = bst_remove(root->right, temp->n);
			}
			else
			{
				if (!root->left && !root->right)
				{
					free(root);
					return (NULL);
				}
				temp = root;
				if (!root->left)
					root = root->right;
				else
					if (!root->right)
						root = root->left;
				if (temp->parent->left == temp)
					temp->parent->left = root;
				else
					temp->parent->right = root;
				root->parent = temp->parent;
				free(temp);
			}
		}
	return (root);
}
