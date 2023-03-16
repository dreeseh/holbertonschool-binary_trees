#include "binary_trees.h"

/**
 * initialize_tree - creates an AVL tree with recursion
 *
 * @node: pointer to the node
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * @leftRight: 1 = adding on the left, 2 = adding on the right
 * Return: is void
 */
void initialize_tree(avl_t **node, int *array, size_t size, int leftRight)
{
	size_t middle;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (leftRight == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		initialize_tree(&((*node)->left), array, middle, 1);
		initialize_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		initialize_tree(&((*node)->right), array, middle, 1);
		initialize_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the avl_t root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t middle;
	int left, right;

	left = 1;
	right = 2;

	root = NULL;

	if (size == 0)
		return (NULL);

	middle = (size / 2);

	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);

	initialize_tree(&root, array, middle, left);
	initialize_tree(&root, array + middle + 1, (size - 1 - middle), right);

	return (root);
}
