#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: he number of element in the array
 * Return: new avl_t*
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t counter;

	tree = NULL;

	for (counter = 0 ; counter < size ; counter++)
	{
		avl_insert(&tree, array[counter]);
	}

	if (counter == size)
		return (tree);

	return (NULL);
}
