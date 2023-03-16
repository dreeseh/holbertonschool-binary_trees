#include "binary_trees.h"

/**
 * avl_balance - checks the balance
 * @node: pointer to the node
 * @value: value to store in the node
 * Return: is void
 */
void avl_balance(avl_t **node, int value)
{
	int balance;

	balance = binary_tree_balance(*node);

	if (balance > 1 && value < (*node)->left->n)
	{
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value > (*node)->right->n)
	{
		*node = binary_tree_rotate_left(*node);
		return;
	}

	if (balance > 1 && value > (*node)->left->n)
	{
		(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
		return;
	}

	if (balance < -1 && value < (*node)->right->n)
	{
		(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
		return;
	}
}

/**
 * my_avl_insert - checks if node is inserted
 *
 * @tree: pointer to the root node of the tree
 * @value: value to store in the node
 * Return: pointer to the new node
 */
avl_t *my_avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}

		new_node = my_avl_insert(&((*tree)->left), value);
		if (new_node)
			avl_balance(tree, value);
		return (new_node);
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		
		new_node = my_avl_insert(&((*tree)->right), value);
		if (new_node)
			avl_balance(tree, value);
		return (new_node);
	}
	return (NULL);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_tree;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_tree = my_avl_insert(tree, value);

	return (new_tree);
}