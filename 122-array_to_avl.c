#include "binary_trees.h"

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